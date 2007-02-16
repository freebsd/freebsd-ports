# New ports collection makefile for:	smx
# Date created:				04 Nov 2005
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	smx
PORTVERSION=	0.0.0.0
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.sendmail.org/pub/sendmail/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/mail/sendmail/&,}
PKGNAMESUFFIX?=	${TLS_SUFFIX}${SASL_SUFFIX}${LDAP_SUFFIX}${BERKELEYDB_SUFFIX}${PMILTER_SUFFIX}${PKGNAMESUFFIX2}
DISTNAME=	${PORTNAME2}-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Secure and efficient mail gateway

NOT_FOR_ARCHS=	ia64
CONFLICTS=	meta1-*
PORTNAME2=	smX
WRKSRC=		${WRKDIR}/${PORTNAME2}-${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--disable-dependency-tracking
MAKE_ENV+=	SMXCONFDIR="${SMXCONFDIR}"
MAN5=		sendmailx.conf.5
MAN8=		createmap.8 mailq.8 mcp.8 milter-spamd.8 qmgr.8 \
		qmgrctl.8 runas.8 sendmailx.8 smar.8 smtpc.8 smtps.8
MLINKS=		sendmailx.conf.5 smx.conf.5 \
		sendmailx.8 sendmailX.8
PORTDOCS=	README.dvi README.html README.pdf README.ps README.txt \
		img1.png img2.png img3.png img4.png img5.png img6.png \
		nx_grp_g.png overview1.eps overview1.gif overview1.pdf \
		prev_g.png up_g.png pmilter.api.tex
PLIST_SUB+=	SPOOL=${DESTDIR}/var/spool
PLIST_SUB+=	NOLOGIN=${NOLOGIN_CMD}
EXTRA_SBIN=	libcheck/noroot libconf/tree libmta/statit \
		libmta/t-hostname checks/t-getgroup

# Options to define Features:
# SMX_WITHOUT_TLS=yes
# SMX_WITHOUT_SASL=yes
# SMX_WITH_PMILTER=yes
# SMX_WITH_INTERNAL_BERKELEYD=yes
# SMX_WITH_BERKELEYDB=yes
#   Set either WITH_BDB_VER or SMX_WITH_BDB_VER
#   to the version of Berkely DB to use.

# default config:
SMXCONFDIR?=	${PREFIX}/etc/smx

.if defined(SMX_WITH_BERKELEYDB_VER)
SMX_WITH_BERKELEYDB=	yes
OBSOLETE_BDB_VAR=	SMX_WITH_BERKELEYDB_VER BERKELEYDB_PORT \
	BERKELEYDB_LIB BERKELEYDB_LIBDIR BERKELEYDB_INCLUDE
IGNORE=	use SMX_WITH_BERKELEYDB to select Berkeley DB
.endif

.if defined(SMX_WITH_INTERNAL_BERKELEYD)
BERKELEYDB_SUFFIX=	-intbdb
PLIST_SUB+=	WITH_BDBINT=""
.else
.if defined(SMX_WITH_BDB_VER)
SMX_WITH_BERKELEYDB=yes
.endif
.if !defined(SMX_WITH_BERKELEYDB)
SMX_WITH_BERKELEYDB=yes
WITH_BDB_VER=	43
.endif
USE_BDB=	41+
IGNORE_WITH_BDB=	2 3 40
BERKELEYDB_SUFFIX=	-${BDB_INCLUDE_DIR:S,^${LOCALBASE}/include/,,}
CONFIGURE_ARGS+=	--disable-included-bdb
CONFIGURE_ARGS+=	--with-bdb-incdir=${BDB_INCLUDE_DIR}
CONFIGURE_ARGS+=	--with-bdb-libdir=${BDB_LIB_DIR}
PLIST_SUB+=	WITH_BDBINT="@comment "
.endif

.if defined(SMX_WITHOUT_SASL)
SASL_SUFFIX?=	-nosasl
CONFIGURE_ARGS+=	--disable-SASL
.else
LIB_DEPENDS+=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2
.if !defined(SMX_WITHOUT_SASLAUTHD)
RUN_DEPENDS+=	${LOCALBASE}/sbin/saslauthd:${PORTSDIR}/security/cyrus-sasl2-saslauthd
.endif
CONFIGURE_ARGS+=	--enable-SASL
CONFIGURE_ARGS+=	--with-sasl-incdir=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-sasl-libdir=${LOCALBASE}/lib
.endif

.if defined(SMX_WITHOUT_TLS) || defined(WITHOUT_TLS)
TLS_SUFFIX?=	-notls
CONFIGURE_ARGS+=	--disable-TLS
.else
CONFIGURE_ARGS+=	--enable-TLS
.endif

.if defined(SMX_WITH_PMILTER) || defined(WITH_PMILTER)
PMILTER_SUFFIX?=	-pmilter
CONFIGURE_ARGS+=	--enable-pmilter
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=	--disable-pmilter
.endif

.if defined(BATCH)
EXTRA_PATCHES+=		${FILESDIR}/batch.patch
.endif

post-configure:
	@${CP} ${WRKSRC}/misc/sm.check.sh ${WRKSRC}/misc/sm.setup.sh \
		${WRKDIR}/
	 @${REINPLACE_CMD} -e 's|/etc/smx|${SMXCONFDIR}|g' \
		-e 's|$${SD}/misc|${PREFIX}/bin|' \
		-e 's|$${SD}/libcheck|${PREFIX}/sbin|' \
		-e 's|$${SD}/libmta|${PREFIX}/sbin|' \
		-e 's|$${SD}/checks|${PREFIX}/sbin|' \
		${WRKDIR}/sm.check.sh
	 @${REINPLACE_CMD} -e 's|/etc/smx|${SMXCONFDIR}|g' \
		-e 's|[.]/misc|${PREFIX}/bin|' \
		-e 's|$${S}/libconf|${PREFIX}/sbin|' \
		-e 's|[.]/libmta|${PREFIX}/sbin|' \
		-e 's|[.]/checks|${PREFIX}/sbin|' \
		-e 's|=mcp.sh|=${PREFIX}/etc/rc.d/smx-mcp.sh|' \
		${WRKDIR}/sm.setup.sh

test:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

regression-test:	test

pre-install:
	if ! pw groupshow smxm; then pw groupadd smxs -g 260; fi
	if ! pw groupshow smxq; then pw groupadd smxq -g 261; fi
	if ! pw groupshow smxc; then pw groupadd smxc -g 262; fi
	if ! pw groupshow smxm; then pw groupadd smxm -g 263; fi
	if ! pw groupshow smx; then pw groupadd smx -g 264; fi
	if ! pw usershow smxs; then pw useradd smxs -g smxs -u 260 \
		-h - -d ${NONEXISTENT} -s ${NOLOGIN_CMD} -c "Sendmail X SMTPS"; fi
	if ! pw usershow smxq; then pw useradd smxq -g smxq -u 261 \
		-h - -d ${NONEXISTENT} -s ${NOLOGIN_CMD} -c "Sendmail X QMGR"; fi
	if ! pw usershow smxc; then pw useradd smxc -g smxc -u 262 \
		-h - -d ${NONEXISTENT} -s ${NOLOGIN_CMD} -c "Sendmail X SMTPC"; fi
	if ! pw usershow smxm; then pw useradd smxm -g smxm -u 263 \
		-h - -d ${NONEXISTENT} -s ${NOLOGIN_CMD} -c "Sendmail X misc"; fi
	if ! pw usershow smx; then pw useradd smx -g smx -u 264 \
		-h - -d ${NONEXISTENT} -s ${NOLOGIN_CMD} -c "Sendmail X other"; fi
	pw groupmod smxc -m smxs
	pw groupmod smxm -m smxs,smxq
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

.include <bsd.port.pre.mk>

.if !defined(UID)
UID!=	${ID} -u
.endif
.if ${UID} != 0
post-build:	test
.endif

.if ${OSVERSION} < 500000
NOLOGIN_CMD?=	/sbin/nologin
.else
NOLOGIN_CMD?=	/usr/sbin/nologin
.endif

.include <bsd.port.post.mk>
