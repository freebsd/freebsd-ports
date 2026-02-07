/*
 * Copyright (c) 2012-2024 Belledonne Communications SARL.
 *
 * This file is part of belle-sip.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "belle-sip/headers.h"
#include "belle-sip/parameters.h"
#include "sip/sip_parser.hh"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "belle_sip_internal.h"
#include "listeningpoint_internal.h"

/************************
 * header
 ***********************/

GET_SET_STRING(belle_sip_header, name);
#define PROTO_SIP 0x1
#define PROTO_HTTP 0x1 << 1
typedef belle_sip_header_t *(*header_parse_func)(const char *);

struct header_name_func_pair {
	int protocol;
	const char *name;
	header_parse_func func;
};

static struct header_name_func_pair header_table[] = {
    {PROTO_SIP, "m", (header_parse_func)belle_sip_header_contact_parse},
    {PROTO_SIP, BELLE_SIP_CONTACT, (header_parse_func)belle_sip_header_contact_parse},
    {PROTO_SIP, "f", (header_parse_func)belle_sip_header_from_parse},
    {PROTO_SIP, BELLE_SIP_FROM, (header_parse_func)belle_sip_header_from_parse},
    {PROTO_SIP, "t", (header_parse_func)belle_sip_header_to_parse},
    {PROTO_SIP, BELLE_SIP_TO, (header_parse_func)belle_sip_header_to_parse},
    {PROTO_SIP, "d", (header_parse_func)belle_sip_header_diversion_parse},
    {PROTO_SIP, BELLE_SIP_DIVERSION, (header_parse_func)belle_sip_header_diversion_parse},
    {PROTO_SIP, "i", (header_parse_func)belle_sip_header_call_id_parse},
    {PROTO_SIP, BELLE_SIP_CALL_ID, (header_parse_func)belle_sip_header_call_id_parse},
    {PROTO_SIP, "r", (header_parse_func)belle_sip_header_retry_after_parse},
    {PROTO_SIP, BELLE_SIP_RETRY_AFTER, (header_parse_func)belle_sip_header_retry_after_parse},
    {PROTO_SIP, "l", (header_parse_func)belle_sip_header_content_length_parse},
    {PROTO_SIP | PROTO_HTTP, BELLE_SIP_CONTENT_LENGTH, (header_parse_func)belle_sip_header_content_length_parse},
    {PROTO_SIP, "c", (header_parse_func)belle_sip_header_content_type_parse},
    {PROTO_SIP | PROTO_HTTP, BELLE_SIP_CONTENT_TYPE, (header_parse_func)belle_sip_header_content_type_parse},
    {PROTO_SIP, BELLE_SIP_CSEQ, (header_parse_func)belle_sip_header_cseq_parse},
    {PROTO_SIP, BELLE_SIP_ROUTE, (header_parse_func)belle_sip_header_route_parse},
    {PROTO_SIP, BELLE_SIP_RECORD_ROUTE, (header_parse_func)belle_sip_header_record_route_parse},
    {PROTO_SIP, "v", (header_parse_func)belle_sip_header_via_parse},
    {PROTO_SIP, BELLE_SIP_VIA, (header_parse_func)belle_sip_header_via_parse},
    {PROTO_SIP, "x", (header_parse_func)belle_sip_header_session_expires_parse},
    {PROTO_SIP, BELLE_SIP_SESSION_EXPIRES, (header_parse_func)belle_sip_header_session_expires_parse},
    {PROTO_SIP, BELLE_SIP_AUTHORIZATION, (header_parse_func)belle_sip_header_authorization_parse},
    {PROTO_SIP, BELLE_SIP_PROXY_AUTHORIZATION, (header_parse_func)belle_sip_header_proxy_authorization_parse},
    {PROTO_SIP | PROTO_HTTP, BELLE_SIP_WWW_AUTHENTICATE, (header_parse_func)belle_sip_header_www_authenticate_parse},
    {PROTO_SIP | PROTO_HTTP, BELLE_SIP_PROXY_AUTHENTICATE,
     (header_parse_func)belle_sip_header_proxy_authenticate_parse},
    {PROTO_SIP, BELLE_SIP_MAX_FORWARDS, (header_parse_func)belle_sip_header_max_forwards_parse},
    {PROTO_SIP | PROTO_HTTP, BELLE_SIP_USER_AGENT, (header_parse_func)belle_sip_header_user_agent_parse},
    {PROTO_SIP, BELLE_SIP_EXPIRES, (header_parse_func)belle_sip_header_expires_parse},
    {PROTO_SIP | PROTO_HTTP, BELLE_SIP_ALLOW, (header_parse_func)belle_sip_header_allow_parse},
    {PROTO_SIP, BELLE_SIP_SUBSCRIPTION_STATE, (header_parse_func)belle_sip_header_subscription_state_parse},
    {PROTO_SIP, BELLE_SIP_SERVICE_ROUTE, (header_parse_func)belle_sip_header_service_route_parse},
    {PROTO_SIP, BELLE_SIP_REFER_TO, (header_parse_func)belle_sip_header_refer_to_parse},
    {PROTO_SIP, BELLE_SIP_REFERRED_BY, (header_parse_func)belle_sip_header_referred_by_parse},
    {PROTO_SIP, BELLE_SIP_REPLACES, (header_parse_func)belle_sip_header_replaces_parse},
    {PROTO_SIP | PROTO_HTTP, BELLE_SIP_DATE, (header_parse_func)belle_sip_header_date_parse},
    {PROTO_SIP, BELLE_SIP_P_PREFERRED_IDENTITY, (header_parse_func)belle_sip_header_p_preferred_identity_parse},
    {PROTO_SIP, BELLE_SIP_PRIVACY, (header_parse_func)belle_sip_header_privacy_parse},
    {PROTO_SIP, BELLE_SIP_EVENT, (header_parse_func)belle_sip_header_event_parse},
    {PROTO_SIP, "o", (header_parse_func)belle_sip_header_event_parse},
    {PROTO_SIP, BELLE_SIP_SUPPORTED, (header_parse_func)belle_sip_header_supported_parse},
    {PROTO_SIP, "k", (header_parse_func)belle_sip_header_supported_parse},
    {PROTO_SIP, BELLE_SIP_REQUIRE, (header_parse_func)belle_sip_header_require_parse},
    {PROTO_SIP, BELLE_SIP_CONTENT_DISPOSITION, (header_parse_func)belle_sip_header_content_disposition_parse},
    {PROTO_SIP | PROTO_HTTP, BELLE_SIP_ACCEPT, (header_parse_func)belle_sip_header_accept_parse},
    {PROTO_SIP, BELLE_SIP_REASON, (header_parse_func)belle_sip_header_reason_parse},
    {PROTO_SIP, BELLE_SIP_AUTHENTICATION_INFO, (header_parse_func)belle_sip_header_authentication_info_parse}};

static belle_sip_header_t *belle_header_create(const char *name, const char *value, int protocol) {
	size_t i;
	belle_sip_header_t *ret;
	size_t elements = sizeof(header_table) / sizeof(struct header_name_func_pair);

	if (!name || name[0] == '\0') {
		belle_sip_error("Cannot create header without name");
		return NULL;
	}

	for (i = 0; i < elements; i++) {
		if ((header_table[i].protocol & protocol) && strcasecmp(header_table[i].name, name) == 0) {
			char *raw = belle_sip_strdup_printf("%s:%s", name, value);
			ret = header_table[i].func(raw);
			belle_sip_free(raw);
			return ret;
		}
	}
	/*not a known header*/
	return BELLE_SIP_HEADER(belle_sip_header_extension_create(name, value));
}

belle_sip_header_t *belle_sip_header_create(const char *name, const char *value) {
	return belle_header_create(name, value, PROTO_SIP);
}

belle_sip_header_t *belle_http_header_create(const char *name, const char *value) {
	return belle_header_create(name, value, PROTO_HTTP);
}

void belle_sip_header_init(belle_sip_header_t *header) {
}

static void belle_sip_header_clone(belle_sip_header_t *header, const belle_sip_header_t *orig) {
	CLONE_STRING(belle_sip_header, name, header, orig)
	if (belle_sip_header_get_next(orig)) {
		belle_sip_header_set_next(
		    header, BELLE_SIP_HEADER(belle_sip_object_clone(BELLE_SIP_OBJECT(belle_sip_header_get_next(orig)))));
	}
}

static void belle_sip_header_destroy(belle_sip_header_t *header) {
	if (header->name) belle_sip_free(header->name);
	if (header->unparsed_value) belle_sip_free(header->unparsed_value);
	if (header->next) belle_sip_object_unref(BELLE_SIP_OBJECT(header->next));
}

void belle_sip_header_set_next(belle_sip_header_t *header, belle_sip_header_t *next) {
	if (next) belle_sip_object_ref(next);
	if (header->next) belle_sip_object_unref(header->next);
	header->next = next;
}

void belle_sip_header_append(belle_sip_header_t *header, belle_sip_header_t *next) {
	auto current = header;
	while (current->next)
		current = current->next;
	belle_sip_header_set_next(current, next);
}

belle_sip_header_t *belle_sip_header_get_next(const belle_sip_header_t *header) {
	return header->next;
}

const char *belle_sip_header_get_unparsed_value(belle_sip_header_t *obj) {
	if (BELLE_SIP_OBJECT_IS_INSTANCE_OF(obj, belle_sip_header_extension_t)) {
		return belle_sip_header_extension_get_value(BELLE_SIP_HEADER_EXTENSION(obj));
	} else {
		char *tmp = belle_sip_object_to_string(obj);
		char *ret;
		if (obj->unparsed_value) {
			belle_sip_free(obj->unparsed_value);
			obj->unparsed_value = NULL;
		}
		obj->unparsed_value = tmp;
		ret = tmp;
		ret += strlen(obj->name) + 1; /* name + semicolon*/
		for (; *ret == ' '; ret++) {
		}; /*skip spaces*/
		return ret;
	}
}

belle_sip_error_code
belle_sip_header_marshal(belle_sip_header_t *header, char *buff, size_t buff_size, size_t *offset) {
	if (header->name) {
		return belle_sip_snprintf(buff, buff_size, offset, "%s: ", header->name);
	} else {
		belle_sip_warning("no header name found");
		return BELLE_SIP_OK;
	}
}

BELLE_SIP_DECLARE_NO_IMPLEMENTED_INTERFACES(belle_sip_header_t);

BELLE_SIP_INSTANCIATE_VPTR(belle_sip_header_t,
                           belle_sip_object_t,
                           belle_sip_header_destroy,
                           belle_sip_header_clone,
                           belle_sip_header_marshal,
                           TRUE);

BELLE_SIP_PARSE_WITH_CONTEXT_AND_RULE(header, message_header);

belle_sip_header_t *belle_sip_header_new_dummy(void) {
	return belle_sip_header_create("dummy", "dummy");
}

void belle_sip_header_set_unparsed_value(belle_sip_header_t *obj, const char *value) {
	if (obj->unparsed_value) belle_sip_free(obj->unparsed_value);
	if (value) {
		obj->unparsed_value = belle_sip_strdup(value);
	} else {
		obj->unparsed_value = nullptr;
	}
}

/************************
 * header_address
 ***********************/
struct _belle_sip_header_address {
	belle_sip_parameters_t base;
	char *displayname;
	belle_sip_uri_t *uri;
	belle_generic_uri_t *absolute_uri;
	unsigned char automatic;
};

static void belle_sip_header_address_init(belle_sip_header_address_t *object) {
	belle_sip_parameters_init((belle_sip_parameters_t *)object); /*super*/
}

static void belle_sip_header_address_destroy(belle_sip_header_address_t *address) {
	if (address->displayname) belle_sip_free(address->displayname);
	if (address->uri) belle_sip_object_unref(address->uri);
	if (address->absolute_uri) belle_sip_object_unref(address->absolute_uri);
}

static void _belle_sip_header_address_clone(belle_sip_header_address_t *addr, const belle_sip_header_address_t *orig) {
	CLONE_STRING(belle_sip_header_address, displayname, addr, orig)
	if (belle_sip_header_address_get_uri(orig)) {
		belle_sip_header_address_set_uri(
		    addr, BELLE_SIP_URI(belle_sip_object_clone(BELLE_SIP_OBJECT(belle_sip_header_address_get_uri(orig)))));
	}
	if (belle_sip_header_address_get_absolute_uri(orig)) {
		belle_sip_header_address_set_absolute_uri(addr, BELLE_GENERIC_URI(belle_sip_object_clone(BELLE_SIP_OBJECT(
		                                                    belle_sip_header_address_get_absolute_uri(orig)))));
	}
	if (belle_sip_header_address_get_automatic(orig)) {
		belle_sip_header_address_set_automatic(addr, belle_sip_header_address_get_automatic(orig));
	}
	belle_sip_parameters_copy_parameters_from(&addr->base, &orig->base);
}
belle_sip_header_address_t *belle_sip_header_address_clone(const belle_sip_header_address_t *orig) {
	belle_sip_header_address_t *new_address = belle_sip_header_address_new();
	_belle_sip_header_address_clone(new_address, orig);
	return new_address;
}

