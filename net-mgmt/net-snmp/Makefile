PORTNAME=	snmp
PORTVERSION=	5.9.4
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/net-${PORTNAME}/net-${PORTNAME}/${PORTVERSION} \
		ZI
PKGNAMEPREFIX=	net-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Extendable SNMP implementation
WWW=		http://net-snmp.sourceforge.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=		mips mips64
NOT_FOR_ARCHS_REASON=	SSP is currently broken on MIPS

OPTIONS_DEFINE=	MFD_REWRITES PERL PERL_EMBEDDED PYTHON DUMMY TKMIB \
		MYSQL AX_SOCKONLY UNPRIVILEGED SMUX DOCS AX_DISABLE_TRAP \
		TLS NEWSYSLOG NOLIBPKG SCTP AES
OPTIONS_DEFAULT=PERL PERL_EMBEDDED DUMMY SMUX NEWSYSLOG
OPTIONS_SUB=	yes

MFD_REWRITES_DESC=	Use new MFD rewrites of mib modules
PERL_EMBEDDED_DESC=	Build embedded perl
DUMMY_DESC=		Enable dummy values as placeholders
TKMIB_DESC=		Install graphical MIB browser
AX_SOCKONLY_DESC=	Disable UDP/TCP transports for agentx
AX_DISABLE_TRAP_DESC=	Disable agentx subagent code in snmptrapd
UNPRIVILEGED_DESC=	Allow unprivileged users to execute net-snmp
SMUX_DESC=		Build with SNMP multiplexing (SMUX) support
NEWSYSLOG_DESC=		Automatically rotate snmpd.log via newsyslog
NOLIBPKG_DESC=		Build without libpkg
SCTP_DESC=		Build with SCTP MIB support
AES_DESC=		Build with Blumenthal AES support

USERS=		snmpd
GROUPS=		snmpd

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		cpe libtool perl5 ssl
USE_RC_SUBR=	snmpd snmptrapd
USE_LDCONFIG=	yes
CPE_PRODUCT=	net-snmp
USE_PERL5=	build run
USE_CSTD=	c99

CFLAGS+=	-I${LOCALBASE}/include -I${PKG_PREFIX}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	PERLPROG="${PERL}" PSPROG="${PS_CMD}" SED="${SED}"
CONFIGURE_ARGS+=--enable-shared --enable-internal-md5 \
		--with-default-snmp-version="${DEFAULT_SNMP_VERSION}" \
		--with-sys-contact="${NET_SNMP_SYS_CONTACT}" \
		--with-sys-location="${NET_SNMP_SYS_LOCATION}" \
		--with-logfile="${NET_SNMP_LOGFILE}" \
		--with-persistent-directory="${NET_SNMP_PERSISTENTDIR}" \
		--with-gnu-ld --without-libwrap --enable-ipv6 \
		--without-kmem-usage \
		--with-ldflags="-lm -lkvm -ldevstat -L${PKG_PREFIX}/lib -L${LOCALBASE}/lib ${LCRYPTO}"
SUB_FILES=	pkg-message

.if defined(WITH_SSP)
CONFIGURE_ARGS+=--with-libs="-lssp_nonshared"
.endif

.if defined(BATCH)
CONFIGURE_ARGS+=--with-defaults
.endif

TLS_CONFIGURE_ON=	--with-security-modules=tsm --with-transports=TLSTCP,DTLSUDP

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
PYDISTUTILS_PKGNAME?=		netsnmp-python
PYDISTUTILS_PKGVERSION?=	1.0a1
USES+=		python
RUN_DEPENDS+=	${PY_SETUPTOOLS}
BUILD_DEPENDS+=	${PY_SETUPTOOLS}
CONFIGURE_ARGS+=--with-python-modules
CONFIGURE_ENV+=	PYTHONPROG="${PYTHON_CMD}"
MAKE_ENV+=	PYDISTUTILS_INSTALLARGS="${PYDISTUTILS_INSTALLARGS}" STAGEDIR="${STAGEDIR}"
PLIST_SUB+=	WITH_PYTHON="" PYTHON_VER=${PYTHON_VER}
PLIST_SUB+=	PYDISTUTILS_PKGVERSION=${PYDISTUTILS_PKGVERSION}
.else
PLIST_SUB+=	WITH_PYTHON="@comment "
.endif

