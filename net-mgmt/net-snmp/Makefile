# Created by: gpalmer
# $FreeBSD$

PORTNAME=	snmp
PORTVERSION=	5.7.2
PORTREVISION=	3
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	SF/net-${PORTNAME}/net-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	net-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	An extendable SNMP implementation

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	IPV6 MFD_REWRITES PERL PERL_EMBEDDED PYTHON DUMMY TKMIB \
		DMALLOC MYSQL AX_SOCKONLY UNPRIVILEGED SMUX
OPTIONS_DEFAULT=IPV6 PERL PERL_EMBEDDED DUMMY SMUX

MFD_REWRITES_DESC=	Build with 64-bit Interface Counters
PERL_EMBEDDED_DESC=	Build embedded perl
DUMMY_DESC=		Enable dummy values as placeholders
TKMIB_DESC=		Install graphical MIB browser
DMALLOC_DESC=		Enable dmalloc debug memory allocator
AX_SOCKONLY_DESC=	Disable UDP/TCP transports for agentx
UNPRIVILEGED_DESC=	Allow unprivileged users to execute net-snmp
SMUX_DESC=		Build with SNMP multiplexing (SMUX) support

MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
USE_RC_SUBR=	snmpd snmptrapd
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
USES=		perl5

CONFIGURE_ENV+=	PERLPROG="${PERL}" PSPROG="${PS_CMD}" SED="${SED}"
CONFIGURE_ARGS+=--enable-shared --enable-internal-md5 \
		--with-default-snmp-version="${DEFAULT_SNMP_VERSION}" \
		--with-sys-contact="${NET_SNMP_SYS_CONTACT}" \
		--with-sys-location="${NET_SNMP_SYS_LOCATION}" \
		--with-logfile="${NET_SNMP_LOGFILE}" \
		--with-persistent-directory="${NET_SNMP_PERSISTENTDIR}" \
		--with-gnu-ld --with-libwrap --with-ldflags="-lm -lkvm -ldevstat"
SUB_FILES=	pkg-message

.if defined(BATCH)
CONFIGURE_ARGS+=--with-defaults
.endif

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
# borrowed from bsd.python.mk and adapted for our needs
PYEASYINSTALL_CMD?=		${LOCALBASE}/bin/easy_install-${PYTHON_VER}
PYEASYINSTALL_BINDIR?=		${PREFIX}/bin
PYEASYINSTALL_SITELIBDIR?=	${PYTHONPREFIX_SITELIBDIR}
PYDISTUTILS_PKGNAME?=		netsnmp-python
PYDISTUTILS_PKGVERSION?=	1.0a1
PYEASYINSTALL_INSTALLARGS?=	-q -N -S ${PYTHON_SITELIBDIR} \
				-d ${PYEASYINSTALL_SITELIBDIR} \
				-s ${PYEASYINSTALL_BINDIR} \
				${PYDISTUTILS_PKGNAME}==${PYDISTUTILS_PKGVERSION}
PYEASYUNINSTALL_UNINSTALLARGS?=	-q -N -m -S ${PYTHON_SITELIBDIR} \
				-d ${PYEASYINSTALL_SITELIBDIR} \
				-s ${PYEASYINSTALL_BINDIR} \
				${PYDISTUTILS_PKGNAME}
USE_PYTHON=	yes
RUN_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-distribute
BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-distribute
CONFIGURE_ARGS+=--with-python-modules
PLIST_SUB+=	WITH_PYTHON="" PYTHON_VER=${PYTHON_VER}
PLIST_SUB+=	PYDISTUTILS_PKGVERSION=${PYDISTUTILS_PKGVERSION}
PLIST_SUB+=	PYINSTALL="@exec ${SETENV} PYTHONPATH=${PYEASYINSTALL_SITELIBDIR} ${PYEASYINSTALL_CMD} ${PYEASYINSTALL_INSTALLARGS}"
PLIST_SUB+=	PYUNINSTALL="@unexec ${PYEASYINSTALL_CMD} ${PYEASYUNINSTALL_UNINSTALLARGS}"
.else
PLIST_SUB+=	WITH_PYTHON="@comment "
.endif