static belle_sip_error_code _belle_sip_header_address_marshal(
    belle_sip_header_address_t *header, char *buff, size_t buff_size, size_t *offset, int force_angle_quote) {
	belle_sip_error_code error = BELLE_SIP_OK;
	bool has_display_name = header->displayname != nullptr;

	if (belle_sip_stack_name_addr_forced) force_angle_quote = TRUE;

	/*1 display name*/
	if (has_display_name) {
		char *escaped_display_name = belle_sip_display_name_to_backslashed_escaped_string(header->displayname);
		error = belle_sip_snprintf(buff, buff_size, offset, "\"%s\" ", escaped_display_name);
		belle_sip_free(escaped_display_name);
		if (error != BELLE_SIP_OK) return error;
	}
	if (header->uri || header->absolute_uri) {
		bool has_parameters = belle_sip_parameters_get_parameter_names(&header->base);
		bool is_sip_uri_with_headers_or_parameters =
		    (header->uri != nullptr) &&
		    (belle_sip_parameters_get_parameter_names((belle_sip_parameters_t *)header->uri) ||
		     belle_sip_uri_get_header_names(header->uri));
		bool angle_quote_required =
		    force_angle_quote || has_display_name || is_sip_uri_with_headers_or_parameters || has_parameters;
		/*cases where < is required*/
		if (angle_quote_required) {
			error = belle_sip_snprintf(buff, buff_size, offset, "%s", "<");
			if (error != BELLE_SIP_OK) return error;
		}
		if (header->uri) {
			error = belle_sip_uri_marshal(header->uri, buff, buff_size, offset);
		} else {
			error = belle_generic_uri_marshal(header->absolute_uri, buff, buff_size, offset);
		}
		if (error != BELLE_SIP_OK) return error;
		if (angle_quote_required) {
			error = belle_sip_snprintf(buff, buff_size, offset, "%s", ">");
			if (error != BELLE_SIP_OK) return error;
		}
	}
	error = belle_sip_parameters_marshal(&header->base, buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	return error;
}

belle_sip_error_code
belle_sip_header_address_marshal(belle_sip_header_address_t *header, char *buff, size_t buff_size, size_t *offset) {
	return _belle_sip_header_address_marshal(header, buff, buff_size, offset, FALSE);
}
#define belle_sip_header_address_clone                                                                                 \
	_belle_sip_header_address_clone /*because public clone function is not the one to be used internally*/
BELLE_SIP_NEW_HEADER(header_address, parameters, "header_address");
BELLE_SIP_ADDRESS_PARSE(header_address);
GET_SET_STRING(belle_sip_header_address, displayname);
SET_QUOTED_STRING(belle_sip_header_address, displayname);

void belle_sip_header_address_set_quoted_displayname_with_slashes(belle_sip_header_address_t *address,
                                                                  const char *value) {
	char *unescaped_value = belle_sip_string_to_backslash_less_unescaped_string(value);
	belle_sip_header_address_set_quoted_displayname(address, unescaped_value);
	belle_sip_free(unescaped_value);
}

belle_sip_uri_t *belle_sip_header_address_get_uri(const belle_sip_header_address_t *address) {
	return address->uri;
}

void belle_sip_header_address_set_uri(belle_sip_header_address_t *address, belle_sip_uri_t *uri) {
	if (uri) belle_sip_object_ref(uri);
	if (address->uri) {
		belle_sip_object_unref(address->uri);
	}
	address->uri = uri;
	if (address->absolute_uri && uri) {
		belle_sip_warning("sip absolute uri [%p] already set for header_address [%p], cleaning it",
		                  address->absolute_uri, address);
		belle_sip_header_address_set_absolute_uri(address, NULL);
	}
}

void belle_sip_header_address_set_automatic(belle_sip_header_address_t *address, int automatic) {
	address->automatic = (unsigned char)automatic;
}

int belle_sip_header_address_get_automatic(const belle_sip_header_address_t *address) {
	return address->automatic;
}

belle_generic_uri_t *belle_sip_header_address_get_absolute_uri(const belle_sip_header_address_t *address) {
	return address->absolute_uri;
}

void belle_sip_header_address_set_absolute_uri(belle_sip_header_address_t *address, belle_generic_uri_t *absolute_uri) {
	belle_sip_object_ref(absolute_uri);
	if (address->absolute_uri) {
		belle_sip_object_unref(address->absolute_uri);
	}
	address->absolute_uri = absolute_uri;
	if (address->uri && absolute_uri) {
		belle_sip_warning("sip uri [%p] already set for header_address [%p], cleaning it", address->uri, address);
		belle_sip_header_address_set_uri(address, NULL);
	}
}

void belle_sip_header_address_set_generic_uri(belle_sip_header_address_t *obj, belle_generic_uri_t *generic_uri) {
	const char *scheme = belle_generic_uri_get_scheme(generic_uri);
	if (scheme && (strcasecmp(scheme, "sip") != 0) && (strcasecmp(scheme, "sips") != 0)) {
		belle_sip_header_address_set_absolute_uri(obj, generic_uri);
	} else {
		belle_sip_error("Cannot parse a sip/sips uri as a generic uri");
		belle_sip_object_unref(generic_uri);
	}
}

belle_sip_header_address_t *belle_sip_header_address_create(const char *display, belle_sip_uri_t *uri) {
	belle_sip_header_address_t *address = belle_sip_header_address_new();
	belle_sip_header_address_set_displayname(address, display);
	belle_sip_header_address_set_uri(address, uri);
	return address;
}

belle_sip_header_address_t *belle_sip_header_address_create2(const char *display, belle_generic_uri_t *uri) {
	belle_sip_header_address_t *address = belle_sip_header_address_new();
	belle_sip_header_address_set_displayname(address, display);
	belle_sip_header_address_set_absolute_uri(address, uri);
	return address;
}

int belle_sip_header_address_equals(const belle_sip_header_address_t *addr_a,
                                    const belle_sip_header_address_t *addr_b) {
	// Addresses are not identical if either is NULL
	if (!addr_a | !addr_b) return -1;
	belle_sip_uri_t *uri_a = belle_sip_header_address_get_uri(addr_a);
	belle_sip_uri_t *uri_b = belle_sip_header_address_get_uri(addr_b);
	// URIs are not identical if either is NULL
	if (!uri_a | !uri_b) return -1;
	const bool_t uri_equal = (belle_sip_uri_equals(uri_a, uri_b) != 0);

	const char *displayname_a = belle_sip_header_address_get_displayname(addr_a);
	const char *displayname_b = belle_sip_header_address_get_displayname(addr_b);
	bool_t displayname_equal = FALSE;
	if (displayname_a && displayname_b) {
		displayname_equal = (strcmp(displayname_a, displayname_b) == 0);
	} else if (!displayname_a & !displayname_b) {
		displayname_equal = TRUE;
	}
	return ((uri_equal && displayname_equal) ? 0 : -1);
}

/*fast header address implementation*/

belle_sip_header_address_t *belle_sip_header_address_fast_parse(const char *address) {
	return belle_sip_header_address_parse(address);
}

/*
 same as belle_sip_header_address_fast_parse but with no error log.
 */
belle_sip_header_address_t *belle_sip_header_address_try_fast_parse(const char *address) {
	return belle_sip_try_header_address_parse(address);
}

belle_sip_header_address_t *belle_sip_header_address_try_parse(const char *address) {
	return belle_sip_try_header_address_parse(address);
}

/******************************
 * Allow header inherits from header
 ******************************/
struct _belle_sip_header_allow {
	belle_sip_header_t header;
	const char *method;
};
static void belle_sip_header_allow_clone(belle_sip_header_allow_t *allow, const belle_sip_header_allow_t *orig) {
	CLONE_STRING(belle_sip_header_allow, method, allow, orig)
}
static void belle_sip_header_allow_destroy(belle_sip_header_allow_t *allow) {
	if (allow->method) belle_sip_free((void *)allow->method);
}

belle_sip_error_code
belle_sip_header_allow_marshal(belle_sip_header_allow_t *allow, char *buff, size_t buff_size, size_t *offset) {
	belle_sip_error_code error = belle_sip_header_marshal(BELLE_SIP_HEADER(allow), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_snprintf(buff, buff_size, offset, "%s", allow->method);
	if (error != BELLE_SIP_OK) return error;
	return error;
}

BELLE_SIP_NEW_HEADER(header_allow, header, "Allow");
BELLE_SIP_PARSE_FULL(header_allow);
belle_sip_header_allow_t *belle_sip_header_allow_create(const char *methods) {
	belle_sip_header_allow_t *allow = belle_sip_header_allow_new();
	belle_sip_header_allow_set_method(allow, methods);
	return allow;
}
GET_SET_STRING(belle_sip_header_allow, method);

/************************
 * Contact header object inherits from header_address
 ***********************/
struct _belle_sip_header_contact {
	belle_sip_header_address_t address;
	unsigned char wildcard;
	unsigned char unknown;
	unsigned char pad[2];
};

void belle_sip_header_contact_destroy(belle_sip_header_contact_t *contact) {
}

void belle_sip_header_contact_clone(belle_sip_header_contact_t *contact, const belle_sip_header_contact_t *orig) {
	contact->wildcard = orig->wildcard;
}

belle_sip_error_code
belle_sip_header_contact_marshal(belle_sip_header_contact_t *contact, char *buff, size_t buff_size, size_t *offset) {
	belle_sip_error_code error = belle_sip_header_marshal(BELLE_SIP_HEADER(contact), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	if (contact->wildcard) {
		error = belle_sip_snprintf(buff, buff_size, offset, "%s", "*");
	} else {
		error = belle_sip_header_address_marshal(&contact->address, buff, buff_size, offset);
	}
	return error;
}

BELLE_SIP_NEW_HEADER(header_contact, header_address, BELLE_SIP_CONTACT);
BELLE_SIP_PARSE_WITH_CONTEXT(header_contact);
belle_sip_header_contact_t *belle_sip_header_contact_create(const belle_sip_header_address_t *contact) {
	belle_sip_header_contact_t *header = belle_sip_header_contact_new();
	_belle_sip_object_copy(BELLE_SIP_OBJECT(header), BELLE_SIP_OBJECT(contact));
	belle_sip_header_set_next(BELLE_SIP_HEADER(header), NULL);              /*make sure only one header is kept*/
	belle_sip_header_set_name(BELLE_SIP_HEADER(header), BELLE_SIP_CONTACT); /*restaure header name*/
	return header;
}
GET_SET_INT_PARAM_PRIVATE(belle_sip_header_contact, expires, int, _);
GET_SET_INT_PARAM_PRIVATE(belle_sip_header_contact, q, float, _);
GET_SET_BOOL(belle_sip_header_contact, wildcard, is);

void belle_sip_header_contact_set_string_wildcard(belle_sip_header_contact_t *contact, const char *wildcard) {
	if (strcmp("*", wildcard) == 0) {
		belle_sip_header_contact_set_wildcard(contact, 1);
	}
}

int belle_sip_header_contact_set_expires(belle_sip_header_contact_t *contact, int expires) {
	if (expires < 0) {
		belle_sip_error("bad expires value [%i] for contact", expires);
		return -1;
	}
	_belle_sip_header_contact_set_expires(contact, expires);
	return 0;
}
int belle_sip_header_contact_set_qvalue(belle_sip_header_contact_t *contact, float qValue) {
	if (qValue != -1 && qValue < 0 && qValue > 1) {
		belle_sip_error("bad q value [%f] for contact", qValue);
		return -1;
	}
	_belle_sip_header_contact_set_q(contact, qValue);
	return 0;
}
float belle_sip_header_contact_get_qvalue(const belle_sip_header_contact_t *contact) {
	return belle_sip_header_contact_get_q(contact);
}

unsigned int belle_sip_header_contact_equals(const belle_sip_header_contact_t *a, const belle_sip_header_contact_t *b) {
	if (!a | !b) return 0;
	return belle_sip_uri_equals(belle_sip_header_address_get_uri(BELLE_SIP_HEADER_ADDRESS(a)),
	                            belle_sip_header_address_get_uri(BELLE_SIP_HEADER_ADDRESS(b)));
}
unsigned int belle_sip_header_contact_not_equals(const belle_sip_header_contact_t *a,
                                                 const belle_sip_header_contact_t *b) {
	return !belle_sip_header_contact_equals(a, b);
}

unsigned int belle_sip_header_contact_equals_with_uri_omitting(const belle_sip_header_contact_t *a,
                                                               const belle_sip_header_contact_t *b) {
	if (!a | !b) return 0;
	return belle_sip_uri_equals_with_uri_omitting(belle_sip_header_address_get_uri(BELLE_SIP_HEADER_ADDRESS(a)),
	                                              belle_sip_header_address_get_uri(BELLE_SIP_HEADER_ADDRESS(b)));
}
unsigned int belle_sip_header_contact_not_equals_with_uri_omitting(const belle_sip_header_contact_t *a,
                                                                   const belle_sip_header_contact_t *b) {
	return !belle_sip_header_contact_equals_with_uri_omitting(a, b);
}

void belle_sip_header_contact_set_automatic(belle_sip_header_contact_t *a, int enabled) {
	belle_sip_header_address_set_automatic((belle_sip_header_address_t *)a, enabled);
}

int belle_sip_header_contact_get_automatic(const belle_sip_header_contact_t *a) {
	return belle_sip_header_address_get_automatic((belle_sip_header_address_t *)a);
}

void belle_sip_header_contact_set_unknown(belle_sip_header_contact_t *a, int value) {
	a->unknown = value;
}

int belle_sip_header_contact_is_unknown(const belle_sip_header_contact_t *a) {
	return a->unknown;
}

/**************************
 * From header object inherits from header_address
 ***************************/
#define BELLE_SIP_FROM_LIKE_MARSHAL(header, force_angle_quote)                                                         \
	belle_sip_error_code error = belle_sip_header_marshal(BELLE_SIP_HEADER(header), buff, buff_size, offset);          \
	if (error != BELLE_SIP_OK) return error;                                                                           \
	error = _belle_sip_header_address_marshal(&header->address, buff, buff_size, offset, force_angle_quote);           \
	if (error != BELLE_SIP_OK) return error;                                                                           \
	return error;

struct _belle_sip_header_from {
	belle_sip_header_address_t address;
};

static void belle_sip_header_from_destroy(belle_sip_header_from_t *from) {
}

static void belle_sip_header_from_clone(belle_sip_header_from_t *from, const belle_sip_header_from_t *cloned) {
}

belle_sip_error_code
belle_sip_header_from_marshal(belle_sip_header_from_t *from, char *buff, size_t buff_size, size_t *offset) {
	BELLE_SIP_FROM_LIKE_MARSHAL(from, FALSE);
}

belle_sip_header_from_t *belle_sip_header_from_create2(const char *uri, const char *tag) {
	belle_sip_header_address_t *address = belle_sip_header_address_parse(uri);
	if (address) {
		belle_sip_header_from_t *from = belle_sip_header_from_create(address, tag);
		belle_sip_object_unref(address);
		return from;
	} else return NULL;
}
belle_sip_header_from_t *belle_sip_header_from_create(const belle_sip_header_address_t *address, const char *tag) {
	belle_sip_header_from_t *header = belle_sip_header_from_new();
	belle_sip_uri_t *uri;
	_belle_sip_object_copy((belle_sip_object_t *)header, (belle_sip_object_t *)address);
	/*clear unwanted uri components*/
	if ((uri = belle_sip_header_address_get_uri(BELLE_SIP_HEADER_ADDRESS(header)))) {
		belle_sip_parameters_t *params = BELLE_SIP_PARAMETERS(uri);
		belle_sip_parameters_remove_parameter(params, "lr");
		belle_sip_parameters_remove_parameter(params, "ttl");
		belle_sip_parameters_remove_parameter(params, "method");
		belle_sip_parameters_remove_parameter(params, "maddr");
		belle_sip_parameters_remove_parameter(params, "transport");
		belle_sip_uri_set_port(uri, 0);
		belle_sip_uri_headers_clean(uri);
	}
	belle_sip_header_set_next(BELLE_SIP_HEADER(header), NULL);           /*make sure only one header is kept*/
	belle_sip_header_set_name(BELLE_SIP_HEADER(header), BELLE_SIP_FROM); /*restore header name*/
	if (tag) belle_sip_header_from_set_tag(header, tag);
	return header;
}
BELLE_SIP_NEW_HEADER(header_from, header_address, BELLE_SIP_FROM);
BELLE_SIP_PARSE_HEADER_WITH_URI_CHECK(header_from);
GET_SET_STRING_PARAM2(belle_sip_header_from, tag, raw_tag);

void belle_sip_header_from_set_random_tag(belle_sip_header_from_t *obj) {
	char tmp[BELLE_SIP_TAG_LENGTH];
	belle_sip_header_from_set_raw_tag(obj, belle_sip_random_token(tmp, sizeof(tmp)));
}

void belle_sip_header_from_set_tag(belle_sip_header_from_t *obj, const char *tag) {
	if (tag == BELLE_SIP_RANDOM_TAG) belle_sip_header_from_set_random_tag(obj);
	else belle_sip_header_from_set_raw_tag(obj, tag);
}

const char *belle_sip_header_from_get_tag(const belle_sip_header_from_t *obj) {
	return belle_sip_header_from_get_raw_tag(obj);
}

/**************************
 * To header object inherits from header_address
 ***************************/
struct _belle_sip_header_to {
	belle_sip_header_address_t address;
};

static void belle_sip_header_to_destroy(belle_sip_header_to_t *to) {
}

void belle_sip_header_to_clone(belle_sip_header_to_t *contact, const belle_sip_header_to_t *orig) {
}

belle_sip_error_code belle_sip_header_to_marshal(belle_sip_header_to_t *to,
                                                 char *buff,
                                                 size_t buff_size,
                                                 size_t *offset){BELLE_SIP_FROM_LIKE_MARSHAL(to, FALSE)}

BELLE_SIP_NEW_HEADER(header_to, header_address, BELLE_SIP_TO);
BELLE_SIP_PARSE_HEADER_WITH_URI_CHECK(header_to);
GET_SET_STRING_PARAM2(belle_sip_header_to, tag, raw_tag);

belle_sip_header_to_t *belle_sip_header_to_create2(const char *uri, const char *tag) {
	belle_sip_header_address_t *address = belle_sip_header_address_parse(uri);
	if (address) {
		belle_sip_header_to_t *to = belle_sip_header_to_create(address, tag);
		belle_sip_object_unref(address);
		return to;
	} else return NULL;
}
belle_sip_header_to_t *belle_sip_header_to_create(const belle_sip_header_address_t *address, const char *tag) {
	belle_sip_header_to_t *header = belle_sip_header_to_new();
	belle_sip_uri_t *uri;
	_belle_sip_object_copy((belle_sip_object_t *)header, (belle_sip_object_t *)address);
	/*clear unwanted uri components*/
	if ((uri = belle_sip_header_address_get_uri(BELLE_SIP_HEADER_ADDRESS(header)))) {
		belle_sip_parameters_t *params = BELLE_SIP_PARAMETERS(uri);
		belle_sip_parameters_remove_parameter(params, "lr");
		belle_sip_parameters_remove_parameter(params, "ttl");
		belle_sip_parameters_remove_parameter(params, "method");
		belle_sip_parameters_remove_parameter(params, "maddr");
		belle_sip_parameters_remove_parameter(params, "transport");
		belle_sip_uri_set_port(uri, 0);
		belle_sip_uri_headers_clean(uri);
	}
	belle_sip_header_set_next(BELLE_SIP_HEADER(header), NULL);         /*make sure only one header is kept*/
	belle_sip_header_set_name(BELLE_SIP_HEADER(header), BELLE_SIP_TO); /*restaure header name*/
	if (tag) belle_sip_header_to_set_tag(header, tag);
	return header;
}
void belle_sip_header_to_set_random_tag(belle_sip_header_to_t *obj) {
	char tmp[8];
	/*not less than 32bit */
	belle_sip_header_to_set_tag(obj, belle_sip_random_token(tmp, sizeof(tmp)));
}

void belle_sip_header_to_set_tag(belle_sip_header_to_t *obj, const char *tag) {
	if (tag == BELLE_SIP_RANDOM_TAG) belle_sip_header_to_set_random_tag(obj);
	else belle_sip_header_to_set_raw_tag(obj, tag);
}

const char *belle_sip_header_to_get_tag(const belle_sip_header_to_t *obj) {
	return belle_sip_header_to_get_raw_tag(obj);
}

/**************************
 * Diversion header object inherits from header_address
 ***************************/
struct _belle_sip_header_diversion {
	belle_sip_header_address_t address;
};

static void belle_sip_header_diversion_destroy(belle_sip_header_diversion_t *diversion) {
}

void belle_sip_header_diversion_clone(belle_sip_header_diversion_t *contact, const belle_sip_header_diversion_t *orig) {
}

belle_sip_error_code belle_sip_header_diversion_marshal(belle_sip_header_diversion_t *diversion,
                                                        char *buff,
                                                        size_t buff_size,
                                                        size_t *offset){BELLE_SIP_FROM_LIKE_MARSHAL(diversion, FALSE)}

BELLE_SIP_NEW_HEADER(header_diversion, header_address, BELLE_SIP_DIVERSION) BELLE_SIP_PARSE_FULL(header_diversion);
GET_SET_STRING_PARAM2(belle_sip_header_diversion, tag, raw_tag);

belle_sip_header_diversion_t *belle_sip_header_diversion_create2(const char *uri, const char *tag) {
	belle_sip_header_address_t *address = belle_sip_header_address_parse(uri);
	if (address) {
		belle_sip_header_diversion_t *diversion = belle_sip_header_diversion_create(address, tag);
		belle_sip_object_unref(address);
		return diversion;
	} else return NULL;
}
belle_sip_header_diversion_t *belle_sip_header_diversion_create(const belle_sip_header_address_t *address,
                                                                const char *tag) {
	belle_sip_header_diversion_t *header = belle_sip_header_diversion_new();
	belle_sip_uri_t *uri;
	_belle_sip_object_copy((belle_sip_object_t *)header, (belle_sip_object_t *)address);
	/*clear unwanted uri components*/
	if ((uri = belle_sip_header_address_get_uri(BELLE_SIP_HEADER_ADDRESS(header)))) {
		belle_sip_parameters_t *params = BELLE_SIP_PARAMETERS(uri);
		belle_sip_parameters_remove_parameter(params, "lr");
		belle_sip_parameters_remove_parameter(params, "ttl");
		belle_sip_parameters_remove_parameter(params, "method");
		belle_sip_parameters_remove_parameter(params, "maddr");
		belle_sip_parameters_remove_parameter(params, "transport");
		belle_sip_uri_set_port(uri, 0);
		belle_sip_uri_headers_clean(uri);
	}
	belle_sip_header_set_name(BELLE_SIP_HEADER(header), BELLE_SIP_DIVERSION); /*restaure header name*/
	if (tag) belle_sip_header_diversion_set_tag(header, tag);
	return header;
}
void belle_sip_header_diversion_set_random_tag(belle_sip_header_diversion_t *obj) {
	char tmp[8];
	/*not less than 32bit */
	belle_sip_header_diversion_set_tag(obj, belle_sip_random_token(tmp, sizeof(tmp)));
}

void belle_sip_header_diversion_set_tag(belle_sip_header_diversion_t *obj, const char *tag) {
	if (tag == BELLE_SIP_RANDOM_TAG) belle_sip_header_diversion_set_random_tag(obj);
	else belle_sip_header_diversion_set_raw_tag(obj, tag);
}

const char *belle_sip_header_diversion_get_tag(const belle_sip_header_diversion_t *obj) {
	return belle_sip_header_diversion_get_raw_tag(obj);
}

/******************************
 * Session-Expires inherits from parameters
 ******************************/
struct _belle_sip_header_session_expires {
	belle_sip_parameters_t params_list;
	int delta;
};

static void belle_sip_header_session_expires_destroy(belle_sip_header_session_expires_t *session_expires) {
}

static void belle_sip_header_session_expires_clone(belle_sip_header_session_expires_t *session_expires,
                                                   const belle_sip_header_session_expires_t *orig) {
	session_expires->delta = orig->delta;
	belle_sip_header_session_expires_set_refresher_value(session_expires,
	                                                     belle_sip_header_session_expires_get_refresher_value(orig));
}

belle_sip_error_code belle_sip_header_session_expires_marshal(belle_sip_header_session_expires_t *session_expires,
                                                              char *buff,
                                                              size_t buff_size,
                                                              size_t *offset) {
	belle_sip_error_code error = belle_sip_header_marshal(BELLE_SIP_HEADER(session_expires), buff, buff_size, offset);

	if (session_expires->delta) {
		error = belle_sip_snprintf(buff, buff_size, offset, "%i", session_expires->delta);
		if (error != BELLE_SIP_OK) return error;
	}

	error = belle_sip_parameters_marshal(&session_expires->params_list, buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;

	return error;
}

belle_sip_header_session_expires_t *
belle_sip_header_session_expires_create(int delta, belle_sip_header_session_expires_refresher_t refresher) {
	belle_sip_header_session_expires_t *session_expires = belle_sip_header_session_expires_new();

	belle_sip_header_session_expires_set_delta(session_expires, delta);
	if (refresher != BELLE_SIP_HEADER_SESSION_EXPIRES_UNSPECIFIED) {
		belle_sip_header_session_expires_set_refresher_value(session_expires, refresher);
	}

	return session_expires;
}

BELLE_SIP_PARSE_FULL(header_session_expires);
BELLE_SIP_NEW_HEADER(header_session_expires, parameters, BELLE_SIP_SESSION_EXPIRES);
GET_SET_STRING_PARAM(belle_sip_header_session_expires, refresher);
GET_SET_INT(belle_sip_header_session_expires, delta, int);

belle_sip_header_session_expires_refresher_t
belle_sip_header_session_expires_get_refresher_value(const belle_sip_header_session_expires_t *session_expires) {
	const char *refresher_value = belle_sip_header_session_expires_get_refresher(session_expires);

	if (refresher_value == NULL) {
		return BELLE_SIP_HEADER_SESSION_EXPIRES_UNSPECIFIED;
	} else if (strcmp("uac", refresher_value) == 0) {
		return BELLE_SIP_HEADER_SESSION_EXPIRES_UAC;
	} else if (strcmp("uas", refresher_value) == 0) {
		return BELLE_SIP_HEADER_SESSION_EXPIRES_UAS;
	}

	return BELLE_SIP_HEADER_SESSION_EXPIRES_UNSPECIFIED;
}

void belle_sip_header_session_expires_set_refresher_value(
    belle_sip_header_session_expires_t *session_expires, belle_sip_header_session_expires_refresher_t refresher_value) {
	switch (refresher_value) {
		case BELLE_SIP_HEADER_SESSION_EXPIRES_UNSPECIFIED:
			belle_sip_parameters_remove_parameter(BELLE_SIP_PARAMETERS(session_expires), "refresher");
			break;
		case BELLE_SIP_HEADER_SESSION_EXPIRES_UAC:
			belle_sip_header_session_expires_set_refresher(session_expires, "uac");
			break;
		case BELLE_SIP_HEADER_SESSION_EXPIRES_UAS:
			belle_sip_header_session_expires_set_refresher(session_expires, "uas");
			break;
	}
}

/******************************
 * User-Agent header inherits from header
 ******************************/
struct _belle_sip_header_user_agent {
	belle_sip_header_t header;
	belle_sip_list_t *products;
};

static void belle_sip_header_user_agent_destroy(belle_sip_header_user_agent_t *user_agent) {
	belle_sip_header_user_agent_set_products(user_agent, NULL);
}

static void belle_sip_header_user_agent_clone(belle_sip_header_user_agent_t *user_agent,
                                              const belle_sip_header_user_agent_t *orig) {
	belle_sip_list_t *list = orig->products;
	for (; list != NULL; list = list->next) {
		belle_sip_header_user_agent_add_product(user_agent, (const char *)list->data);
	}
}

belle_sip_error_code belle_sip_header_user_agent_marshal(belle_sip_header_user_agent_t *user_agent,
                                                         char *buff,
                                                         size_t buff_size,
                                                         size_t *offset) {
	belle_sip_error_code error = BELLE_SIP_OK;
	belle_sip_list_t *list = user_agent->products;
	error = belle_sip_header_marshal(BELLE_SIP_HEADER(user_agent), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	for (; list != NULL; list = list->next) {
		error = belle_sip_snprintf(buff, buff_size, offset, list == user_agent->products ? "%s" : " %s",
		                           (const char *)list->data);
		if (error != BELLE_SIP_OK) return error;
	}
	return error;
}

BELLE_SIP_NEW_HEADER(header_user_agent, header, "User-Agent");
BELLE_SIP_PARSE_FULL(header_user_agent);

belle_sip_list_t *belle_sip_header_user_agent_get_products(const belle_sip_header_user_agent_t *user_agent) {
	return user_agent->products;
}
void belle_sip_header_user_agent_set_products(belle_sip_header_user_agent_t *user_agent, belle_sip_list_t *products) {
	belle_sip_list_t *list;
	if (user_agent->products) {
		for (list = user_agent->products; list != NULL; list = list->next) {
			belle_sip_free((void *)list->data);
		}
		belle_sip_list_free(user_agent->products);
	}
	user_agent->products = products;
}
void belle_sip_header_user_agent_add_product(belle_sip_header_user_agent_t *user_agent, const char *product) {
	user_agent->products = belle_sip_list_append(user_agent->products, belle_sip_strdup(product));
}

int belle_sip_header_user_agent_get_products_as_string(const belle_sip_header_user_agent_t *user_agent,
                                                       char *value,
                                                       unsigned int value_size) {
	size_t result = 0;
	belle_sip_error_code error = BELLE_SIP_OK;
	belle_sip_list_t *list = user_agent->products;

	for (; list != NULL; list = list->next) {
		error = belle_sip_snprintf(value, value_size, &result, "%s ", (const char *)list->data);
		if (error != BELLE_SIP_OK) return -1;
	}
	if (result > 0) value[result - 1] = '\0'; /*remove last space */

	return (int)result - 1;
}

/**************************
 * Via header object inherits from parameters
 ***************************/
struct _belle_sip_header_via {
	belle_sip_parameters_t params_list;
	char *protocol;
	char *transport;
	char *host;
	int port;
	char *received;
};

static void belle_sip_header_via_destroy(belle_sip_header_via_t *via) {
	if (via->protocol) belle_sip_free(via->protocol);
	if (via->transport) belle_sip_free(via->transport);
	if (via->host) belle_sip_free(via->host);
	DESTROY_STRING(via, received)
}

static void belle_sip_header_via_clone(belle_sip_header_via_t *via, const belle_sip_header_via_t *orig) {
	CLONE_STRING(belle_sip_header_via, protocol, via, orig)
	CLONE_STRING(belle_sip_header_via, transport, via, orig)
	CLONE_STRING(belle_sip_header_via, host, via, orig)
	CLONE_STRING(belle_sip_header_via, received, via, orig)
	via->port = orig->port;
}

belle_sip_error_code
belle_sip_header_via_marshal(belle_sip_header_via_t *via, char *buff, size_t buff_size, size_t *offset) {
	belle_sip_error_code error = belle_sip_header_marshal(BELLE_SIP_HEADER(via), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_snprintf(buff, buff_size, offset, "%s/%s", via->protocol, via->transport);
	if (error != BELLE_SIP_OK) return error;

	if (via->host) {
		if (strchr(via->host, ':')) { /*ipv6*/
			error = belle_sip_snprintf(buff, buff_size, offset, " [%s]", via->host);
		} else {
			error = belle_sip_snprintf(buff, buff_size, offset, " %s", via->host);
		}
		if (error != BELLE_SIP_OK) return error;
	} else {
		belle_sip_warning("no host found in this via");
	}

	if (via->port > 0) {
		error = belle_sip_snprintf(buff, buff_size, offset, ":%i", via->port);
		if (error != BELLE_SIP_OK) return error;
	}
	if (via->received) {
		error = belle_sip_snprintf(buff, buff_size, offset, ";received=%s", via->received);
		if (error != BELLE_SIP_OK) return error;
	}

	error = belle_sip_parameters_marshal(&via->params_list, buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;

	return error;
}

belle_sip_header_via_t *
belle_sip_header_via_create(const char *host, int port, const char *transport, const char *branch) {
	belle_sip_header_via_t *via = belle_sip_header_via_new();
	via->host = belle_sip_strdup(host);
	via->port = port;
	via->transport = belle_sip_strdup(transport);
	via->protocol = belle_sip_strdup("SIP/2.0");
	belle_sip_header_via_set_branch(via, branch);
	return via;
}

BELLE_SIP_NEW_HEADER(header_via, parameters, BELLE_SIP_VIA);
BELLE_SIP_PARSE_WITH_CONTEXT(header_via);
GET_SET_STRING(belle_sip_header_via, protocol);
GET_SET_STRING(belle_sip_header_via, transport);
GET_SET_STRING_NO_ENCLOSING_BRACKETS(belle_sip_header_via, host);
GET_SET_STRING_NO_ENCLOSING_BRACKETS(belle_sip_header_via, received);
GET_SET_INT_PRIVATE(belle_sip_header_via, port, int, _);

GET_SET_STRING_PARAM(belle_sip_header_via, branch);
GET_SET_STRING_PARAM(belle_sip_header_via, maddr);

GET_SET_INT_PARAM_PRIVATE(belle_sip_header_via, rport, int, _);
GET_SET_INT_PARAM_PRIVATE(belle_sip_header_via, ttl, int, _);

int belle_sip_header_via_set_rport(belle_sip_header_via_t *obj, int value) {
	if (value == -1) {
		belle_sip_parameters_set_parameter(BELLE_SIP_PARAMETERS(obj), "rport", NULL);
		return 0;
	}
	if (value > 0 && value < 65536) {
		_belle_sip_header_via_set_rport(obj, value);
		return 0;
	} else {
		belle_sip_error("bad rport value [%i] for via", value);
		return -1;
	}
}
int belle_sip_header_via_set_ttl(belle_sip_header_via_t *obj, int value) {
	if (value == -1 || (value > 0 && value <= 255)) {
		_belle_sip_header_via_set_ttl(obj, value);
		return 0;
	} else {
		belle_sip_error("bad ttl value [%i] for via", value);
		return -1;
	}
}

int belle_sip_header_via_set_port(belle_sip_header_via_t *obj, int value) {
	if (value == -1 || (value > 0 && value < 65536)) {
		_belle_sip_header_via_set_port(obj, value);
		return 0;
	} else {
		belle_sip_error("bad port value [%i] for via", value);
		return -1;
	}
}

int belle_sip_header_via_get_listening_port(const belle_sip_header_via_t *via) {
	int ret = belle_sip_header_via_get_port(via);
	if (ret == 0) ret = belle_sip_listening_point_get_well_known_port(via->transport);
	return ret;
}

const char *belle_sip_header_via_get_transport_lowercase(const belle_sip_header_via_t *via) {
	if (strcasecmp("udp", via->transport) == 0) return "udp";
	else if (strcasecmp("tcp", via->transport) == 0) return "tcp";
	else if (strcasecmp("tls", via->transport) == 0) return "tls";
	else if (strcasecmp("dtls", via->transport) == 0) return "dtls";
	else {
		belle_sip_warning("Cannot convert [%s] to lower case", via->transport);
		return via->transport;
	}
}

/**************************
 * call_id header object inherits from object
 ***************************/
struct _belle_sip_header_call_id {
	belle_sip_header_t header;
	const char *call_id;
};

static void belle_sip_header_call_id_destroy(belle_sip_header_call_id_t *call_id) {
	if (call_id->call_id) belle_sip_free((void *)call_id->call_id);
}

static void belle_sip_header_call_id_clone(belle_sip_header_call_id_t *call_id,
                                           const belle_sip_header_call_id_t *orig) {
	CLONE_STRING(belle_sip_header_call_id, call_id, call_id, orig);
}

belle_sip_error_code
belle_sip_header_call_id_marshal(belle_sip_header_call_id_t *call_id, char *buff, size_t buff_size, size_t *offset) {
	belle_sip_error_code error = belle_sip_header_marshal(BELLE_SIP_HEADER(call_id), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_snprintf(buff, buff_size, offset, "%s", call_id->call_id);
	if (error != BELLE_SIP_OK) return error;
	return error;
}

unsigned int belle_sip_header_call_id_equals(const belle_sip_header_call_id_t *a, const belle_sip_header_call_id_t *b) {
	return strcasecmp(a->call_id, b->call_id) == 0;
}
BELLE_SIP_NEW_HEADER(header_call_id, header, BELLE_SIP_CALL_ID);
BELLE_SIP_PARSE_FULL(header_call_id);
GET_SET_STRING(belle_sip_header_call_id, call_id);

/**************************
 * retry-after header object inherits from object
 ***************************/
struct _belle_sip_header_retry_after {
	belle_sip_header_t header;
	int retry_after;
};

static void belle_sip_header_retry_after_destroy(belle_sip_header_retry_after_t *retry_after) {
}

static void belle_sip_header_retry_after_clone(belle_sip_header_retry_after_t *retry_after,
                                               const belle_sip_header_retry_after_t *orig) {
	retry_after->retry_after = orig->retry_after;
}

belle_sip_error_code belle_sip_header_retry_after_marshal(belle_sip_header_retry_after_t *retry_after,
                                                          char *buff,
                                                          size_t buff_size,
                                                          size_t *offset) {
	belle_sip_error_code error = belle_sip_header_marshal(BELLE_SIP_HEADER(retry_after), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	if (retry_after->retry_after > 0) {
		error = belle_sip_snprintf(buff, buff_size, offset, "%i", retry_after->retry_after);
		if (error != BELLE_SIP_OK) return error;
	}
	return error;
}

BELLE_SIP_NEW_HEADER(header_retry_after, header, BELLE_SIP_RETRY_AFTER);
BELLE_SIP_PARSE_FULL(header_retry_after);
GET_SET_INT(belle_sip_header_retry_after, retry_after, int);

belle_sip_header_retry_after_t *belle_sip_header_retry_after_create(int retry_after) {
	belle_sip_header_retry_after_t *obj;
	obj = belle_sip_header_retry_after_new();
	belle_sip_header_retry_after_set_retry_after(obj, retry_after);
	return obj;
}

/**************************
 * cseq header object inherit from object
 ***************************/
struct _belle_sip_header_cseq {
	belle_sip_header_t header;
	char *method;
	unsigned int seq_number;
};

static void belle_sip_header_cseq_destroy(belle_sip_header_cseq_t *cseq) {
	if (cseq->method) belle_sip_free(cseq->method);
}

static void belle_sip_header_cseq_clone(belle_sip_header_cseq_t *cseq, const belle_sip_header_cseq_t *orig) {
	CLONE_STRING(belle_sip_header_cseq, method, cseq, orig)
	cseq->seq_number = orig->seq_number;
}

belle_sip_error_code
belle_sip_header_cseq_marshal(belle_sip_header_cseq_t *cseq, char *buff, size_t buff_size, size_t *offset) {
	belle_sip_error_code error = belle_sip_header_marshal(BELLE_SIP_HEADER(cseq), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_snprintf(buff, buff_size, offset, "%i %s", cseq->seq_number, cseq->method);
	if (error != BELLE_SIP_OK) return error;
	return error;
}

belle_sip_header_cseq_t *belle_sip_header_cseq_create(unsigned int number, const char *method) {
	belle_sip_header_cseq_t *cseq = belle_sip_header_cseq_new();
	belle_sip_header_cseq_set_method(cseq, method);
	cseq->seq_number = number;
	return cseq;
}

BELLE_SIP_NEW_HEADER(header_cseq, header, BELLE_SIP_CSEQ);
BELLE_SIP_PARSE_FULL(header_cseq);
GET_SET_STRING(belle_sip_header_cseq, method);
GET_SET_INT(belle_sip_header_cseq, seq_number, unsigned int);

/**************************
 * content type header object inherit from parameters
 ***************************/
struct _belle_sip_header_content_type {
	belle_sip_parameters_t params_list;
	const char *type;
	const char *subtype;
};

static void belle_sip_header_content_type_destroy(belle_sip_header_content_type_t *content_type) {
	if (content_type->type) belle_sip_free((void *)content_type->type);
	if (content_type->subtype) belle_sip_free((void *)content_type->subtype);
}

static void belle_sip_header_content_type_clone(belle_sip_header_content_type_t *content_type,
                                                const belle_sip_header_content_type_t *orig) {
	CLONE_STRING(belle_sip_header_content_type, type, content_type, orig);
	CLONE_STRING(belle_sip_header_content_type, subtype, content_type, orig);
}

belle_sip_error_code belle_sip_header_content_type_marshal(belle_sip_header_content_type_t *content_type,
                                                           char *buff,
                                                           size_t buff_size,
                                                           size_t *offset) {
	belle_sip_error_code error = belle_sip_header_marshal(BELLE_SIP_HEADER(content_type), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_snprintf(buff, buff_size, offset, "%s/%s", content_type->type, content_type->subtype);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_parameters_marshal(&content_type->params_list, buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	return error;
}

BELLE_SIP_NEW_HEADER(header_content_type, parameters, BELLE_SIP_CONTENT_TYPE);
BELLE_SIP_PARSE_FULL(header_content_type);

belle_sip_header_content_type_t *belle_sip_header_content_type_create(const char *type, const char *sub_type) {
	belle_sip_header_content_type_t *header = belle_sip_header_content_type_new();
	belle_sip_header_content_type_set_type(header, type);
	belle_sip_header_content_type_set_subtype(header, sub_type);
	return header;
}

GET_SET_STRING(belle_sip_header_content_type, type);
GET_SET_STRING(belle_sip_header_content_type, subtype);

/**************************
 * Route header object inherits from header_address
 ***************************/
struct _belle_sip_header_route {
	belle_sip_header_address_t address;
};

static void belle_sip_header_route_destroy(belle_sip_header_route_t *route) {
}

static void belle_sip_header_route_clone(belle_sip_header_route_t *route, const belle_sip_header_route_t *orig) {
}

belle_sip_error_code belle_sip_header_route_marshal(belle_sip_header_route_t *route,
                                                    char *buff,
                                                    size_t buff_size,
                                                    size_t *offset){BELLE_SIP_FROM_LIKE_MARSHAL(route, TRUE)}

BELLE_SIP_NEW_HEADER(header_route, header_address, BELLE_SIP_ROUTE) BELLE_SIP_PARSE_WITH_CONTEXT(header_route);

belle_sip_header_route_t *belle_sip_header_route_create(const belle_sip_header_address_t *route) {
	belle_sip_header_route_t *header = belle_sip_header_route_new();
	_belle_sip_object_copy((belle_sip_object_t *)header, (belle_sip_object_t *)route);
	belle_sip_header_set_next(BELLE_SIP_HEADER(header), NULL);            /*make sure only one header is kept*/
	belle_sip_header_set_name(BELLE_SIP_HEADER(header), BELLE_SIP_ROUTE); /*restore header name*/
	return header;
}

int belle_sip_header_route_equals(const belle_sip_header_route_t *route_a, const belle_sip_header_route_t *route_b) {
	// Routes are not identical if either is NULL
	if (!route_a | !route_b) {
		return -1;
	}
	return belle_sip_header_address_equals(&route_a->address, &route_b->address);
}
/**************************
 * Record route header object inherits from header_address
 ***************************/
struct _belle_sip_header_record_route {
	belle_sip_header_address_t address;
	unsigned char auto_outgoing;
	unsigned char pad[3];
};

static void belle_sip_header_record_route_destroy(belle_sip_header_record_route_t *record_route) {
}

static void belle_sip_header_record_route_clone(belle_sip_header_record_route_t *record_route,
                                                const belle_sip_header_record_route_t *orig) {
}

belle_sip_error_code belle_sip_header_record_route_marshal(belle_sip_header_record_route_t *record_route,
                                                           char *buff,
                                                           size_t buff_size,
                                                           size_t *offset){
    BELLE_SIP_FROM_LIKE_MARSHAL(record_route, TRUE)}

belle_sip_header_record_route_t *belle_sip_header_record_route_new_auto_outgoing() {
	belle_sip_header_record_route_t *rr = belle_sip_header_record_route_new();
	rr->auto_outgoing = TRUE;
	return rr;
}

unsigned char belle_sip_header_record_route_get_auto_outgoing(const belle_sip_header_record_route_t *a) {
	return a->auto_outgoing;
}

BELLE_SIP_NEW_HEADER(header_record_route, header_address, BELLE_SIP_RECORD_ROUTE);
BELLE_SIP_PARSE_WITH_CONTEXT(header_record_route);

/**************************
 * Service route header object inherits from header_address
 ***************************/
struct _belle_sip_header_service_route {
	belle_sip_header_address_t address;
};

static void belle_sip_header_service_route_destroy(belle_sip_header_service_route_t *service_route) {
}

static void belle_sip_header_service_route_clone(belle_sip_header_service_route_t *service_route,
                                                 const belle_sip_header_service_route_t *orig) {
}

belle_sip_error_code belle_sip_header_service_route_marshal(belle_sip_header_service_route_t *service_route,
                                                            char *buff,
                                                            size_t buff_size,
                                                            size_t *offset){
    BELLE_SIP_FROM_LIKE_MARSHAL(service_route, TRUE)}

BELLE_SIP_NEW_HEADER(header_service_route, header_address, BELLE_SIP_SERVICE_ROUTE);
BELLE_SIP_PARSE_WITH_CONTEXT(header_service_route);

/**************************
 * content length header object inherit from object
 ***************************/
struct _belle_sip_header_content_length {
	belle_sip_header_t header;
	size_t content_length;
};

static void belle_sip_header_content_length_destroy(belle_sip_header_content_length_t *content_length) {
}

static void belle_sip_header_content_length_clone(belle_sip_header_content_length_t *content_length,
                                                  const belle_sip_header_content_length_t *orig) {
	content_length->content_length = orig->content_length;
}

belle_sip_error_code belle_sip_header_content_length_marshal(belle_sip_header_content_length_t *content_length,
                                                             char *buff,
                                                             size_t buff_size,
                                                             size_t *offset) {
	belle_sip_error_code error = belle_sip_header_marshal(BELLE_SIP_HEADER(content_length), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_snprintf(buff, buff_size, offset, FORMAT_SIZE_T, content_length->content_length);
	if (error != BELLE_SIP_OK) return error;
	return error;
}

BELLE_SIP_NEW_HEADER(header_content_length, header, BELLE_SIP_CONTENT_LENGTH);
BELLE_SIP_PARSE_FULL(header_content_length);
GET_SET_INT(belle_sip_header_content_length, content_length, size_t);

belle_sip_header_content_length_t *belle_sip_header_content_length_create(size_t content_length) {
	belle_sip_header_content_length_t *obj;
	obj = belle_sip_header_content_length_new();
	belle_sip_header_content_length_set_content_length(obj, content_length);
	return obj;
}

/**************************
 * Expires header object inherit from header
 ***************************/
struct _belle_sip_header_expires {
	belle_sip_header_t header;
	int expires;
};

static void belle_sip_header_expires_destroy(belle_sip_header_expires_t *expires) {
}

static void belle_sip_header_expires_clone(belle_sip_header_expires_t *expires,
                                           const belle_sip_header_expires_t *orig) {
	expires->expires = orig->expires;
}

belle_sip_error_code
belle_sip_header_expires_marshal(belle_sip_header_expires_t *expires, char *buff, size_t buff_size, size_t *offset) {
	belle_sip_error_code error = belle_sip_header_marshal(BELLE_SIP_HEADER(expires), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_snprintf(buff, buff_size, offset, "%i", expires->expires);
	if (error != BELLE_SIP_OK) return error;
	return error;
}

BELLE_SIP_NEW_HEADER(header_expires, header, BELLE_SIP_EXPIRES);
BELLE_SIP_PARSE_FULL(header_expires);
GET_SET_INT(belle_sip_header_expires, expires, int);

belle_sip_header_expires_t *belle_sip_header_expires_create(int expires) {
	belle_sip_header_expires_t *obj = belle_sip_header_expires_new();
	belle_sip_header_expires_set_expires(obj, expires);
	return obj;
}

/******************************
 * Extension header inherits from header
 ******************************/
struct _belle_sip_header_extension {
	belle_sip_header_t header;
	const char *value;
};

static void belle_sip_header_extension_destroy(belle_sip_header_extension_t *extension) {
	if (extension->value) belle_sip_free((void *)extension->value);
}

static void belle_sip_header_extension_clone(belle_sip_header_extension_t *extension,
                                             const belle_sip_header_extension_t *orig){
    CLONE_STRING(belle_sip_header_extension, value, extension, orig)}

belle_sip_error_code belle_sip_header_extension_marshal(belle_sip_header_extension_t *extension,
                                                        char *buff,
                                                        size_t buff_size,
                                                        size_t *offset) {
	belle_sip_error_code error = belle_sip_header_marshal(BELLE_SIP_HEADER(extension), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	if (extension->value) error = belle_sip_snprintf(buff, buff_size, offset, "%s", extension->value);
	if (error != BELLE_SIP_OK) return error;
	return error;
}

BELLE_SIP_NEW_HEADER(header_extension, header, NULL);

belle_sip_header_extension_t *belle_sip_header_extension_create(const char *name, const char *value) {
	belle_sip_header_extension_t *ext = belle_sip_header_extension_new();
	belle_sip_header_set_name(BELLE_SIP_HEADER(ext), name);
	belle_sip_header_extension_set_value(ext, value);
	return ext;
}

GET_SET_STRING(belle_sip_header_extension, value);

/**************************
 *Authorization header object inherits from parameters
 ***************************/
#define AUTH_BASE                                                                                                      \
	belle_sip_parameters_t params_list;                                                                                \
	const char *scheme;                                                                                                \
	const char *realm;                                                                                                 \
	const char *nonce;                                                                                                 \
	const char *algorithm;                                                                                             \
	const char *opaque;

#define AUTH_BASE_DESTROY(obj)                                                                                         \
	if (obj->scheme) belle_sip_free((void *)obj->scheme);                                                              \
	if (obj->realm) belle_sip_free((void *)obj->realm);                                                                \
	if (obj->nonce) belle_sip_free((void *)obj->nonce);                                                                \
	if (obj->algorithm) belle_sip_free((void *)obj->algorithm);                                                        \
	if (obj->opaque) belle_sip_free((void *)obj->opaque);

/*if (obj->params_list) FIXME free list*/

#define AUTH_BASE_CLONE(object_type, dest, src)                                                                        \
	CLONE_STRING(object_type, scheme, dest, src)                                                                       \
	CLONE_STRING(object_type, realm, dest, src)                                                                        \
	CLONE_STRING(object_type, nonce, dest, src)                                                                        \
	CLONE_STRING(object_type, algorithm, dest, src)                                                                    \
	CLONE_STRING(object_type, opaque, dest, src)

#define AUTH_BASE_MARSHAL(header)                                                                                      \
	std::string border = " ";                                                                                          \
	const belle_sip_list_t *list;                                                                                      \
	belle_sip_error_code error = belle_sip_header_marshal(BELLE_SIP_HEADER(header), buff, buff_size, offset);          \
	if (error != BELLE_SIP_OK) return error;                                                                           \
	list = belle_sip_parameters_get_parameters(&header->params_list);                                                  \
	if (header->scheme) {                                                                                              \
		error = belle_sip_snprintf(buff, buff_size, offset, "%s", header->scheme);                                     \
		if (error != BELLE_SIP_OK) return error;                                                                       \
	} else {                                                                                                           \
		belle_sip_error("missing mandatory scheme");                                                                   \
	}                                                                                                                  \
	for (; list != NULL; list = list->next) {                                                                          \
		belle_sip_param_pair_t *container = reinterpret_cast<belle_sip_param_pair_t *>(list->data);                    \
		error = belle_sip_snprintf(buff, buff_size, offset, "%s%s", border.c_str(), container->name);                  \
		if (error != BELLE_SIP_OK) return error;                                                                       \
		if (container->value) error = belle_sip_snprintf(buff, buff_size, offset, "=%s", container->value);            \
		if (error != BELLE_SIP_OK) return error;                                                                       \
		border = ", ";                                                                                                 \
	}                                                                                                                  \
	if (header->realm) {                                                                                               \
		error = belle_sip_snprintf(buff, buff_size, offset, "%srealm=\"%s\"", border.c_str(), header->realm);          \
		if (error != BELLE_SIP_OK) return error;                                                                       \
		border = ", ";                                                                                                 \
	}                                                                                                                  \
	if (header->nonce) {                                                                                               \
		error = belle_sip_snprintf(buff, buff_size, offset, "%snonce=\"%s\"", border.c_str(), header->nonce);          \
		if (error != BELLE_SIP_OK) return error;                                                                       \
		border = ", ";                                                                                                 \
	}                                                                                                                  \
	if (header->algorithm) {                                                                                           \
		const char *format;                                                                                            \
		if (BELLE_SIP_OBJECT_IS_INSTANCE_OF(header, belle_http_header_authorization_t)) {                              \
			format = "%salgorithm=\"%s\"";                                                                             \
		} else {                                                                                                       \
			format = "%salgorithm=%s";                                                                                 \
		}                                                                                                              \
		error = belle_sip_snprintf(buff, buff_size, offset, format, border.c_str(), header->algorithm);                \
		if (error != BELLE_SIP_OK) return error;                                                                       \
		border = ", ";                                                                                                 \
	}                                                                                                                  \
	if (header->opaque) {                                                                                              \
		error = belle_sip_snprintf(buff, buff_size, offset, "%sopaque=\"%s\"", border.c_str(), header->opaque);        \
		if (error != BELLE_SIP_OK) return error;                                                                       \
		border = ", ";                                                                                                 \
	}

struct _belle_sip_header_authorization {
	AUTH_BASE
	const char *username;
	belle_sip_uri_t *uri;
	const char *response;
	const char *cnonce;
	int nonce_count;
	const char *qop;
	belle_sip_bearer_token_t *token;
};

static void belle_sip_header_authorization_destroy(belle_sip_header_authorization_t *authorization) {
	if (authorization->username) belle_sip_free((void *)authorization->username);
	if (authorization->uri) {
		belle_sip_object_unref(authorization->uri);
	}
	if (authorization->cnonce) belle_sip_free((void *)authorization->cnonce);
	AUTH_BASE_DESTROY(authorization)
	DESTROY_STRING(authorization, response);
	DESTROY_STRING(authorization, qop);
}

static void belle_sip_header_authorization_clone(belle_sip_header_authorization_t *authorization,
                                                 const belle_sip_header_authorization_t *orig) {
	AUTH_BASE_CLONE(belle_sip_header_authorization, authorization, orig)
	CLONE_STRING(belle_sip_header_authorization, username, authorization, orig)
	if (belle_sip_header_authorization_get_uri(orig)) {
		belle_sip_header_authorization_set_uri(
		    authorization,
		    BELLE_SIP_URI(belle_sip_object_clone(BELLE_SIP_OBJECT(belle_sip_header_authorization_get_uri(orig)))));
	}
	CLONE_STRING(belle_sip_header_authorization, response, authorization, orig)
	CLONE_STRING(belle_sip_header_authorization, cnonce, authorization, orig)
	authorization->nonce_count = orig->nonce_count;
	CLONE_STRING(belle_sip_header_authorization, qop, authorization, orig)
}

static void belle_sip_header_authorization_init(belle_sip_header_authorization_t *authorization) {
}

belle_sip_uri_t *belle_sip_header_authorization_get_uri(const belle_sip_header_authorization_t *authorization) {
	return authorization->uri;
}

void belle_sip_header_authorization_set_uri(belle_sip_header_authorization_t *authorization, belle_sip_uri_t *uri) {
	if (uri) belle_sip_object_ref(uri);
	if (authorization->uri) {
		belle_sip_object_unref(BELLE_SIP_OBJECT(authorization->uri));
	}
	authorization->uri = uri;
}

belle_sip_error_code belle_sip_header_authorization_marshal(belle_sip_header_authorization_t *authorization,
                                                            char *buff,
                                                            size_t buff_size,
                                                            size_t *offset) {
	char nonce_count[10];
	AUTH_BASE_MARSHAL(authorization)
	if (authorization->username) {
		error =
		    belle_sip_snprintf(buff, buff_size, offset, "%susername=\"%s\"", border.c_str(), authorization->username);
		if (error != BELLE_SIP_OK) return error;
		border = ", ";
	}
	if (authorization->uri) {
		error = belle_sip_snprintf(buff, buff_size, offset, "%s uri=\"", border.c_str());
		if (error != BELLE_SIP_OK) return error;
		border = ", ";
		error = belle_sip_uri_marshal(authorization->uri, buff, buff_size, offset);
		if (error != BELLE_SIP_OK) return error;
		error = belle_sip_snprintf(buff, buff_size, offset, "%s", "\"");
		if (error != BELLE_SIP_OK) return error;
	}

	if (authorization->response) {
		error =
		    belle_sip_snprintf(buff, buff_size, offset, "%sresponse=\"%s\"", border.c_str(), authorization->response);
		if (error != BELLE_SIP_OK) return error;
		border = ", ";
	}
	if (authorization->cnonce) {
		error = belle_sip_snprintf(buff, buff_size, offset, "%scnonce=\"%s\"", border.c_str(), authorization->cnonce);
		if (error != BELLE_SIP_OK) return error;
		border = ", ";
	}
	if (authorization->nonce_count > 0) {
		belle_sip_header_authorization_get_nonce_count_as_string(authorization, nonce_count);
		error = belle_sip_snprintf(buff, buff_size, offset, "%snc=%s", border.c_str(), nonce_count);
		if (error != BELLE_SIP_OK) return error;
		border = ", ";
	}
	if (authorization->qop) {
		const char *format;
		format = "%sqop=%s";
		error = belle_sip_snprintf(buff, buff_size, offset, format, border.c_str(), authorization->qop);
		if (error != BELLE_SIP_OK) return error;
	}
	return error;
}

BELLE_SIP_NEW_HEADER(header_authorization, parameters, BELLE_SIP_AUTHORIZATION);
BELLE_SIP_PARSE_FULL(header_authorization);
GET_SET_STRING(belle_sip_header_authorization, scheme);
GET_SET_STRING(belle_sip_header_authorization, username);
SET_QUOTED_STRING(belle_sip_header_authorization, username);
GET_SET_STRING(belle_sip_header_authorization, realm);
SET_QUOTED_STRING(belle_sip_header_authorization, realm);
GET_SET_STRING(belle_sip_header_authorization, nonce);
SET_QUOTED_STRING(belle_sip_header_authorization, nonce);
GET_SET_STRING(belle_sip_header_authorization, response);
SET_QUOTED_STRING(belle_sip_header_authorization, response);
GET_SET_STRING(belle_sip_header_authorization, algorithm);
GET_SET_STRING(belle_sip_header_authorization, cnonce);
GET_SET_STRING(belle_sip_header_authorization, opaque);
SET_QUOTED_STRING(belle_sip_header_authorization, opaque);
GET_SET_STRING(belle_sip_header_authorization, qop);
GET_SET_INT(belle_sip_header_authorization, nonce_count, int);

int belle_sip_header_authorization_get_nonce_count_as_string(const belle_sip_header_authorization_t *authorization,
                                                             char nounce_count[9]) {
	nounce_count[0] = '\0';
	if (authorization->nonce_count > 0) {
		snprintf(nounce_count, 9, "%08x", authorization->nonce_count);
		return 0;
	} else {
		return -1;
	}
}

/**************************
 *Proxy-Authorization header object inherit from parameters
 ***************************/
struct _belle_sip_header_proxy_authorization {
	belle_sip_header_authorization_t authorization;
};

static void belle_sip_header_proxy_authorization_destroy(belle_sip_header_proxy_authorization_t *proxy_authorization) {
}

static void belle_sip_header_proxy_authorization_clone(belle_sip_header_proxy_authorization_t *proxy_authorization,
                                                       const belle_sip_header_proxy_authorization_t *orig) {
}

belle_sip_error_code belle_sip_header_proxy_authorization_marshal(
    belle_sip_header_proxy_authorization_t *proxy_authorization, char *buff, size_t buff_size, size_t *offset) {
	return belle_sip_header_authorization_marshal(&proxy_authorization->authorization, buff, buff_size, offset);
}

BELLE_SIP_NEW_HEADER(header_proxy_authorization, header_authorization, BELLE_SIP_PROXY_AUTHORIZATION);
BELLE_SIP_PARSE_FULL(header_proxy_authorization);

/**************************
 *HTTP Authorization header object inherit from Authorization
 ***************************/
struct _belle_http_header_authorization {
	belle_sip_header_authorization_t authorization;
	belle_generic_uri_t *uri;
};

static void belle_http_header_authorization_init(belle_http_header_authorization_t *authorization) {
	belle_sip_header_set_name(BELLE_SIP_HEADER(authorization), BELLE_HTTP_AUTHORIZATION);
}
static void belle_http_header_authorization_destroy(belle_http_header_authorization_t *authorization) {
	if (authorization->uri) {
		belle_sip_object_unref(authorization->uri);
	}
}

static void belle_http_header_authorization_clone(belle_http_header_authorization_t *authorization,
                                                  const belle_http_header_authorization_t *orig) {
	if (belle_http_header_authorization_get_uri(orig)) {
		belle_http_header_authorization_set_uri(
		    authorization,
		    BELLE_GENERIC_URI(belle_sip_object_clone(BELLE_SIP_OBJECT(belle_http_header_authorization_get_uri(orig)))));
	}
}

belle_sip_error_code belle_http_header_authorization_marshal(belle_http_header_authorization_t *authorization,
                                                             char *buff,
                                                             size_t buff_size,
                                                             size_t *offset) {
	belle_sip_error_code error = BELLE_SIP_OK;

	/*first make sure there is no sip uri*/
	if (belle_sip_header_authorization_get_uri(BELLE_SIP_HEADER_AUTHORIZATION(authorization))) {
		belle_sip_error("Cannot marshal http_header_authorization because a sip uri is set. Use "
		                "belle_http_authorization_set uri instead of belle_sip_header_authorization_set_uri");
		return BELLE_SIP_NOT_IMPLEMENTED;
	}
	belle_sip_header_authorization_marshal(BELLE_SIP_HEADER_AUTHORIZATION(authorization), buff, buff_size, offset);
	if (authorization->uri) {
		error = belle_sip_snprintf(buff, buff_size, offset, ", uri=\"");
		if (error != BELLE_SIP_OK) return error;
		error = belle_generic_uri_marshal(authorization->uri, buff, buff_size, offset);
		if (error != BELLE_SIP_OK) return error;
		error = belle_sip_snprintf(buff, buff_size, offset, "%s", "\"");
		if (error != BELLE_SIP_OK) return error;
	}
	return error;
}

BELLE_NEW(belle_http_header_authorization, belle_sip_header_authorization);

belle_generic_uri_t *belle_http_header_authorization_get_uri(const belle_http_header_authorization_t *authorization) {
	return authorization->uri;
}
void belle_http_header_authorization_set_uri(belle_http_header_authorization_t *authorization,
                                             belle_generic_uri_t *uri) {
	if (authorization->uri) belle_sip_object_unref(authorization->uri);
	if (uri) belle_sip_object_ref(uri);
	authorization->uri = uri;
}

/**************************
 * WWW-Authenticate header object inherits from parameters
 **************************/
struct _belle_sip_header_www_authenticate {
	AUTH_BASE
	char *domain;
	char *authz_server;
	int stale;
	belle_sip_list_t *qop;
};

static void belle_sip_header_www_authenticate_destroy(belle_sip_header_www_authenticate_t *www_authenticate) {
	AUTH_BASE_DESTROY(www_authenticate)
	if (www_authenticate->domain) belle_sip_free(www_authenticate->domain);
	if (www_authenticate->qop) belle_sip_list_free_with_data(www_authenticate->qop, belle_sip_free);
	if (www_authenticate->authz_server) belle_sip_free(www_authenticate->authz_server);
}
void belle_sip_header_www_authenticate_init(belle_sip_header_www_authenticate_t *www_authenticate) {
	www_authenticate->stale = -1;
}
static void belle_sip_header_www_authenticate_clone(belle_sip_header_www_authenticate_t *www_authenticate,
                                                    const belle_sip_header_www_authenticate_t *orig) {
	AUTH_BASE_CLONE(belle_sip_header_www_authenticate, www_authenticate, orig)
	CLONE_STRING(belle_sip_header_www_authenticate, domain, www_authenticate, orig)
	www_authenticate->stale = orig->stale;
	www_authenticate->qop = belle_sip_list_copy_with_data(orig->qop, (void *(*)(void *))belle_sip_strdup);
}

belle_sip_error_code belle_sip_header_www_authenticate_marshal(belle_sip_header_www_authenticate_t *www_authenticate,
                                                               char *buff,
                                                               size_t buff_size,
                                                               size_t *offset) {
	belle_sip_list_t *qops = www_authenticate->qop;
	AUTH_BASE_MARSHAL(www_authenticate)
	if (www_authenticate->domain) {
		error =
		    belle_sip_snprintf(buff, buff_size, offset, "%sdomain=\"%s\"", border.c_str(), www_authenticate->domain);
		if (error != BELLE_SIP_OK) return error;
		border = ", ";
	}
	if (www_authenticate->stale >= 0) {
		error = belle_sip_snprintf(buff, buff_size, offset, "%sstale=%s", border.c_str(),
		                           www_authenticate->stale ? "true" : "false");
		if (error != BELLE_SIP_OK) return error;
	}
	if (qops != NULL && qops->data != NULL) {
		error = belle_sip_snprintf(buff, buff_size, offset, "%sqop=\"", border.c_str());
		if (error != BELLE_SIP_OK) return error;
		border = "";
		for (; qops != NULL; qops = qops->next) {
			error = belle_sip_snprintf(buff, buff_size, offset, "%s%s", border.c_str(), (const char *)qops->data);
			if (error != BELLE_SIP_OK) return error;
			border = ",";
		}
		error = belle_sip_snprintf(buff, buff_size, offset, "\"");
		if (error != BELLE_SIP_OK) return error;
		border = ", ";
	}
	return error;
}

#define SET_ADD_STRING_LIST(header, name)                                                                              \
	void header##_set_##name(header##_t *obj, belle_sip_list_t *value) {                                               \
		if (obj->name) {                                                                                               \
			belle_sip_list_free_with_data(obj->name, belle_sip_free);                                                  \
		}                                                                                                              \
		obj->name = value;                                                                                             \
	}                                                                                                                  \
	void header##_add_##name(header##_t *obj, const char *value) {                                                     \
		obj->name = belle_sip_list_append(obj->name, strdup(value));                                                   \
	}

BELLE_SIP_NEW_HEADER_INIT(header_www_authenticate, parameters, BELLE_SIP_WWW_AUTHENTICATE, header_www_authenticate);
BELLE_SIP_PARSE_WITH_CONTEXT(header_www_authenticate);
GET_SET_STRING(belle_sip_header_www_authenticate, scheme);
GET_SET_STRING(belle_sip_header_www_authenticate, realm);
SET_QUOTED_STRING(belle_sip_header_www_authenticate, realm);
GET_SET_STRING(belle_sip_header_www_authenticate, nonce);
SET_QUOTED_STRING(belle_sip_header_www_authenticate, nonce);
GET_SET_STRING(belle_sip_header_www_authenticate, algorithm);
GET_SET_STRING(belle_sip_header_www_authenticate, opaque);
SET_QUOTED_STRING(belle_sip_header_www_authenticate, opaque);
SET_ADD_STRING_LIST(belle_sip_header_www_authenticate, qop);
GET_SET_STRING(belle_sip_header_www_authenticate, domain);
SET_QUOTED_STRING(belle_sip_header_www_authenticate, domain);
GET_SET_BOOL(belle_sip_header_www_authenticate, stale, is);

void belle_sip_header_www_authenticate_set_qop_options(belle_sip_header_www_authenticate_t *obj,
                                                       belle_sip_qop_options_t *options) {
	belle_sip_header_www_authenticate_set_qop(obj, options->list);
	belle_sip_object_unref(options);
}
belle_sip_list_t *
belle_sip_header_www_authenticate_get_qop(const belle_sip_header_www_authenticate_t *www_authetication) {
	return www_authetication->qop;
}
const char *
belle_sip_header_www_authenticate_get_qop_first(const belle_sip_header_www_authenticate_t *www_authetication) {
	return www_authetication->qop ? (const char *)www_authetication->qop->data : NULL;
}

const char *
belle_sip_header_www_authenticate_get_authz_server(const belle_sip_header_www_authenticate_t *www_authenticate) {
	belle_sip_header_www_authenticate_t *mutable_authenticate = (belle_sip_header_www_authenticate_t *)www_authenticate;
	const char *authz_server =
	    belle_sip_parameters_get_parameter(BELLE_SIP_PARAMETERS(www_authenticate), "authz_server");
	if (mutable_authenticate->authz_server) {
		belle_sip_free(mutable_authenticate->authz_server);
		mutable_authenticate->authz_server = NULL;
	}
	if (authz_server) mutable_authenticate->authz_server = _belle_sip_str_dup_and_unquote_string(authz_server);
	return mutable_authenticate->authz_server;
}
void belle_sip_header_www_authenticate_set_string_stale(belle_sip_header_www_authenticate_t *obj, const char *value) {
	if (strcmp("true", value) == 0) {
		belle_sip_header_www_authenticate_set_stale(obj, 1);
	}
}

belle_sip_qop_options_t *belle_sip_qop_options_new(void) {
	return belle_sip_object_new(belle_sip_qop_options_t);
}

void belle_sip_qop_options_append(belle_sip_qop_options_t *obj, const char *value) {
	obj->list = belle_sip_list_append(obj->list, belle_sip_strdup(value));
}

BELLE_SIP_DECLARE_NO_IMPLEMENTED_INTERFACES(belle_sip_qop_options_t);
BELLE_SIP_INSTANCIATE_VPTR(belle_sip_qop_options_t, belle_sip_object_t, nullptr, nullptr, nullptr, TRUE);

/**************************
 *Proxy-authenticate header object inherits from www_authenticate
 ***************************/
struct _belle_sip_header_proxy_authenticate {
	belle_sip_header_www_authenticate_t www_authenticate;
};

static void belle_sip_header_proxy_authenticate_destroy(belle_sip_header_proxy_authenticate_t *proxy_authenticate) {
}

static void belle_sip_header_proxy_authenticate_clone(belle_sip_header_proxy_authenticate_t *proxy_authenticate,
                                                      const belle_sip_header_proxy_authenticate_t *orig) {
}

belle_sip_error_code belle_sip_header_proxy_authenticate_marshal(
    belle_sip_header_proxy_authenticate_t *proxy_authenticate, char *buff, size_t buff_size, size_t *offset) {
	return belle_sip_header_www_authenticate_marshal(&proxy_authenticate->www_authenticate, buff, buff_size, offset);
}

BELLE_SIP_NEW_HEADER(header_proxy_authenticate, header_www_authenticate, BELLE_SIP_PROXY_AUTHENTICATE);
BELLE_SIP_PARSE_WITH_CONTEXT(header_proxy_authenticate);

/**************************
 * max forwards header object inherit from header
 ***************************/
struct _belle_sip_header_max_forwards {
	belle_sip_header_t header;
	int max_forwards;
};

static void belle_sip_header_max_forwards_destroy(belle_sip_header_max_forwards_t *max_forwards) {
}

static void belle_sip_header_max_forwards_clone(belle_sip_header_max_forwards_t *max_forwards,
                                                const belle_sip_header_max_forwards_t *orig) {
	max_forwards->max_forwards = orig->max_forwards;
}

belle_sip_error_code belle_sip_header_max_forwards_marshal(belle_sip_header_max_forwards_t *max_forwards,
                                                           char *buff,
                                                           size_t buff_size,
                                                           size_t *offset) {
	belle_sip_error_code error = belle_sip_header_marshal(BELLE_SIP_HEADER(max_forwards), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_snprintf(buff, buff_size, offset, "%i", max_forwards->max_forwards);
	if (error != BELLE_SIP_OK) return error;
	return error;
}

BELLE_SIP_NEW_HEADER(header_max_forwards, header, "Max-Forwards");
BELLE_SIP_PARSE_FULL(header_max_forwards);
GET_SET_INT(belle_sip_header_max_forwards, max_forwards, int);

int belle_sip_header_max_forwards_decrement_max_forwards(belle_sip_header_max_forwards_t *max_forwards) {
	return max_forwards->max_forwards--;
}
belle_sip_header_max_forwards_t *belle_sip_header_max_forwards_create(int value) {
	belle_sip_header_max_forwards_t *max_forwards = belle_sip_header_max_forwards_new();
	max_forwards->max_forwards = value;
	return max_forwards;
}

/**************************
 * Subscription state header object inherits from parameters
 ***************************/
struct _belle_sip_header_subscription_state {
	belle_sip_parameters_t parameters;
	const char *state;
};

static void belle_sip_header_subscription_state_destroy(belle_sip_header_subscription_state_t *subscription_state) {
	DESTROY_STRING(subscription_state, state);
}

static void belle_sip_header_subscription_state_clone(belle_sip_header_subscription_state_t *subscription_state,
                                                      const belle_sip_header_subscription_state_t *orig){
    CLONE_STRING(belle_sip_header_subscription_state, state, subscription_state, orig)}

belle_sip_error_code belle_sip_header_subscription_state_marshal(
    belle_sip_header_subscription_state_t *subscription_state, char *buff, size_t buff_size, size_t *offset) {
	belle_sip_error_code error =
	    belle_sip_header_marshal(BELLE_SIP_HEADER(subscription_state), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_snprintf(buff, buff_size, offset, "%s", subscription_state->state);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_parameters_marshal(BELLE_SIP_PARAMETERS(subscription_state), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	return error;
}

BELLE_SIP_NEW_HEADER(header_subscription_state, parameters, BELLE_SIP_SUBSCRIPTION_STATE);
BELLE_SIP_PARSE_FULL(header_subscription_state);
GET_SET_STRING(belle_sip_header_subscription_state, state);
GET_SET_STRING_PARAM(belle_sip_header_subscription_state, reason);
GET_SET_INT_PARAM2(belle_sip_header_subscription_state, retry - after, int, retry_after);
GET_SET_INT_PARAM(belle_sip_header_subscription_state, expires, int);

belle_sip_header_subscription_state_t *belle_sip_header_subscription_state_create(const char *subscription_state,
                                                                                  int expires) {
	belle_sip_header_subscription_state_t *sub_state = belle_sip_header_subscription_state_new();
	belle_sip_header_subscription_state_set_state(sub_state, subscription_state);
	belle_sip_header_subscription_state_set_expires(sub_state, expires);
	return sub_state;
}

#define HEADER_TO_LIKE_IMPL(name, header_name)                                                                         \
	struct _belle_sip_header_##name {                                                                                  \
		belle_sip_header_address_t address;                                                                            \
	};                                                                                                                 \
                                                                                                                       \
	static void belle_sip_header_##name##_destroy(belle_sip_header_##name##_t *obj) {                                  \
	}                                                                                                                  \
	void belle_sip_header_##name##_clone(belle_sip_header_##name##_t *contact,                                         \
	                                     const belle_sip_header_##name##_t *orig) {                                    \
	}                                                                                                                  \
	belle_sip_error_code belle_sip_header_##name##_marshal(belle_sip_header_##name##_t *name, char *buff,              \
	                                                       size_t buff_size, size_t *offset) {                         \
		BELLE_SIP_FROM_LIKE_MARSHAL(name, FALSE);                                                                      \
	}                                                                                                                  \
	BELLE_SIP_NEW_HEADER(header_##name, header_address, header_name)                                                   \
	BELLE_SIP_PARSE_HEADER_WITH_URI_CHECK(header_##name)                                                               \
	belle_sip_header_##name##_t *belle_sip_header_##name##_create(const belle_sip_header_address_t *address) {         \
		belle_sip_header_##name##_t *header = belle_sip_header_##name##_new();                                         \
		_belle_sip_object_copy((belle_sip_object_t *)header, (belle_sip_object_t *)address);                           \
		belle_sip_header_set_next(BELLE_SIP_HEADER(header), NULL); /*make sure only one header is kept*/               \
		belle_sip_header_set_name(BELLE_SIP_HEADER(header), header_name);                                              \
		return header;                                                                                                 \
	}

/**************************
 * Refer-To header object inherits from header_address
 ***************************/
HEADER_TO_LIKE_IMPL(refer_to, BELLE_SIP_REFER_TO);

/**************************
 * Referred-By header object inherits from header_address
 ***************************/
HEADER_TO_LIKE_IMPL(referred_by, BELLE_SIP_REFERRED_BY);

/**************************
 * Replaces header object inherits from parameters
 ***************************/
struct _belle_sip_header_replaces {
	belle_sip_parameters_t parameters;
	char *call_id;
};

static void belle_sip_header_replaces_destroy(belle_sip_header_replaces_t *replaces) {
	DESTROY_STRING(replaces, call_id);
}

static void belle_sip_header_replaces_clone(belle_sip_header_replaces_t *replaces,
                                            const belle_sip_header_replaces_t *orig){
    CLONE_STRING(belle_sip_header_replaces, call_id, replaces, orig)}

belle_sip_error_code belle_sip_header_replaces_marshal(belle_sip_header_replaces_t *replaces,
                                                       char *buff,
                                                       size_t buff_size,
                                                       size_t *offset) {
	belle_sip_error_code error = belle_sip_header_marshal(BELLE_SIP_HEADER(replaces), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_snprintf(buff, buff_size, offset, "%s", replaces->call_id);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_parameters_marshal(BELLE_SIP_PARAMETERS(replaces), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	return error;
}

BELLE_SIP_NEW_HEADER(header_replaces, parameters, BELLE_SIP_REPLACES);
BELLE_SIP_PARSE_FULL(header_replaces);

GET_SET_STRING(belle_sip_header_replaces, call_id);
// clang-format off
GET_SET_STRING_PARAM2(belle_sip_header_replaces, to-tag, to_tag);
GET_SET_STRING_PARAM2(belle_sip_header_replaces, from-tag, from_tag);
// clang-format on

static void escaped_to_ascii(const char *a, char *b, size_t n) {
	size_t index_a = 0, index_b = 0;

	while (a[index_a] != '\0' && index_a < n)
		index_a += belle_sip_get_char(a + index_a, b + index_b++);
}

#define REPLACES_PREF_OFFSET (strlen(BELLE_SIP_REPLACES) + 2)
belle_sip_header_replaces_t *belle_sip_header_replaces_create2(const char *escaped_replace) {
	belle_sip_header_replaces_t *replaces;
	size_t len = strlen(escaped_replace);
	char *out = reinterpret_cast<char *>(belle_sip_malloc0(REPLACES_PREF_OFFSET + len + 1));
	strcpy(out, BELLE_SIP_REPLACES ": ");
	escaped_to_ascii(escaped_replace, out + REPLACES_PREF_OFFSET, len);
	/*now we can parse*/
	replaces = belle_sip_header_replaces_parse(out);
	belle_sip_free(out);
	return replaces;
}

char *belle_sip_header_replaces_value_to_escaped_string(const belle_sip_header_replaces_t *replaces) {
	char buff[BELLE_SIP_MAX_TO_STRING_SIZE];
	size_t buff_size = sizeof(buff);
	size_t offset = 0;
	belle_sip_error_code error = BELLE_SIP_OK;
	/*first, marshall callid/from/to tags*/
	error = belle_sip_snprintf(buff, buff_size, &offset, "%s", replaces->call_id);
	if (error != BELLE_SIP_OK) return NULL;
	error = belle_sip_parameters_marshal(BELLE_SIP_PARAMETERS(replaces), buff, buff_size, &offset);
	if (error != BELLE_SIP_OK) return NULL;
	buff[offset] = '\0';
	return strdup(buff);
}

belle_sip_header_replaces_t *
belle_sip_header_replaces_create(const char *call_id, const char *from_tag, const char *to_tag) {
	belle_sip_header_replaces_t *replaces = belle_sip_header_replaces_new();
	belle_sip_header_replaces_set_call_id(replaces, call_id);
	belle_sip_header_replaces_set_from_tag(replaces, from_tag);
	belle_sip_header_replaces_set_to_tag(replaces, to_tag);
	return replaces;
}

/******************************
 * Date header inherits from header
 ******************************/
struct belle_sip_header_date {
	belle_sip_header_t base;
	char *date;
};

static void belle_sip_header_date_destroy(belle_sip_header_date_t *obj) {
	DESTROY_STRING(obj, date);
}

static void belle_sip_header_date_clone(belle_sip_header_date_t *obj, const belle_sip_header_date_t *orig) {
	CLONE_STRING(belle_sip_header_date, date, obj, orig);
}

belle_sip_error_code
belle_sip_header_date_marshal(belle_sip_header_date_t *obj, char *buff, size_t buff_size, size_t *offset) {
	belle_sip_error_code error = belle_sip_header_marshal(BELLE_SIP_HEADER(obj), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_snprintf(buff, buff_size, offset, "%s", obj->date);
	if (error != BELLE_SIP_OK) return error;
	return error;
}

BELLE_SIP_NEW_HEADER(header_date, header, BELLE_SIP_DATE);
BELLE_SIP_PARSE_FULL(header_date);

BELLESIP_EXPORT belle_sip_header_date_t *belle_sip_header_date_create_from_time(const time_t *utc_time) {
	belle_sip_header_date_t *obj = belle_sip_header_date_new();
	belle_sip_header_date_set_time(obj, utc_time);
	return obj;
}

static const char *days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
static const char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

BELLESIP_EXPORT time_t belle_sip_header_date_get_time(belle_sip_header_date_t *obj) {
	struct tm ret = {0};
	char tmp1[4] = {0};
	char tmp2[17] = {0};
	int i, j;
	time_t seconds;

	/* time headers are in GMT as spec says */
	sscanf(obj->date, "%3c,%d %16s %d %d:%d:%d", tmp1, &ret.tm_mday, tmp2, &ret.tm_year, &ret.tm_hour, &ret.tm_min,
	       &ret.tm_sec);
	ret.tm_year -= 1900;
	for (i = 0; i < 7; i++) {
		if (strcmp(tmp1, days[i]) == 0) {
			ret.tm_wday = i;
			for (j = 0; j < 12; j++) {
				if (strcmp(tmp2, months[j]) == 0) {
					ret.tm_mon = j;
					goto success;
				}
			}
		}
	}
	belle_sip_warning("Failed to parse date %s", obj->date);
	return (time_t)-1;
success:
	ret.tm_isdst = 0;

	if (seconds == (time_t)-1) {
		belle_sip_error("timegm() failed: %s", strerror(errno));
		return (time_t)-1;
	}
	return seconds;
}

BELLESIP_EXPORT void belle_sip_header_date_set_time(belle_sip_header_date_t *obj, const time_t *utc_time) {

	struct tm *ret;
#ifndef _WIN32
	struct tm gmt;
	ret = gmtime_r(utc_time, &gmt);
#else
	ret = gmtime(utc_time);
#endif
	/*cannot use strftime because it is locale dependant*/
	if (obj->date) {
		belle_sip_free(obj->date);
	}

	/*SIP-date      =  rfc1123-date
	rfc1123-date  =  wkday "," SP date1 SP time SP "GMT"
	date1         =  2DIGIT SP month SP 4DIGIT
	                 ; day month year (e.g., 02 Jun 1982)
	time          =  2DIGIT ":" 2DIGIT ":" 2DIGIT
	                 ; 00:00:00 - 23:59:59
	wkday         =  "Mon" / "Tue" / "Wed"
	                 / "Thu" / "Fri" / "Sat" / "Sun"
	month         =  "Jan" / "Feb" / "Mar" / "Apr"
	                 / "May" / "Jun" / "Jul" / "Aug"
	                 / "Sep" / "Oct" / "Nov" / "Dec"
	*/
	obj->date =
	    belle_sip_strdup_printf("%s, %02i %s %04i %02i:%02i:%02i GMT", days[ret->tm_wday], ret->tm_mday,
	                            months[ret->tm_mon], 1900 + ret->tm_year, ret->tm_hour, ret->tm_min, ret->tm_sec);
}

GET_SET_STRING(belle_sip_header_date, date);

/************************
 * header_p_prefered_identity
 ***********************/
struct _belle_sip_header_p_preferred_identity {
	belle_sip_header_address_t address;
};

void belle_sip_header_p_preferred_identity_destroy(belle_sip_header_p_preferred_identity_t *p_preferred_identity) {
}

void belle_sip_header_p_preferred_identity_clone(belle_sip_header_p_preferred_identity_t *p_preferred_identity,
                                                 const belle_sip_header_p_preferred_identity_t *orig) {
}
belle_sip_error_code belle_sip_header_p_preferred_identity_marshal(
    belle_sip_header_p_preferred_identity_t *p_preferred_identity, char *buff, size_t buff_size, size_t *offset) {
	belle_sip_error_code error =
	    belle_sip_header_marshal(BELLE_SIP_HEADER(p_preferred_identity), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_header_address_marshal(&p_preferred_identity->address, buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	return error;
}
BELLE_SIP_NEW_HEADER(header_p_preferred_identity, header_address, BELLE_SIP_P_PREFERRED_IDENTITY);
BELLE_SIP_PARSE_HEADER_WITH_URI_CHECK(header_p_preferred_identity);

belle_sip_header_p_preferred_identity_t *
belle_sip_header_p_preferred_identity_create(const belle_sip_header_address_t *p_preferred_identity) {
	belle_sip_header_p_preferred_identity_t *header = belle_sip_header_p_preferred_identity_new();
	_belle_sip_object_copy(BELLE_SIP_OBJECT(header), BELLE_SIP_OBJECT(p_preferred_identity));
	belle_sip_header_set_next(BELLE_SIP_HEADER(header), NULL); /*make sure only one header is kept*/
	belle_sip_header_set_name(BELLE_SIP_HEADER(header), BELLE_SIP_P_PREFERRED_IDENTITY); /*restaure header name*/
	return header;
}

#define PRIVACY_LIKE_HEADER(header_name, string_name, separator)                                                       \
	struct _belle_sip_header_##header_name {                                                                           \
		belle_sip_header_t header;                                                                                     \
		belle_sip_list_t *header_name;                                                                                 \
	};                                                                                                                 \
                                                                                                                       \
	static void belle_sip_header_##header_name##_destroy(belle_sip_header_##header_name##_t *p) {                      \
		belle_sip_header_##header_name##_set_##header_name(p, NULL);                                                   \
	}                                                                                                                  \
                                                                                                                       \
	static void belle_sip_header_##header_name##_clone(belle_sip_header_##header_name##_t *p,                          \
	                                                   const belle_sip_header_##header_name##_t *orig) {               \
		belle_sip_list_t *list = orig->header_name;                                                                    \
		for (; list != NULL; list = list->next) {                                                                      \
			belle_sip_header_##header_name##_add_##header_name(p, (const char *)list->data);                           \
		}                                                                                                              \
	}                                                                                                                  \
                                                                                                                       \
	belle_sip_error_code belle_sip_header_##header_name##_marshal(belle_sip_header_##header_name##_t *p, char *buff,   \
	                                                              size_t buff_size, size_t *offset) {                  \
		belle_sip_error_code error = BELLE_SIP_OK;                                                                     \
		belle_sip_list_t *list = p->header_name;                                                                       \
		error = belle_sip_header_marshal(BELLE_SIP_HEADER(p), buff, buff_size, offset);                                \
		if (error != BELLE_SIP_OK) return error;                                                                       \
		for (; list != NULL; list = list->next) {                                                                      \
			error = belle_sip_snprintf(buff, buff_size, offset, list == p->header_name ? "%s" : separator " %s",       \
			                           (const char *)list->data);                                                      \
			if (error != BELLE_SIP_OK) return error;                                                                   \
		}                                                                                                              \
		return error;                                                                                                  \
	}                                                                                                                  \
                                                                                                                       \
	BELLE_SIP_NEW_HEADER(header_##header_name, header, string_name);                                                   \
	BELLE_SIP_PARSE_FULL(header_##header_name);                                                                        \
	belle_sip_list_t *belle_sip_header_##header_name##_get_##header_name(                                              \
	    const belle_sip_header_##header_name##_t *p) {                                                                 \
		return p->header_name;                                                                                         \
	}                                                                                                                  \
	SET_ADD_STRING_LIST(belle_sip_header_##header_name, header_name);                                                  \
                                                                                                                       \
	belle_sip_header_##header_name##_t *belle_sip_header_##header_name##_create(const char *header_name) {             \
		belle_sip_header_##header_name##_t *header = belle_sip_header_##header_name##_new();                           \
		belle_sip_header_##header_name##_add_##header_name(header, header_name);                                       \
		return header;                                                                                                 \
	}

/******************************
 * Privacy header inherits from header
 ******************************/
PRIVACY_LIKE_HEADER(privacy, BELLE_SIP_PRIVACY, ";");

/**************************
 * Event header object inherits from parameters
 ***************************/
struct _belle_sip_header_event {
	belle_sip_parameters_t parameters;
	const char *package_name;
};

static void belle_sip_header_event_destroy(belle_sip_header_event_t *event) {
	DESTROY_STRING(event, package_name);
}

static void belle_sip_header_event_clone(belle_sip_header_event_t *event, const belle_sip_header_event_t *orig){
    CLONE_STRING(belle_sip_header_event, package_name, event, orig)}

belle_sip_error_code
    belle_sip_header_event_marshal(belle_sip_header_event_t *event, char *buff, size_t buff_size, size_t *offset) {
	belle_sip_error_code error = belle_sip_header_marshal(BELLE_SIP_HEADER(event), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_snprintf(buff, buff_size, offset, "%s", event->package_name);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_parameters_marshal(BELLE_SIP_PARAMETERS(event), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	return error;
}

BELLE_SIP_NEW_HEADER(header_event, parameters, BELLE_SIP_EVENT);
BELLE_SIP_PARSE_FULL(header_event);
GET_SET_STRING(belle_sip_header_event, package_name);
GET_SET_STRING_PARAM(belle_sip_header_event, id);

belle_sip_header_event_t *belle_sip_header_event_create(const char *package_name) {
	belle_sip_header_event_t *event = belle_sip_header_event_new();
	belle_sip_header_event_set_package_name(event, package_name);
	return event;
}

/******************************
 * Supported header inherits from header
 ******************************/
PRIVACY_LIKE_HEADER(supported, BELLE_SIP_SUPPORTED, ",");

int belle_sip_header_supported_contains_tag(const belle_sip_header_supported_t *supported, const char *tag) {
	belle_sip_list_t *list = belle_sip_header_supported_get_supported(supported);

	while (list) {
		if (strcmp(reinterpret_cast<char *>(list->data), tag) == 0) return TRUE;
		list = list->next;
	}

	return FALSE;
}

/******************************
 * Require header inherits from header
 ******************************/
PRIVACY_LIKE_HEADER(require, BELLE_SIP_REQUIRE, ",");

int belle_sip_header_require_contains_tag(const belle_sip_header_require_t *require, const char *tag) {
	const bctbx_list_t *elem;
	for (elem = require->require; elem != NULL; elem = elem->next) {
		if (strcmp((const char *)elem->data, tag) == 0) return TRUE;
	}
	return FALSE;
}

/******************************
 * Content-Disposition header inherits from parameters
 ******************************/
struct _belle_sip_header_content_disposition {
	belle_sip_parameters_t parameters;
	const char *content_disposition;
};

static void belle_sip_header_content_disposition_destroy(belle_sip_header_content_disposition_t *content_disposition) {
	DESTROY_STRING(content_disposition, content_disposition);
}

static void belle_sip_header_content_disposition_clone(belle_sip_header_content_disposition_t *content_disposition,
                                                       const belle_sip_header_content_disposition_t *orig){
    CLONE_STRING(belle_sip_header_content_disposition, content_disposition, content_disposition, orig)}

belle_sip_error_code belle_sip_header_content_disposition_marshal(
    belle_sip_header_content_disposition_t *content_disposition, char *buff, size_t buff_size, size_t *offset) {
	belle_sip_error_code error =
	    belle_sip_header_marshal(BELLE_SIP_HEADER(content_disposition), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_snprintf(buff, buff_size, offset, "%s", content_disposition->content_disposition);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_parameters_marshal(BELLE_SIP_PARAMETERS(content_disposition), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	return error;
}

BELLE_SIP_NEW_HEADER(header_content_disposition, parameters, BELLE_SIP_CONTENT_DISPOSITION);
BELLE_SIP_PARSE_FULL(header_content_disposition);
GET_SET_STRING(belle_sip_header_content_disposition, content_disposition);

belle_sip_header_content_disposition_t *belle_sip_header_content_disposition_create(const char *value) {
	belle_sip_header_content_disposition_t *header = belle_sip_header_content_disposition_new();
	belle_sip_header_content_disposition_set_content_disposition(header, value);
	return header;
}

/******************************
 * Accept header inherits from parameters
 ******************************/
struct _belle_sip_header_accept {
	belle_sip_parameters_t params_list;
	const char *type;
	const char *subtype;
};

static void belle_sip_header_accept_destroy(belle_sip_header_accept_t *accept) {
	if (accept->type) belle_sip_free((void *)accept->type);
	if (accept->subtype) belle_sip_free((void *)accept->subtype);
}

static void belle_sip_header_accept_clone(belle_sip_header_accept_t *accept, const belle_sip_header_accept_t *orig) {
	CLONE_STRING(belle_sip_header_accept, type, accept, orig);
	CLONE_STRING(belle_sip_header_accept, subtype, accept, orig);
}

belle_sip_error_code
belle_sip_header_accept_marshal(belle_sip_header_accept_t *accept, char *buff, size_t buff_size, size_t *offset) {
	belle_sip_error_code error = belle_sip_header_marshal(BELLE_SIP_HEADER(accept), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_snprintf(buff, buff_size, offset, "%s/%s", accept->type, accept->subtype);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_parameters_marshal(&accept->params_list, buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	return error;
}

BELLE_SIP_NEW_HEADER(header_accept, parameters, BELLE_SIP_ACCEPT);
BELLE_SIP_PARSE_WITH_CONTEXT(header_accept);

belle_sip_header_accept_t *belle_sip_header_accept_create(const char *type, const char *sub_type) {
	belle_sip_header_accept_t *header = belle_sip_header_accept_new();
	belle_sip_header_accept_set_type(header, type);
	belle_sip_header_accept_set_subtype(header, sub_type);
	return header;
}

GET_SET_STRING(belle_sip_header_accept, type);
GET_SET_STRING(belle_sip_header_accept, subtype);

/******************************
 * Reason header object inherits from parameters
 ******************************/
struct _belle_sip_header_reason {
	belle_sip_parameters_t params_list;
	const char *protocol;
	const char *unquoted_text;
};

static void belle_sip_header_reason_destroy(belle_sip_header_reason_t *reason) {
	DESTROY_STRING(reason, protocol);
	DESTROY_STRING(reason, unquoted_text);
}

static void belle_sip_header_reason_clone(belle_sip_header_reason_t *reason, const belle_sip_header_reason_t *orig){
    CLONE_STRING(belle_sip_header_reason, protocol, reason, orig)}

belle_sip_error_code
    belle_sip_header_reason_marshal(belle_sip_header_reason_t *reason, char *buff, size_t buff_size, size_t *offset) {
	belle_sip_error_code error = belle_sip_header_marshal(BELLE_SIP_HEADER(reason), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_snprintf(buff, buff_size, offset, "%s ", reason->protocol);
	if (error != BELLE_SIP_OK) return error;
	error = belle_sip_parameters_marshal(BELLE_SIP_PARAMETERS(reason), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;
	if (reason->unquoted_text)
		error = belle_sip_snprintf(buff, buff_size, offset, "; text=\"%s\"", reason->unquoted_text);
	return error;
}

GET_SET_STRING(belle_sip_header_reason, unquoted_text);

void belle_sip_header_reason_set_text(belle_sip_header_reason_t *reason, const char *text) {
	belle_sip_parameters_remove_parameter(BELLE_SIP_PARAMETERS(reason), "text"); /*just in case*/
	belle_sip_header_reason_set_unquoted_text((belle_sip_header_reason_t *)reason, text);
}
BELLESIP_EXPORT const char *belle_sip_header_reason_get_text(const belle_sip_header_reason_t *reason) {
	if (!reason->unquoted_text) {
		/*try from params*/
		const char *quoted = belle_sip_parameters_get_parameter(BELLE_SIP_PARAMETERS(reason), "text");
		if (quoted) {
			char *unquoted = _belle_sip_str_dup_and_unquote_string(quoted);
			belle_sip_header_reason_set_unquoted_text((belle_sip_header_reason_t *)reason,
			                                          unquoted); /*change internal param, ,even if reason is const*/
			belle_sip_parameters_remove_parameter(BELLE_SIP_PARAMETERS(reason), "text");
			belle_sip_free(unquoted);
		}
	}
	return reason->unquoted_text;
}

GET_SET_STRING(belle_sip_header_reason, protocol);

GET_SET_INT_PARAM(belle_sip_header_reason, cause, int);
BELLE_SIP_PARSE_WITH_CONTEXT(header_reason);
BELLE_SIP_NEW_HEADER(header_reason, parameters, BELLE_SIP_REASON);

/******************************
 * AuthenticationInfo header inherits from header
 ******************************/

struct _belle_sip_header_authentication_info {
	belle_sip_header_t header;
	const char *rsp_auth;
	const char *cnonce;
	int nonce_count;
	const char *qop;
	const char *next_nonce;
};

static void belle_sip_header_authentication_info_destroy(belle_sip_header_authentication_info_t *authentication_info) {
	DESTROY_STRING(authentication_info, rsp_auth);
	DESTROY_STRING(authentication_info, cnonce);
	DESTROY_STRING(authentication_info, qop);
	DESTROY_STRING(authentication_info, next_nonce);
}

static void belle_sip_header_authentication_info_clone(belle_sip_header_authentication_info_t *authentication_info,
                                                       const belle_sip_header_authentication_info_t *orig){
    CLONE_STRING(belle_sip_header_authentication_info, rsp_auth, authentication_info, orig)
        CLONE_STRING(belle_sip_header_authentication_info, cnonce, authentication_info, orig)
            CLONE_STRING(belle_sip_header_authentication_info, qop, authentication_info, orig)
                CLONE_STRING(belle_sip_header_authentication_info, next_nonce, authentication_info, orig)}

belle_sip_error_code belle_sip_header_authentication_info_marshal(
    belle_sip_header_authentication_info_t *authentication_info, char *buff, size_t buff_size, size_t *offset) {
	std::string border = "";
	belle_sip_error_code error =
	    belle_sip_header_marshal(BELLE_SIP_HEADER(authentication_info), buff, buff_size, offset);
	if (error != BELLE_SIP_OK) return error;

	if (authentication_info->rsp_auth) {
		error = belle_sip_snprintf(buff, buff_size, offset, "%srspauth=\"%s\"", border.c_str(),
		                           authentication_info->rsp_auth);
		border = ", ";
	}
	if (error != BELLE_SIP_OK) return error;

	if (authentication_info->cnonce) {
		error =
		    belle_sip_snprintf(buff, buff_size, offset, "%scnonce=\"%s\"", border.c_str(), authentication_info->cnonce);
		border = ", ";
	}
	if (error != BELLE_SIP_OK) return error;

	if (authentication_info->nonce_count >= 0) {
		error =
		    belle_sip_snprintf(buff, buff_size, offset, "%snc=%08x", border.c_str(), authentication_info->nonce_count);
		border = ", ";
	}
	if (error != BELLE_SIP_OK) return error;

	if (authentication_info->qop) {
		error = belle_sip_snprintf(buff, buff_size, offset, "%sqop=%s", border.c_str(), authentication_info->qop);
		border = ", ";
	}
	if (error != BELLE_SIP_OK) return error;

	if (authentication_info->next_nonce) {
		error = belle_sip_snprintf(buff, buff_size, offset, "%snextnonce=\"%s\"", border.c_str(),
		                           authentication_info->next_nonce);
	}
	return error;
}
void belle_sip_header_authentication_info_init(belle_sip_header_authentication_info_t *header_authentication) {
	header_authentication->nonce_count = -1;
}
BELLE_SIP_NEW_HEADER_INIT(header_authentication_info,
                          header,
                          BELLE_SIP_AUTHENTICATION_INFO,
                          header_authentication_info);
BELLE_SIP_PARSE_FULL(header_authentication_info);
GET_SET_STRING(belle_sip_header_authentication_info, rsp_auth);
GET_SET_STRING(belle_sip_header_authentication_info, qop);
GET_SET_STRING(belle_sip_header_authentication_info, next_nonce);
GET_SET_STRING(belle_sip_header_authentication_info, cnonce);
GET_SET_INT(belle_sip_header_authentication_info, nonce_count, int);
