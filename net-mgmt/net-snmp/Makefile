# New ports collection makefile for:	ucd-snmp
# Date created:				26 June 1996
# Whom:					gpalmer
#
# $FreeBSD$
#

PORTNAME=	snmp
PORTVERSION=	5.4.2.1
PORTREVISION=	7
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	SF/net-${PORTNAME}/net-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	net-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	An extendable SNMP implementation

OPTIONS=	IPV6 "Build with IPv6 support" on \
		MFD_REWRITES "Build with 64-bit Interface Counters" off \
		PERL "Install additional perl modules" on \
		PERL_EMBEDDED "Build embedded perl" on \
		TKMIB "Install graphical MIB browser" off \
		DUMMY "Enable dummy values as placeholders" on \
		DMALLOC "Enable dmalloc debug memory allocator" off

MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
USE_RC_SUBR=	snmpd.sh snmptrapd.sh
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
WANT_PERL=	yes

CONFIGURE_ENV+=	PERLPROG="${PERL}" PSPROG="${PS_CMD}" SED="${SED}"
CONFIGURE_ARGS+=--enable-shared --enable-internal-md5 \
		--with-mib-modules="${_NET_SNMP_MIB_MODULES}" \
		--with-default-snmp-version="${DEFAULT_SNMP_VERSION}" \
		--with-sys-contact="${NET_SNMP_SYS_CONTACT}" \
		--with-sys-location="${NET_SNMP_SYS_LOCATION}" \
		--with-logfile="${NET_SNMP_LOGFILE}" \
		--with-persistent-directory="${NET_SNMP_PERSISTENTDIR}" \
		--with-gnu-ld --with-libwrap --with-ldflags="-lm -lkvm -ldevstat"

.if defined(BATCH)
CONFIGURE_ARGS+=--with-defaults
.endif

.include <bsd.port.pre.mk>
CONFIGURE_ARGS+=	--with-openssl="${OPENSSLBASE}"

.if defined(WITH_DUMMY)
CONFIGURE_ARGS+=--with-dummy-values
.endif

.if !defined(WITH_TKMIB)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-local:Makefile.in
PLIST_SUB+=	WITH_TKMIB="@comment "
.else
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk
PLIST_SUB+=	WITH_TKMIB=""
.endif

.if defined(WITH_PERL)
USE_PERL5=	yes
CONFIGURE_ARGS+=--with-perl-modules
.if defined(WITHOUT_PERL_EMBEDDED)
CONFIGURE_ARGS+=--disable-embedded-perl
PLIST_SUB+=	WITH_PERL_EMBEDDED="@comment "
.else
CONFIGURE_ARGS+=--enable-embedded-perl
PLIST_SUB+=	WITH_PERL_EMBEDDED=""
.endif
PLIST_SUB+=	WITH_PERL=""
.else
USE_PERL5_BUILD=yes
CONFIGURE_ARGS+=--disable-embedded-perl --without-perl-modules
PLIST_SUB+=	WITH_PERL_EMBEDDED="@comment "
PLIST_SUB+=	WITH_PERL="@comment "
.endif

.if defined(WITH_DMALLOC)
LIB_DEPENDS+=	dmalloc:${PORTSDIR}/devel/dmalloc
CONFIGURE_ARGS+=--with-dmalloc=${LOCALBASE}
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=--enable-ipv6
# --with-transport="UDPIPv6 TCPIPv6" --with-modules=mibII/ipv6"
PLIST_SUB+=	WITH_IPV6=""
.else
PLIST_SUB+=	WITH_IPV6="@comment "
.endif

SHLIB_VERSION=	16
PLIST_SUB+=	SHLIB_VERSION=${SHLIB_VERSION}
SCRIPTS_SUB=	PREFIX=${PREFIX} PERL=${PERL}

DEFAULT_SNMP_VERSION?=	3
NET_SNMP_SYS_CONTACT?=	nobody@nowhere.invalid
NET_SNMP_SYS_LOCATION?=	somewhere
NET_SNMP_LOGFILE?=	/var/log/snmpd.log
NET_SNMP_PERSISTENTDIR?=/var/net-snmp
NET_SNMP_MIB_MODULES?=	${NET_SNMP_MIB_MODULE_LIST}

NET_SNMP_MIB_MODULE_LIST=host disman/event-mib smux mibII/mta_sendmail mibII/tcpTable ucd-snmp/diskio

.if ${OSVERSION} >= 700028
NET_SNMP_MIB_MODULE_LIST+=	sctp-mib
.endif

.if ${OSVERSION} >= 800000
CONFIGURE_ARGS+=	--with-libs="-lssp_nonshared"
.endif

.if defined(WITH_MFD_REWRITES)
CONFIGURE_ARGS+=--enable-mfd-rewrites
NET_SNMP_MIB_MODULE_LIST+=	if-mib
.endif