CONFIGURE_ARGS+=--with-openssl="${OPENSSLBASE}"

.if ${PORT_OPTIONS:MDUMMY}
CONFIGURE_ARGS+=--with-dummy-values
.endif

.if ${PORT_OPTIONS:MAES}
CONFIGURE_ARGS+=--enable-blumenthal-aes
.endif

.if ! ${PORT_OPTIONS:MTKMIB}
PLIST_SUB+=	WITH_TKMIB="@comment "
.else
RUN_DEPENDS+=	p5-Tk>=0:x11-toolkits/p5-Tk
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

.if ${PORT_OPTIONS:MMYSQL}
USES+=		mysql
CONFIGURE_ARGS+=--with-mysql
CONFIGURE_ENV+=	MYSQLCONFIG=${LOCALBASE}/bin/mysql_config
.endif

.if ${PORT_OPTIONS:MAX_DISABLE_TRAP}
CONFIGURE_ARGS+=--disable-snmptrapd-subagent
.endif

.if ${PORT_OPTIONS:MAX_SOCKONLY}
CONFIGURE_ARGS+=--enable-agentx-dom-sock-only
.endif

.if ${PORT_OPTIONS:MUNPRIVILEGED}
CONFIGURE_ARGS+=--without-root-access
.endif

SHLIB_VERSION=	40
SHLIB_VERSION2=	.2.1
PLIST_SUB+=	SHLIB_VERSION=${SHLIB_VERSION} SHLIB_VERSION2=${SHLIB_VERSION2}
SCRIPTS_SUB=	PREFIX=${PREFIX} PERL=${PERL}

DEFAULT_SNMP_VERSION?=	3
NET_SNMP_SYS_CONTACT?=	nobody@nowhere.invalid
NET_SNMP_SYS_LOCATION?=	somewhere
NET_SNMP_LOGFILE?=	/var/log/snmpd.log
NET_SNMP_PERSISTENTDIR?=/var/net-snmp
NET_SNMP_WITH_MIB_MODULE_LIST+=	host disman/event-mib mibII/mta_sendmail mibII/tcpTable ucd-snmp/diskio

.if ${PORT_OPTIONS:MSCTP}
NET_SNMP_WITH_MIB_MODULE_LIST+=	sctp-mib
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

BIN_FILES=	snmpbulkwalk snmpget snmpgetnext snmpset \
		snmpstatus snmptest snmptranslate snmptrap snmpwalk \
		snmptable snmpbulkget snmpdelta snmpdf agentxtrap \
		snmpps snmpping snmppcap snmpvacm snmpusm \
		encode_keychange snmpnetstat
LIB_FILES=	libnetsnmp.so.${SHLIB_VERSION}${SHLIB_VERSION2} \
		libnetsnmpagent.so.${SHLIB_VERSION}${SHLIB_VERSION2} \
		libnetsnmpmibs.so.${SHLIB_VERSION}${SHLIB_VERSION2} \
		libnetsnmphelpers.so.${SHLIB_VERSION}${SHLIB_VERSION2} \
		libnetsnmptrapd.so.${SHLIB_VERSION}${SHLIB_VERSION2}
SBIN_FILES=	snmpd snmptrapd
STARTUP_DIR=	${PREFIX}/etc/rc.d
SCRIPT_FILES=	snmpcheck.def mib2c fixproc ipf-mod.pl traptoemail
.if ${PORT_OPTIONS:MTKMIB}
SCRIPT_FILES+=	tkmib
.endif
DOC_FILES=	AGENT.txt COPYING FAQ NEWS README \
		README.agentx README.krb5 README.snmpv3 README.thread \
		agent/mibgroup/README.smux

CONFLICTS=	ucd-snmp-4.* net-snmp-5.3.*

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} != base
LCRYPTO=	-lcrypto
.else
LCRYPTO=
.endif

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
	@${REINPLACE_CMD} -E -e 's|return pci_lookup_name|disabled broken|g' \
		${WRKSRC}/configure
.if ${OPSYS} == FreeBSD || ${SSL_DEFAULT:Mopenssl}
	@${REINPLACE_CMD} -E -e 's|SSL_library_init|OPENSSL_init_ssl|g' \
		${WRKSRC}/configure
