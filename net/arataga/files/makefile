LOCALBASE?=	/usr/local
CXXFLAGS+=	-std=c++17 -Wall -Wextra
CPPFLAGS+=	-I. -I.. -I$(LOCALBASE)/include -DSPDLOG_FMT_EXTERNAL

LDFLAGS+=	-pthread $(LOCALBASE)/lib/libso.$(SO5_LIBVER).so \
		-L$(LOCALBASE)/lib -lfmt -lhttp_parser

CCACHE?=	$(shell command -v ccache)

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

connection_handlers_OBJ=\
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
		user_list_auth_data.o $(connection_handlers_OBJ) \
		$(misc_OBJS) main.o

%.o: %.cpp
	$(CCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<

arataga: $(all_OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LIBS)

all: arataga

.PHONY: all install
