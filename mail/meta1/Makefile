# $FreeBSD$

PORTNAME=	meta1
PORTVERSION=	1.1.0a.11.0
CATEGORIES=	mail ipv6
MASTER_SITES=	http://www.MeTA1.org/download/.alpha/mstack/
PKGNAMESUFFIX?=	${TLS_SUFFIX}${SASL_SUFFIX}${BERKELEYDB_SUFFIX}${PMILTER_SUFFIX}${PKGNAMESUFFIX2}
DISTNAME=	${PORTNAME}-1.1.Alpha11.0

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Secure and efficient mail gateway

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_JOBS_UNSAFE=	yes
CONFLICTS=	smx-*
MANUAL_PACKAGE_BUILD=	needs hostname

.if !defined(SENDMAIL_WITHOUT_SHMEM) && !defined(BUILDING_INDEX)
IPCCHECK!=	ipcrm -q 0 2>&1 || true
.if ${IPCCHECK:Mimplemented}
IGNORE=		your system does not support sysvipc
.endif
.endif

USES=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-dependency-tracking
MAKE_ENV+=	META1CONFDIR="${META1CONFDIR}"
PORTDOCS=	README.dvi README.html README.pdf README.ps README.txt \
		img1.png img2.png img3.png img4.png img5.png img6.png \
		nx_grp_g.png overview1.eps overview1.gif overview1.pdf \
		prev_g.png up_g.png pmilter.api.tex
PLIST_SUB+=	NOLOGIN=${NOLOGIN_CMD}
EXTRA_SBIN=	libcheck/noroot libconf/tree libmta/statit \
		libmta/t-hostname checks/t-getgroup
GROUPS=		meta1s meta1q meta1c meta1m meta1
USERS=		meta1s meta1q meta1c meta1m meta1

# default config:
META1CONFDIR?=	${PREFIX}/etc/meta1
NOLOGIN_CMD?=	/usr/sbin/nologin

OPTIONS_DEFINE=	IPV6 BDB PMILTER DKIM MSP SASL2 SASL2AUTHD TLS DOCS
OPTIONS_DEFAULT=	PMILTER DKIM SASL2 TLS
NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes

BDB_DESC=	External Berkeley DB support
PMILTER_DESC=	Adds policy milter support
DKIM_DESC=	Enable DKIM signing support
MSP_DESC=	Enable mail submision program
SASL2_DESC=	Adds SASL2 support
SASL2AUTHD_DESC=	Enable plaintext authentication via SASL2

BDB_USES=		bdb
PMILTER_USES=		ssl
PMILTER_CONFIGURE_ENABLE=	pmilter
DKIM_CONFIGURE_ENABLE=	DKIM
MSP_CONFIGURE_ENABLE=	msp
SASL2_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL2_CONFIGURE_ENABLE=	SASL
SASL2_CONFIGURE_ON=	--with-sasl-incdir=${LOCALBASE}/include \
			--with-sasl-libdir=${LOCALBASE}/lib
SASL2AUTHD_RUN_DEPENDS=	${LOCALBASE}/sbin/saslauthd:security/cyrus-sasl2-saslauthd
TLS_USES=		ssl
TLS_CONFIGURE_ENABLE=	TLS
TLS_CPPFLAGS=		-I${LOCALBASE}/include
TLS_LDFLAGS=		-I${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
MAKE_ENV+=	MTA_NETINET6=1
.endif

.if ${PORT_OPTIONS:MBDB}
BROKEN=		port version of Berkeley DB is not compatible
INVALID_BDB_VER=	48 5 6
BERKELEYDB_SUFFIX=	-db${BDB_VER}
CONFIGURE_ARGS+=	--disable-included-bdb
CONFIGURE_ARGS+=	--with-bdb-incdir=${BDB_INCLUDE_DIR}
CONFIGURE_ARGS+=	--with-bdb-libdir=${BDB_LIB_DIR}
PLIST_SUB+=	WITH_BDBINT="@comment "
.else
BERKELEYDB_SUFFIX=	-intbdb
PLIST_SUB+=	WITH_BDBINT=""
.endif

.if ! ${PORT_OPTIONS:MPMILTER}
PMILTER_SUFFIX?=	-nopmilter
.endif

.if ${PORT_OPTIONS:MMSP}
CONFLICTS+=	courier-0.* postfix-1.* postfix-2.* smail-3.* zmailer-2.* opensmtpd-* sendmail-*
.endif

.if ! ${PORT_OPTIONS:MSASL2}
SASL_SUFFIX?=	-nosasl
.endif

.if ${PORT_OPTIONS:MSASL2AUTHD}
.if empty(PORT_OPTIONS:MSASL2)
IGNORE=		option SASL2AUTHD needs option SASL2
.endif
.endif

.if ! ${PORT_OPTIONS:MTLS}
TLS_SUFFIX?=	-notls
.endif

post-configure:
	@${CP} ${WRKSRC}/misc/sm.check.sh ${WRKSRC}/misc/sm.setup.sh \
		${WRKDIR}/
	@${REINPLACE_CMD} -e 's|/etc/meta1|${META1CONFDIR}|g' \
		-e 's|$${SD}/misc|${PREFIX}/bin|' \
		-e 's|$${SD}/libcheck|${PREFIX}/sbin|' \
		-e 's|$${SD}/libmta|${PREFIX}/sbin|' \
		-e 's|$${SD}/checks|${PREFIX}/sbin|' \
		${WRKDIR}/sm.check.sh
	@${REINPLACE_CMD} -e 's|/etc/meta1|${META1CONFDIR}|g' \
		-e 's|$${S}/misc|${PREFIX}/bin|' \
		-e 's|$${S}/libconf|${PREFIX}/sbin|' \
		-e 's|$${S}/libmta|${PREFIX}/sbin|' \
		-e 's|$${S}/checks|${PREFIX}/sbin|' \
		-e 's|=mcp.sh|=${PREFIX}/etc/rc.d/meta1-mcp.sh|' \
		${WRKDIR}/sm.setup.sh
	@${REINPLACE_CMD} -e "/install-data-hook/d" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|^TESTS =.*|TESTS = $$(TESTP)|' \
		${WRKSRC}/libdkim/Makefile.in
	${CP} ${WRKSRC}/libdns/common.sh ${WRKSRC}/

test:	build
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/sm.check.sh ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKDIR}/sm.setup.sh ${STAGEDIR}${PREFIX}/sbin/
.for i in ${EXTRA_SBIN}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/sbin/
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
