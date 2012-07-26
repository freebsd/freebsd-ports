# New ports collection makefile for:	meta1
# Date created:				19 Oct 2006
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	meta1
PORTVERSION=	1.0.0a.11.0
DISTVERSION=	1.0.Alpha11.0
CATEGORIES=	mail ipv6
MASTER_SITES=	http://www.MeTA1.org/download/.alpha/rainy/
PKGNAMESUFFIX?=	${TLS_SUFFIX}${SASL_SUFFIX}${LDAP_SUFFIX}${BERKELEYDB_SUFFIX}${PMILTER_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Secure and efficient mail gateway

NOT_FOR_ARCHS=	ia64
CONFLICTS=	smx-*

.if !defined(SENDMAIL_WITHOUT_SHMEM) && !defined(BUILDING_INDEX)
IPCCHECK!=	ipcrm -q 0 2>&1 || true
.if ${IPCCHECK:Mimplemented}
IGNORE=		your system does not support sysvipc
.endif
.endif

MANUAL_PACKAGE_BUILD=	needs hostname

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-dependency-tracking
MAKE_ENV+=	META1CONFDIR="${META1CONFDIR}"
MAN8=		createmap.8 fsperf1.8 mailq.8 mcp.8 milter-spamd.8 \
		milter-regex.8 qmgr.8 qmgrctl.8 runas.8 meta1.8 smar.8 \
		smtpc.8 smtps.8
MLINKS=		sendmailx.conf.5 meta1.conf.5 \
		sendmailx.8 sendmailX.8
PORTDOCS=	README.dvi README.html README.pdf README.ps README.txt \
		img1.png img2.png img3.png img4.png img5.png img6.png \
		nx_grp_g.png overview1.eps overview1.gif overview1.pdf \
		prev_g.png up_g.png pmilter.api.tex
PLIST_SUB+=	NOLOGIN=${NOLOGIN_CMD}
EXTRA_SBIN=	libcheck/noroot libconf/tree libmta/statit \
		libmta/t-hostname checks/t-getgroup
# GROUPS/USERS does not work from package
#GROUPS=	meta1s meta1q meta1c meta1m meta1
#USERS=		meta1s meta1q meta1c meta1m meta1

# default config:
META1CONFDIR?=	${PREFIX}/etc/meta1
NOLOGIN_CMD?=	/usr/sbin/nologin

OPTIONS_DEFINE=	BDB PMILTER SASL2 SASL2AUTHD TLS
OPTIONS_DEFAULT=	BDB PMILTER SASL2 TLS

BDB_DESC=	External Berkeley DB support
PMILTER_DESC=	Adds policy milter support
SASL2_DESC=	Adds SASL2 support
SASL2AUTHD_DESC=	Enable plaintext authentication via SASL2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBDB}
USE_BDB=	42+
INVALID_BDB_VER=	46 47 48 5
BERKELEYDB_SUFFIX=	-db${BDB_VER}
CONFIGURE_ARGS+=	--disable-included-bdb
CONFIGURE_ARGS+=	--with-bdb-incdir=${BDB_INCLUDE_DIR}
CONFIGURE_ARGS+=	--with-bdb-libdir=${BDB_LIB_DIR}
PLIST_SUB+=	WITH_BDBINT="@comment "
.else
BERKELEYDB_SUFFIX=	-intbdb
PLIST_SUB+=	WITH_BDBINT=""
.endif

.if ${PORT_OPTIONS:MPMILTER}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--enable-pmilter
.else
PMILTER_SUFFIX?=	-nopmilter
CONFIGURE_ARGS+=	--disable-pmilter
.endif

.if ${PORT_OPTIONS:MSASL2}
LIB_DEPENDS+=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--enable-SASL
CONFIGURE_ARGS+=	--with-sasl-incdir=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-sasl-libdir=${LOCALBASE}/lib
.else
SASL_SUFFIX?=	-nosasl
CONFIGURE_ARGS+=	--disable-SASL
.endif

.if ${PORT_OPTIONS:MSASL2AUTHD}
.if empty(PORT_OPTIONS:MSASL2)
IGNORE=		Option SASL2AUTHD needs option SASL2
.endif
RUN_DEPENDS+=	${LOCALBASE}/sbin/saslauthd:${PORTSDIR}/security/cyrus-sasl2-saslauthd
.endif

.if ${PORT_OPTIONS:MTLS}
CONFIGURE_ARGS+=	--enable-TLS
.else
TLS_SUFFIX?=	-notls
CONFIGURE_ARGS+=	--disable-TLS
.endif

post-patch:
	${REINPLACE_CMD} -e 's|echo aout|echo elf|' \
		${WRKSRC}/db-4.3.28.NC/dist/configure

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
		-e 's|[.]/misc|${PREFIX}/bin|' \
		-e 's|$${S}/libconf|${PREFIX}/sbin|' \
		-e 's|[.]/libmta|${PREFIX}/sbin|' \
		-e 's|[.]/checks|${PREFIX}/sbin|' \
		-e 's|=mcp.sh|=${PREFIX}/etc/rc.d/meta1-mcp.sh|' \
		${WRKDIR}/sm.setup.sh

test:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

#fails on bento
#regression-test:	test

.if !defined(UID)
UID!=	${ID} -u
.endif
.if ${UID} != 0
post-build:	test
.endif

pre-install:
	if ! pw groupshow meta1s; then pw groupadd meta1s -g 260; fi
	if ! pw groupshow meta1q; then pw groupadd meta1q -g 261; fi
	if ! pw groupshow meta1c; then pw groupadd meta1c -g 262; fi
	if ! pw groupshow meta1m; then pw groupadd meta1m -g 263; fi
	if ! pw groupshow meta1; then pw groupadd meta1 -g 264; fi
	if ! pw usershow meta1s; then pw useradd meta1s -g meta1s -u 260 \
		-h - -d ${NONEXISTENT} -s ${NOLOGIN_CMD} -c "MeTA1 SMTPS"; fi
	if ! pw usershow meta1q; then pw useradd meta1q -g meta1q -u 261 \
		-h - -d ${NONEXISTENT} -s ${NOLOGIN_CMD} -c "MeTA1 QMGR"; fi
	if ! pw usershow meta1c; then pw useradd meta1c -g meta1c -u 262 \
		-h - -d ${NONEXISTENT} -s ${NOLOGIN_CMD} -c "MeTA1 SMTPC"; fi
	if ! pw usershow meta1m; then pw useradd meta1m -g meta1m -u 263 \
		-h - -d ${NONEXISTENT} -s ${NOLOGIN_CMD} -c "MeTA1 misc"; fi
	if ! pw usershow meta1; then pw useradd meta1 -g meta1 -u 264 \
		-h - -d ${NONEXISTENT} -s ${NOLOGIN_CMD} -c "MeTA1 other"; fi
	pw groupmod meta1c -m meta1s
	pw groupmod meta1m -m meta1s,meta1q
.if !defined(BATCH)
	cd ${WRKSRC} && ${SH} ./misc/sm.setup.sh
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/sm.check.sh ${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKDIR}/sm.setup.sh ${PREFIX}/sbin/
.for i in ${EXTRA_SBIN}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/sbin/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