CONFIGURE_ARGS+=	--with-openssl="${OPENSSLBASE}"

.if ${PORT_OPTIONS:MDUMMY}
CONFIGURE_ARGS+=--with-dummy-values
.endif

.if ! ${PORT_OPTIONS:MTKMIB}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-local:Makefile.in
PLIST_SUB+=	WITH_TKMIB="@comment "
.else
RUN_DEPENDS+=	p5-Tk>=0:${PORTSDIR}/x11-toolkits/p5-Tk
PLIST_SUB+=	WITH_TKMIB=""
.endif

.if ${PORT_OPTIONS:MPERL}
CONFIGURE_ARGS+=--with-perl-modules
.if ! ${PORT_OPTIONS:MPERL_EMBEDDED}
CONFIGURE_ARGS+=--disable-embedded-perl
PLIST_SUB+=	WITH_PERL_EMBEDDED="@comment "
.else
CONFIGURE_ARGS+=--enable-embedded-perl
PLIST_SUB+=	WITH_PERL_EMBEDDED=""
.endif
PLIST_SUB+=	WITH_PERL=""
.else
USE_PERL5=	build
CONFIGURE_ARGS+=--disable-embedded-perl --without-perl-modules
PLIST_SUB+=	WITH_PERL_EMBEDDED="@comment "
PLIST_SUB+=	WITH_PERL="@comment "
.endif

.if ${PORT_OPTIONS:MDMALLOC}
LIB_DEPENDS+=	dmalloc:${PORTSDIR}/devel/dmalloc
CONFIGURE_ARGS+=--with-dmalloc=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=--with-mysql
CONFIGURE_ENV+=	MYSQLCONFIG=${LOCALBASE}/bin/mysql_config
.endif

.if ${PORT_OPTIONS:MAX_SOCKONLY}
CONFIGURE_ARGS+=--enable-agentx-dom-sock-only
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=--enable-ipv6
# --with-transport="UDPIPv6 TCPIPv6" --with-modules=mibII/ipv6"
PLIST_SUB+=	WITH_IPV6=""
.else
PLIST_SUB+=	WITH_IPV6="@comment "
.endif

.if ${PORT_OPTIONS:MUNPRIVILEGED}
CONFIGURE_ARGS+=--without-root-access
.endif

SHLIB_VERSION=	30
PLIST_SUB+=	SHLIB_VERSION=${SHLIB_VERSION}
SCRIPTS_SUB=	PREFIX=${PREFIX} PERL=${PERL}

DEFAULT_SNMP_VERSION?=	3
NET_SNMP_SYS_CONTACT?=	nobody@nowhere.invalid
NET_SNMP_SYS_LOCATION?=	somewhere
NET_SNMP_LOGFILE?=	/var/log/snmpd.log
NET_SNMP_PERSISTENTDIR?=/var/net-snmp
NET_SNMP_WITH_MIB_MODULE_LIST+=	host disman/event-mib mibII/mta_sendmail mibII/tcpTable ucd-snmp/diskio

.if ${OSVERSION} >= 700028 && ${OSVERSION} < 1100000
NET_SNMP_WITH_MIB_MODULE_LIST+=	sctp-mib
.endif

.if ${OSVERSION} >= 800000
CONFIGURE_ARGS+=	--with-libs="-lssp_nonshared"
.endif

.if ${PORT_OPTIONS:MMFD_REWRITES}
CONFIGURE_ARGS+=--enable-mfd-rewrites
NET_SNMP_WITH_MIB_MODULE_LIST+=	if-mib
.endif

.if ${PORT_OPTIONS:MSMUX}
NET_SNMP_WITH_MIB_MODULE_LIST+=		smux
.else
NET_SNMP_WITHOUT_MIB_MODULE_LIST+=	smux
.endif