_NET_SNMP_MIB_MODULES=
.for module1 in ${NET_SNMP_MIB_MODULE_LIST}
_module1=${module1}
_define=false
. for module2 in ${NET_SNMP_MIB_MODULES}
_module2=${module2}
.  if ${_module1} == ${_module2}
_define=true
.  endif
. endfor
. if ${_define} == true
_NET_SNMP_MIB_MODULES+=${module1}
PLIST_SUB+=	WITH_${module1:C|.*/||:U}=""
. else
PLIST_SUB+=	WITH_${module1:C|.*/||:U}="@comment "
. endif
.endfor

MAN1=		encode_keychange.1 fixproc.1 mib2c.1 mib2c-update.1 \
		net-snmp-config.1 \
		snmpbulkget.1 snmpbulkwalk.1 snmpcmd.1 snmpconf.1 \
		snmpdelta.1 snmpdf.1 snmpget.1 snmpgetnext.1 snmpinform.1 \
		snmpnetstat.1 snmpset.1 snmpstatus.1 snmptable.1 snmptest.1 \
		snmptranslate.1 snmptrap.1 snmpusm.1 snmpvacm.1 snmpwalk.1 \
		tkmib.1 traptoemail.1
MAN3=		add_mibdir.3 add_module_replacement.3 \
		config_perror.3 config_pwarn.3 \
		default_store.3 fprint_description.3 \
		fprint_objid.3 fprint_value.3 fprint_variable.3 \
		get_module_node.3 init_mib.3 init_mib_internals.3 mib_api.3 \
		netsnmp_Container_iterator.3 \
		netsnmp_agent.3 \
		netsnmp_baby_steps.3 \
		netsnmp_bulk_to_next.3 \
		netsnmp_cache_handler.3 netsnmp_container.3 \
		netsnmp_debug.3 \
		netsnmp_ds_get_boolean.3 netsnmp_ds_get_int.3 \
		netsnmp_ds_get_string.3 \
		netsnmp_ds_register_config.3 netsnmp_ds_register_premib.3 \
		netsnmp_ds_set_boolean.3 netsnmp_ds_set_int.3 \
		netsnmp_ds_set_string.3 netsnmp_ds_shutdown.3 \
		netsnmp_example_scalar_int.3 netsnmp_handler.3 \
		netsnmp_instance.3 \
		netsnmp_iterator_info_s.3 \
		netsnmp_leaf.3 netsnmp_library.3 \
		netsnmp_mib_handler_methods.3 netsnmp_mib_utilities.3 \
		netsnmp_mode_end_call.3 netsnmp_multiplexer.3 \
		netsnmp_old_api.3 netsnmp_read_only.3 \
		netsnmp_row_merge.3 \
		netsnmp_scalar.3 \
		netsnmp_scalar_group_group.3 \
		netsnmp_serialize.3 \
		netsnmp_stash_cache.3 \
		netsnmp_table.3 netsnmp_table_array.3 \
		netsnmp_table_data.3 netsnmp_table_dataset.3 \
		netsnmp_table_iterator.3 \
		netsnmp_utilities.3 \
		netsnmp_watcher.3 \
		print_description.3 print_mib.3 print_objid.3 print_value.3 \
		print_variable.3 read_all_mibs.3 \
		read_config.3 read_configs.3 read_config_print_usage.3 \
		read_mib.3 read_module.3 read_module_node.3 read_objid.3 \
		read_premib_configs.3 \
		register_app_config_handler.3 register_app_premib_handler.3 \
		register_config_handler.3 register_mib_handlers.3 \
		register_premib_handler.3 \
		send_easy_trap.3 send_trap_vars.3 send_v2trap.3 \
		shutdown_mib.3 \
		snmp_agent_api.3 \
		snmp_alarm.3 snmp_alarm_register.3 \
		snmp_alarm_register_hr.3 snmp_alarm_unregister.3 \
		snmp_api.3 snmp_api_errstring.3 snmp_close.3 \
		snmp_error.3 snmp_free_pdu.3 snmp_open.3 snmp_perror.3 \
		snmp_read.3 snmp_select_info.3 \
		snmp_send.3 snmp_sess_api.3 snmp_sess_async_send.3 \
		snmp_sess_close.3 snmp_sess_error.3 snmp_sess_init.3 \
		snmp_sess_open.3 snmp_sess_perror.3 \
		snmp_sess_read.3 snmp_sess_select_info.3 \
		snmp_sess_send.3 snmp_sess_session.3 snmp_sess_timeout.3 \
		snmp_set_mib_warnings.3 snmp_set_save_descriptions.3 \
		snmp_timeout.3 snmp_trap_api.3 \
		snprint_objid.3 snprint_value.3 snprint_variable.3 \
		sprint_realloc_objid.3 sprint_realloc_value.3 \
		sprint_realloc_variable.3 \
		unregister_app_config_handler.3 \unregister_config_handler.3

.if defined(WITH_PERL)
MAN3PERL=	NetSNMP::ASN.3 NetSNMP::OID.3 NetSNMP::agent.3 \
		NetSNMP::TrapReceiver.3 \
		NetSNMP::agent::default_store.3 \
		NetSNMP::default_store.3 \
		NetSNMP::netsnmp_request_infoPtr.3 SNMP.3
