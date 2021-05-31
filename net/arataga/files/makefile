CXXFLAGS+=	-std=c++17 -Wall -Wextra
CPPFLAGS+=	-I.$(if $(findstring run_unit_tests,$(MAKECMDGOALS)),./arataga)
CPPFLAGS+=	-I.. -I$(LOCALBASE)/include -DSPDLOG_FMT_EXTERNAL
LDFLAGS+=	-L$(LOCALBASE)/lib
LIBS=		-lpthread $(LOCALBASE)/lib/libso.$(SO5_LIBVER).so \
		-lfmt -lhttp_parser

oess_OBJS=	oess_2/defs/err_code.o \
		oess_2/defs/ex.o \
		oess_2/defs/quantity.o \
		oess_2/io/binbuffer.o \
		oess_2/io/bstring_buf.o \
		oess_2/io/fixed_mem_buf.o \
		oess_2/io/stream.o \
		oess_2/stdsn/ent.o \
		oess_2/stdsn/ent_std.o \
		oess_2/stdsn/serializable.o \
		oess_2/stdsn/shptr.o \
		oess_2/stdsn/type_tag/type_tag.o

stats_OBJS=	stats/auth/pub.o \
		stats/connections/pub.o \
		stats/dns/pub.o

logging_OBJS=	logging/stats_counters.o \
		logging/wrap_logging.o

connection_handlers_OBJS=\
		acl_handler/connection_handler_ifaces.o \
		acl_handler/handlers/protocol_detection.o \
		acl_handler/handlers/data_transfer.o \
		acl_handler/handlers/socks5.o \
		acl_handler/handlers/http/basics.o \
		acl_handler/handlers/http/negative_response_sender.o \
		acl_handler/handlers/http/initial_handler.o \
		acl_handler/handlers/http/authentification_handler.o \
		acl_handler/handlers/http/dns_lookup_handler.o \
		acl_handler/handlers/http/target_connector.o \
		acl_handler/handlers/http/connect_method_handler.o \
		acl_handler/handlers/http/ordinary_method_handler.o

misc_OBJS=	admin_http_entry/pub.o \
		stats_collector/a_stats_collector.o \
		authentificator/a_authentificator.o \
		dns_resolver/interactor/a_nameserver_interactor.o \
		dns_resolver/lookup_conductor/a_conductor.o \
		dns_resolver/pub.o \
		io_thread_timer/a_timer_handler.o \
		acl_handler/bandlim_manager.o \
		acl_handler/a_handler.o \
		user_list_processor/a_processor.o \
		config_processor/a_processor.o \
		startup_manager/a_manager.o

all_OBJS=	$(oess_OBJS) $(stats_OBJS) config.o $(logging_OBJS) \
		user_list_auth_data.o $(connection_handlers_OBJS) \
		$(misc_OBJS) main.o

CCACHE?=	$(shell command -v ccache)

%.o: %.cpp
# XXX: $@ does not play well with VPATH :(
	$(CCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $(<:.cpp=.o) -c $<

arataga: $(all_OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LIBS)

all: arataga

install: arataga
	$(BSD_INSTALL_PROGRAM) $^ $(DESTDIR)$(PREFIX)/bin

UNIT_TESTS=	config_parser local_user_list_data dns_types \
		socks5_1 socks5_2 socks5_3 \
		http_1 http_2 http_3 http_4 http_5

# Tests live in (and built from) their own subdirectory, but use main
# project files as well, so use VPATH to help make(1) find them.
VPATH=		../arataga

config_parser_test_OBJS=\
		config_parser/main.o \
		config.o
config_parser_test_LIBS=	-lfmt

local_user_list_data_test_OBJS=\
		local_user_list_data/main.o \
		user_list_auth_data.o
local_user_list_data_test_LIBS=	-lfmt

dns_types_test_OBJS=\
		dns_types/main.o \
		oess_2/defs/err_code.o \
		oess_2/defs/ex.o \
		oess_2/defs/quantity.o \
		oess_2/io/binbuffer.o \
		oess_2/io/bstring_buf.o \
		oess_2/io/fixed_mem_buf.o \
		oess_2/io/stream.o
dns_types_test_LIBS=	-lfmt

# These object files are common to (shared by) SOCKS and HTTP tests.
common_test_OBJS=\
		connection_handler_simulator/impl.o \
		$(connection_handlers_OBJS) $(logging_OBJS)

socks5_1_test_OBJS=	socks5/bind_pdu/main.o $(common_test_OBJS)
socks5_1_test_LIBS=	$(LIBS)

socks5_2_test_OBJS=	socks5/command_pdu/main.o $(common_test_OBJS)
socks5_2_test_LIBS=	$(LIBS)

socks5_3_test_OBJS=	socks5/illegal_first_pdu/main.o $(common_test_OBJS)
socks5_3_test_LIBS=	$(LIBS)

socks5_4_test_OBJS=	socks5/username_password_auth/main.o $(common_test_OBJS)
socks5_4_test_LIBS=	$(LIBS)

http_1_test_OBJS=	http/auth_params/main.o $(common_test_OBJS)
http_1_test_LIBS=	$(LIBS)

http_2_test_OBJS=	http/chunked_encoding/main.o $(common_test_OBJS)
http_2_test_LIBS=	$(LIBS)

http_3_test_OBJS=	http/connect_data_transfer/main.o $(common_test_OBJS)
http_3_test_LIBS=	$(LIBS)

http_4_test_OBJS=	http/http_fields/main.o $(common_test_OBJS)
http_4_test_LIBS=	$(LIBS)

http_5_test_OBJS=	http/illegal_responses/main.o $(common_test_OBJS)
http_5_test_LIBS=	$(LIBS)

define make_test
$(1)_test: $$($(1)_test_OBJS)
# XXX: again, if object file is missing, make(1) will build it, but
# $^ will contain incorrect path if prerequisite was found via VPATH.
	$(CXX) $(LDFLAGS) -o $$@ $$(foreach o,$$^,$$(if $$(wildcard \
		$$o),$$o,$(VPATH)/$$o)) $$($(1)_test_LIBS)

run_$(1)_test: $(1)_test
# At least one test (local_user_list_data) reads configuration files
# and expects to be run from the project's top directory.
	cd .. && tests/$$<

.PHONY: run_$(1)_test
run_unit_tests: run_$(1)_test
endef

$(foreach t,$(UNIT_TESTS),$(eval $(call make_test,$(t))))

.PHONY: all install run_unit_tests