.if defined(NET_SNMP_WITH_MIB_MODULE_LIST) && \
    !empty(NET_SNMP_WITH_MIB_MODULE_LIST)
CONFIGURE_ARGS+=--with-mib-modules="${NET_SNMP_WITH_MIB_MODULE_LIST}"
.endif

.if defined(NET_SNMP_WITHOUT_MIB_MODULE_LIST) && \
    !empty(NET_SNMP_WITHOUT_MIB_MODULE_LIST)
CONFIGURE_ARGS+=--with-out-mib-modules="${NET_SNMP_WITHOUT_MIB_MODULE_LIST}"
.endif

MAN1=		agentxtrap.1 encode_keychange.1 fixproc.1 mib2c.1 mib2c-update.1 \
		net-snmp-config.1 net-snmp-create-v3-user.1 snmp-bridge-mib.1 \
		snmpbulkget.1 snmpbulkwalk.1 snmpcmd.1 snmpconf.1 \
		snmpdelta.1 snmpdf.1 snmpget.1 snmpgetnext.1 snmpinform.1 \
		snmpnetstat.1 snmpset.1 snmpstatus.1 snmptable.1 snmptest.1 \
		snmptranslate.1 snmptrap.1 snmpusm.1 snmpvacm.1 snmpwalk.1 \
		tkmib.1 traptoemail.1
MAN3=		add_mibdir.3 add_module_replacement.3 \
		config_perror.3 config_pwarn.3 \
		default_store.3 fprint_description.3 \
		fprint_objid.3 fprint_value.3 fprint_variable.3 \
		get_module_node.3 \
		netsnmp_agent_api.3 netsnmp_config_api.3 netsnmp_init_mib.3 \
		netsnmp_mib_api.3 netsnmp_pdu_api.3 netsnmp_read_module.3 \
		netsnmp_sess_api.3 netsnmp_session_api.3 netsnmp_trap_api.3 \
		netsnmp_varbind_api.3 print_description.3 print_mib.3 \
		print_objid.3 print_value.3 print_variable.3 read_all_mibs.3 \
		read_configs.3 read_config_print_usage.3 \
		read_mib.3 read_objid.3 read_premib_configs.3 \
		register_app_config_handler.3 \
		register_config_handler.3 register_mib_handlers.3 \
		send_easy_trap.3 send_trap_vars.3 send_v2trap.3 \
		shutdown_mib.3 snmp_alarm.3 snmp_alarm_register.3 \
		snmp_alarm_register_hr.3 snmp_alarm_unregister.3 \
		snmp_api_errstring.3 snmp_close.3 \
		snmp_error.3 snmp_free_pdu.3 snmp_open.3 snmp_perror.3 \
		snmp_read.3 snmp_select_info.3 \
		snmp_send.3 snmp_sess_async_send.3 \
		snmp_sess_close.3 snmp_sess_error.3 snmp_sess_init.3 \
		snmp_sess_open.3 snmp_sess_perror.3 \
		snmp_sess_read.3 snmp_sess_select_info.3 \
		snmp_sess_send.3 snmp_sess_session.3 snmp_sess_timeout.3 \
		snmp_set_mib_warnings.3 snmp_set_save_descriptions.3 \
		snmp_timeout.3 snprint_objid.3 snprint_value.3 \
		snprint_variable.3 unregister_app_config_handler.3 \
		unregister_config_handler.3 \
		unregister_all_config_handlers.3 \
		register_prenetsnmp_mib_handler.3 \
		register_const_config_handler.3 \
		register_app_prenetsnmp_mib_handler.3 \
		snprint_description.3 \
		snmp_varlist_add_variable.3 \
		snmp_set_var_value.3 \
		snmp_set_var_typed_value.3 \
		snmp_set_var_typed_integer.3 \
		snmp_set_var_objid.3 \
		snmp_set_mib_errors.3 snmp_pdu_create.3 \
		snmp_pdu_add_variable.3 snmp_parse_oid.3 snmp_free_varbind.3 \
		snmp_free_var.3 snmp_fix_pdu.3 snmp_clone_varbind.3 \
		snmp_clone_pdu.3 snmp_add_null_var.3