MAN3PERLPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
_MANPAGES+=	${MAN3PERL:S%^%${MAN3PERLPREFIX}/man/man3/%}
.endif

MAN5=		mib2c.conf.5 snmp.conf.5 snmp_config.5 snmpd.conf.5 \
		snmpd.examples.5 snmpd.internal.5 \
		snmptrapd.conf.5 variables.5
MAN8=		snmpd.8 snmptrapd.8

BIN_FILES=	snmpbulkwalk snmpget snmpgetnext snmpset \
		snmpstatus snmptest snmptranslate snmptrap snmpwalk
SBIN_FILES=	snmpd snmptrapd
STARTUP_DIR=	${PREFIX}/etc/rc.d
SCRIPT_FILES=	snmpcheck.def mib2c fixproc ipf-mod.pl snmpconf \
		traptoemail
.if defined(WITH_TKMIB)
SCRIPT_FILES+=	tkmib
.endif
DOC_FILES=	AGENT.txt COPYING FAQ NEWS README \
		README.agentx README.krb5 README.snmpv3 README.thread \
		agent/mibgroup/README.smux

PS_CMD?=	/bin/ps
CONFLICTS=	ucd-snmp-4.* net-snmp-5.3.*

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG}
	@${ECHO_MSG} "DEFAULT_SNMP_VERSION=\"3\"	Default version of SNMP to use."
	@${ECHO_MSG} "NET_SNMP_SYS_CONTACT=\"${NET_SNMP_SYS_CONTACT}\""
	@${ECHO_MSG} "				Default system contact."
	@${ECHO_MSG} "NET_SNMP_SYS_LOCATION=\"${NET_SNMP_SYS_LOCATION}\""
	@${ECHO_MSG} "				Default system location."
	@${ECHO_MSG} "NET_SNMP_LOGFILE=\"${NET_SNMP_LOGFILE}\""
	@${ECHO_MSG} "				Default log file location for snmpd."
	@${ECHO_MSG} "NET_SNMP_PERSISTENTDIR=\"${NET_SNMP_PERSISTENTDIR}\""
	@${ECHO_MSG} "				Default directory for persistent data storage."
	@${ECHO_MSG} "NET_SNMP_MIB_MODULES=\"${NET_SNMP_MIB_MODULE_LIST}\""
	@${ECHO_MSG} "				Optional mib modules that can be built into the"
	@${ECHO_MSG} "				agent"
	@${ECHO_MSG}

post-patch:
.for filename in ${SCRIPT_FILES}
	@${REINPLACE_CMD} ${SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/local/${filename}
.endfor
.if ${OSVERSION} >= 900007
	${REINPLACE_CMD} -e 's!utmp_p->ut_name!utmp_p->ut_user!' ${WRKSRC}/agent/mibgroup/host/hr_system.c
.endif

post-configure:
	@${FIND} ${WRKSRC} -name Makefile | \
	 ${XARGS} ${REINPLACE_CMD} -E -e '/^INSTALL[ 	]+=/s|$$| -m 755|'

post-build:
.if defined(WITH_PERL)
	${FIND} ${WRKSRC}/perl -name Makefile | \
	${XARGS} ${REINPLACE_CMD} -E -e '\
		s!^(PREFIX) = .*!\1 = ${PREFIX}!; \
		s!^(INSTALLMAN3DIR|INSTALLSITEMAN3DIR) = .*!\1 = ${MAN3PERLPREFIX}/man/man3!; \
		s!^(INSTALLSITELIB|INSTALLSITEARCH) = /usr/local/(.*)!\1 = ${PREFIX}/\2!; \
		s! doc_(perl|site|\$$\(INSTALLDIRS\))_install$$!!; \
		'
.else
	${REINPLACE_CMD} -e 's| perlinstall||' ${WRKSRC}/Makefile
.endif

post-install: strip-files install-config-files install-doc-files display-message
	${MKDIR} /var/agentx

strip-files:
	@cd ${PREFIX}/bin; ${STRIP_CMD} ${BIN_FILES}
	@cd ${PREFIX}/sbin; ${STRIP_CMD} ${SBIN_FILES}

install-config-files:
	@${INSTALL_DATA} ${WRKSRC}/EXAMPLE.conf ${DATADIR}/snmpd.conf.example

install-doc-files:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for filename in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${filename} ${DOCSDIR}
. endfor
.endif

display-message:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}

# Maintainer's note:
#   Don't forget to bump library version in these ports.
#   french/plgrenouille,graphics/hpoj,lang/php4,lang/php5,mail/cyrus-imapd22,mail/cyrus-imapd23,misc/kdeutils3,net-mgmt/braa,net-mgmt/docsis,net-mgmt/mbrowse,net-mgmt/nagios-snmp-plugins,net-mgmt/p5-SNMP-Info,net-mgmt/py-yapsnmp,net-mgmt/sdig,net-mgmt/zabbix,net/cactid,net/wireshark,net/ifstat,net/quagga,net/rtg,print/hplip,security/libfwbuilder,sysutils/apcupsd,sysutils/jailadmin,sysutils/nut

.include <bsd.port.post.mk>