.endif
.for header in darwin7.h darwin8.h darwin9.h darwin10.h darwin11.h darwin12.h \
	darwin13.h darwin14.h darwin15.h darwin16.h darwin17.h
	@${CP} ${WRKSRC}/include/net-snmp/system/darwin.h \
		${WRKSRC}/include/net-snmp/system/${header}
.endfor

.if ${PORT_OPTIONS:MNOLIBPKG}
pre-configure:
	${REINPLACE_CMD} \
		-e 's|pkg[.]h|ignore-pkg.h|g' \
		-e 's|in pkg ;|in ignore-pkg ;|' \
		${WRKSRC}/configure
.endif

post-configure:
	@${FIND} ${WRKSRC} -name Makefile | \
		${XARGS} ${REINPLACE_CMD} -E -e '/^INSTALL[ 	]+=/s|$$| -m 755|'
.for hdr in sys/mbuf.h netinet/in_pcb.h netinet/in_var.h netinet/ip6.h pkg.h
	@${REINPLACE_CMD} -E -e '\
		s!^.*#undef.*(HAVE_${hdr:tu:S/./_/g:S/\//_/g}).*$$!#define \1 1!g' \
			${WRKSRC}/include/net-snmp/net-snmp-config.h
.endfor
	# Fix after:
	# https://github.com/net-snmp/net-snmp/commit/923cb442bbef360de227fbca565710518b5ee8e5
	@${REINPLACE_CMD} -e 's|snmpIPv6BaseDomain.h snmpIPBaseDomain.h|snmpIPv6BaseDomain.h|g' \
		${WRKSRC}/snmplib/Makefile
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
		s!^(INSTALLMAN3DIR|INSTALLSITEMAN3DIR) = .*!\1 = ${PREFIX}/share/man/man3!; \
		s!^(INSTALLSITELIB|INSTALLSITEARCH) = /usr/local/(.*)!\1 = ${PREFIX}/\2!; \
		s! doc_(perl|site|\$$\(INSTALLDIRS\))_install$$!!; \
		'
.else
	${REINPLACE_CMD} -e 's| perlinstall||' ${WRKSRC}/Makefile
.endif

post-install: strip-files install-config-files install-doc-files
	@${MKDIR} ${STAGEDIR}/var/agentx
	@(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf libnetsnmp.so.${SHLIB_VERSION} libnetsnmp.so)
	@(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf libnetsnmpagent.so.${SHLIB_VERSION} libnetsnmpagent.so)
	@(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf libnetsnmphelpers.so.${SHLIB_VERSION} libnetsnmphelpers.so)
	@(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf libnetsnmpmibs.so.${SHLIB_VERSION} libnetsnmpmibs.so)
	@(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf libnetsnmptrapd.so.${SHLIB_VERSION} libnetsnmptrapd.so)
.if ${PORT_OPTIONS:MNEWSYSLOG}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/net-snmp.conf ${STAGEDIR}${DATADIR}/newsyslog.conf.sample
.endif

strip-files:
	(cd ${STAGEDIR}${PREFIX}/bin; ${STRIP_CMD} ${BIN_FILES})
	(cd ${STAGEDIR}${PREFIX}/lib; ${STRIP_CMD} ${LIB_FILES})
	(cd ${STAGEDIR}${PREFIX}/sbin; ${STRIP_CMD} ${SBIN_FILES})

install-config-files:
	${INSTALL_DATA} ${WRKSRC}/EXAMPLE.conf ${STAGEDIR}${DATADIR}/snmpd.conf.example

install-doc-files:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
. for filename in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${STAGEDIR}${DOCSDIR}
. endfor
.endif

# Maintainer's note:
#   Don't forget to bump library version in these ports.
#   french/plgrenouille,graphics/hpoj,lang/php4,lang/php5,mail/cyrus-imapd22,mail/cyrus-imapd23,misc/kdeutils3,net-mgmt/braa,net-mgmt/docsis,net-mgmt/mbrowse,net-mgmt/nagios-snmp-plugins,net-mgmt/p5-SNMP-Info,net-mgmt/py-yapsnmp,net-mgmt/sdig,net-mgmt/zabbix,net/cactid,net/wireshark,net/ifstat,net/quagga,net/rtg,print/hplip,security/libfwbuilder,sysutils/apcupsd,sysutils/jailadmin,sysutils/nut

.include <bsd.port.post.mk>