.if ${PORT_OPTIONS:MPERL}
MAN3PERL=	NetSNMP::ASN.3 NetSNMP::OID.3 NetSNMP::agent.3 \
		NetSNMP::TrapReceiver.3 \
		NetSNMP::agent::default_store.3 \
		NetSNMP::default_store.3 \
		NetSNMP::netsnmp_request_infoPtr.3 SNMP.3
MAN3PERLPREFIX=	${PREFIX}/lib/perl5/${PERL_VER}
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
.if ${PORT_OPTIONS:MTKMIB}
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
	@${ECHO_MSG} "NET_SNMP_WITH_MIB_MODULE_LIST=\"${NET_SNMP_WITH_MIB_MODULE_LIST}\""
	@${ECHO_MSG} "                             MIBs to add to the build."
	@${ECHO_MSG} "NET_SNMP_WITHOUT_MIB_MODULE_LIST=\"${NET_SNMP_WITHOUT_MIB_MODULE_LIST}\""
	@${ECHO_MSG} "                             MIBs to omit from the build."
	@${ECHO_MSG}

post-patch:
.for filename in ${SCRIPT_FILES}
	${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/local/${filename}
.endfor
.if ${OSVERSION} >= 900007
	@${REINPLACE_CMD} -e 's!utmp_p->ut_name!utmp_p->ut_user!' \
	    ${WRKSRC}/agent/mibgroup/host/hr_system.c
.endif

post-configure:
	${FIND} ${WRKSRC} -name Makefile | \
	 ${XARGS} ${REINPLACE_CMD} -E -e '/^INSTALL[ 	]+=/s|$$| -m 755|'
.for hdr in sys/mbuf.h netinet/in_pcb.h netinet/in_var.h netinet/ip6.h
	@${REINPLACE_CMD} -E -e '\
		s!^.*#undef.*(HAVE_${hdr:U:S/./_/g:S/\//_/g}).*$$!#define \1 1!g' \
			${WRKSRC}/include/net-snmp/net-snmp-config.h
.endfor
.if ${PORT_OPTIONS:MPYTHON}
	@(cd ${WRKSRC}/python; \
	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} setopt -c bdist_egg \
		-o plat-name -s "" --basedir=${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} setopt -c bdist \
		-o plat-name -s "" --basedir=${WRKSRC})
.endif

post-build:
.if ${PORT_OPTIONS:MPERL}
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
	cd ${PREFIX}/bin; ${STRIP_CMD} ${BIN_FILES}
	cd ${PREFIX}/sbin; ${STRIP_CMD} ${SBIN_FILES}

install-config-files:
	${INSTALL_DATA} ${WRKSRC}/EXAMPLE.conf ${DATADIR}/snmpd.conf.example

install-doc-files:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
. for filename in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${DOCSDIR}
. endfor
.endif

display-message:
	${ECHO_MSG}
	${CAT} ${PKGMESSAGE}

# Maintainer's note:
#   Don't forget to bump library version in these ports.
#   french/plgrenouille,graphics/hpoj,lang/php4,lang/php5,mail/cyrus-imapd22,mail/cyrus-imapd23,misc/kdeutils3,net-mgmt/braa,net-mgmt/docsis,net-mgmt/mbrowse,net-mgmt/nagios-snmp-plugins,net-mgmt/p5-SNMP-Info,net-mgmt/py-yapsnmp,net-mgmt/sdig,net-mgmt/zabbix,net/cactid,net/wireshark,net/ifstat,net/quagga,net/rtg,print/hplip,security/libfwbuilder,sysutils/apcupsd,sysutils/jailadmin,sysutils/nut

.include <bsd.port.mk>
