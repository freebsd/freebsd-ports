# New ports collection makefile for:	ucd-snmp
# Date created:				26 June 1996
# Whom:					gpalmer
#
# $FreeBSD$
#

PORTNAME=	net-snmp
PORTVERSION=	5.0.6
CATEGORIES=	net ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://sunsite.cnlab-switch.ch/mirror/ucd-snmp/ \
		ftp://ftp.win.ne.jp/pub/network/snmp/ucd-snmp/
MASTER_SITE_SUBDIR= net-snmp

MAINTAINER=	kuriyama@FreeBSD.org

USE_REINPLACE=	yes
USE_AUTOCONF_VER=213
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
NO_LATEST_LINK=	yes

CONFIGURE_ARGS+= --enable-shared --with-mib-modules="host ucd-snmp/diskio" \
		 --with-default-snmp-version="${DEFAULT_SNMP_VERSION}" \
		 --with-sys-contact="${NET_SNMP_SYS_CONTACT}" \
		 --with-sys-location="${NET_SNMP_SYS_LOCATION}" \
		 --with-logfile="${NET_SNMP_LOGFILE}" \
		 --with-persistent-directory="${NET_SNMP_PERSISTENTDIR}" \
		 --with-gnu-ld --with-libwrap --with-libs="-lkvm -ldevstat"
.if defined(BATCH)
CONFIGURE_ARGS+= --with-defaults --with-sys-contact=nobody@no.where
.else
IS_INTERACTIVE= yes
.endif

DEFAULT_SNMP_VERSION?=	3
NET_SNMP_SYS_CONTACT?=	nobody@no.where
NET_SNMP_SYS_LOCATION?=	
NET_SNMP_LOGFILE?=	/var/log/snmpd.log
NET_SNMP_PERSISTENTDIR?=/var/net-snmp

MAN1=		mib2c.1 \
		snmpbulkget.1 snmpbulkwalk.1 snmpcmd.1 snmpconf.1 snmpd.1 \
		snmpdelta.1 snmpdf.1 snmpget.1 snmpgetnext.1 snmpinform.1 \
		snmpnetstat.1 snmpset.1 snmpstatus.1 snmptable.1 snmptest.1 \
		snmptranslate.1 snmptrap.1 snmpusm.1 snmpwalk.1
MAN3=		add_mibdir.3 add_module_replacement.3 default_store.3 \
		get_module_node.3 init_mib.3 init_mib_internals.3 mib_api.3 \
		netsnmp_agent.3 netsnmp_bulk_to_next.3 netsnmp_debug.3 \
		netsnmp_example_scalar_int.3 netsnmp_handler.3 \
		netsnmp_instance.3 netsnmp_mib_handler_methods.3 \
		netsnmp_multiplexer.3 netsnmp_old_api.3 netsnmp_read_only.3 \
		netsnmp_scalar.3 \
		netsnmp_serialize.3 netsnmp_table.3 netsnmp_table_array.3 \
		netsnmp_table_data.3 netsnmp_table_dataset.3 \
		netsnmp_table_iterator.3 netsnmp_todo.3 netsnmp_watcher.3 \
		print_description.3 print_mib.3 print_objid.3 print_value.3 \
		print_variable.3 read_all_mibs.3 read_config.3 read_mib.3 \
		read_module.3 read_module_node.3 read_objid.3 shutdown_mib.3 \
		snmp_agent_api.3 snmp_alarm.3 snmp_api.3 \
		snmp_api_errstring.3 snmp_close.3 \
		snmp_error.3 snmp_free_pdu.3 snmp_open.3 snmp_perror.3 \
		snmp_read.3 snmp_select_info.3 \
		snmp_send.3 snmp_sess_api.3 snmp_sess_async_send.3 \
		snmp_sess_close.3 snmp_sess_error.3 snmp_sess_init.3 \
		snmp_sess_open.3 snmp_sess_perror.3 \
		snmp_sess_read.3 snmp_sess_select_info.3 \
		snmp_sess_send.3 snmp_sess_session.3 snmp_sess_timeout.3 \
		snmp_set_mib_warnings.3 snmp_set_save_descriptions.3 \
		snmp_timeout.3 snmp_trap_api.3
MAN5=		snmp.conf.5 snmp_config.5 snmpd.conf.5 \
		snmptrapd.conf.5 variables.5
MAN8=		snmptrapd.8
BIN=		snmpbulkwalk snmpget snmpgetnext snmpnetstat snmpset \
		snmpstatus snmptest snmptranslate snmptrap snmpwalk
SBIN=		snmpd snmptrapd

STARTUP_FILE=	${PREFIX}/etc/rc.d/snmpd.sh

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+= --enable-ipv6 \
		--with-transports="UDP UDPIPv6 TCP TCPIPv6 Unix"
.endif

SHLIB_VERSION=	5
PLIST_SUB+=	shlib=${SHLIB_VERSION}

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/aclocal.m4

pre-install:
	-@[ -f ${STARTUP_FILE} ] && \
	 (echo "Remove old ${STARTUP_FILE} before install." && exit 1)

post-install:
	@( cd ${PREFIX}/bin && ${STRIP_CMD} ${BIN} )
	@( cd ${PREFIX}/sbin && ${STRIP_CMD} ${SBIN} )
	@${FIND} ${PREFIX}/include/net-snmp ${PREFIX}/share/snmp/mibs -type f \
		| ${XARGS} ${CHMOD} 644
	@${INSTALL_SCRIPT} -m 751 ${FILESDIR}/snmpd.sh.sample ${STARTUP_FILE}
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
