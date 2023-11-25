PORTNAME=	bonsai
DISTVERSION=	1.5.2
CATEGORIES=	net devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Module for handling LDAP operations in Python
WWW=		https://github.com/noirello/bonsai

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

MY_DEPENDS=	openldap26-client>=0:net/openldap26-client
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gevent>=0:devel/py-gevent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=0:www/py-tornado@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	autoplist concurrent distutils pytest
PYTEST_IGNORED_TESTS=	TornadoLDAPConnectionTest.test_connection test_abandon \
			test_acl_from_binary test_acl_to_binary \
			test_add_and_delete test_async_close_remove_pendig_ops \
			test_async_with test_binary test_bind_digest \
			test_bind_digest_with_authzid test_bind_external \
			test_bind_external_with_authzid test_bind_gssapi_kinit \
			test_bind_gssapi_with_authzid_kinit \
			test_bind_not_supported_auth test_bind_ntlm \
			test_change_attribute test_change_attribute_error \
			test_client_sizelimit_error test_close test_connect \
			test_connection test_connection_timeout \
			test_digest_auth_error test_dn_with_space \
			test_extended_dn test_fileno test_from_binary test_get \
			test_ignore_referrals test_ldap_over_tls \
			test_load_resource test_modify_and_rename \
			test_modify_referrals test_obj_err test_open \
			test_paged_search test_paged_search_with_auto_acq \
			test_password_expire test_password_lockout \
			test_password_modify test_pool_close test_pool_get_put \
			test_pool_spawn test_ppolicy test_put test_put_closed \
			test_raw_attributes test_recursive_delete \
			test_referral_chasing test_rename test_rename_error \
			test_rename_with_old_rdn test_rootdse test_search \
			test_search_timeout test_server_sizelimit_error \
			test_set_async_connect test_set_sasl_sec_properties \
			test_simple_auth_error test_sort_order test_spawn \
			test_special_char test_starttls test_sync_operations \
			test_threaded_pool_block test_threaded_pool_close \
			test_threaded_pool_raise test_tls_timeout \
			test_to_binary test_unicode test_url_attribute \
			test_vlv_attrvalue test_vlv_offset \
			test_vlv_without_sort_order test_whoami \
			test_wrong_add_param test_wrong_conn_param \
			test_wrong_delete_param test_wrong_search_param

OPTIONS_DEFINE=	GEVENT TORNADO TRIO

GEVENT_DESC=		Support for async IO using gevent
GEVENT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gevent>=0:devel/py-gevent@${PY_FLAVOR}
TORNADO_DESC=		Support for async IO using tornado
TORNADO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tornado>=0:www/py-tornado@${PY_FLAVOR}
TRIO_DESC=		Support for async IO using trio
TRIO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}trio>=0:net/py-trio@${PY_FLAVOR}

.include <bsd.port.mk>
