# New ports collection makefile for:	dansguardian
# Date created:				April 02, 2002
# Whom:					Freddie Cash <fjwcash@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	dansguardian
PORTVERSION=	2.9.9.3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	# empty, see below
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast, feature-rich web content filter for Squid proxy servers

RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid

USE_ICONV=	yes

USE_RC_SUBR=	dansguardian

CONFLICTS=	dansguardian-2.[678]*
LATEST_LINK=	dansguardian-devel
IGNORE=		dansGuardian 2.10 has gone stable, use www/dansguardian

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-logdir=/var/log \
		--with-piddir=/var/run

MAN8=		dansguardian.8

OPTIONS=	DG_APACHE  "Enable Apache support for access denied page" on \
		DG_PCRE    "Enable PCRE support" on \
		DG_DMGR    "Enable the fancy download manager" on \
		DG_TRICKLE "Enable the trickle download manager" on \
		DG_CLISCAN "Enable support for CLI content scanners" off \
		DG_CLAMD   "Enable ClamAV daemon support (clamd)" off \
		DG_ICAP    "Enable ICAP AV content scanner support (testing)" off \
		DG_KASP    "Enable Kaspersky AV support (testing)" off \
		DG_NTLM    "Enable NTLM authentication plugin" off \
		DG_EMAIL   "Enable e-mail reporting support" off \
		DG_DEBUG   "Enable debug options - not for production use" off

DG_URL=		http://dansguardian.org/index.php?page=copyright2
CONFDIR=	${PREFIX}/etc/dansguardian

RESTRICTED=	Redistribution and commercial download is restricted. Check ${DG_URL} for more info

PORTDOCS=	AuthPlugins ContentScanners DownloadManagers FAQ FAQ.html Plugins

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_DG_APACHE)
USE_APACHE=	1.3+
.endif

.if !defined(WITHOUT_DG_PCRE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
.endif

.if !defined(WITHOUT_DG_TRICKLE)
CONFIGURE_ARGS+=	--enable-trickledm
.endif

.if defined(WITH_DG_CLISCAN)
CONFIGURE_ARGS+=	--enable-commandline
PLIST_SUB+=		CLISCANCONF=""
.else
PLIST_SUB+=		CLISCANCONF="@comment "
.endif

.if defined(WITH_DG_CLAMD)
CONFIGURE_ARGS+=	--enable-clamd
RUN_DEPENDS+=		${LOCALBASE}/sbin/clamd:${PORTSDIR}/security/clamav
PLIST_SUB+=		CLAMDCONF=""
.else
PLIST_SUB+=		CLAMDCONF="@comment "
.endif

.if defined(WITH_DG_ICAP)
CONFIGURE_ARGS+=	--enable-icap
PLIST_SUB+=		ICAPCONF=""
.else
PLIST_SUB+=		ICAPCONF="@comment "
.endif

.if defined(WITH_DG_KASP)
CONFIGURE_ARGS+=	--enable-kavd
PLIST_SUB+=		KAVDCONF=""
.else
PLIST_SUB+=		KAVDCONF="@comment "
.endif

.if defined(WITH_DG_CLAMD) || defined(WITH_DG_ICAP) || defined(WITH_DG_KASP) || defined(WITH_CLISCANCONF)
PLIST_SUB+=		SCANNERS=""
.else
PLIST_SUB+=		SCANNERS="@comment "
.endif

.if !defined(WITHOUT_DG_DMGR)
CONFIGURE_ARGS+=	--enable-fancydm
#PLIST_SUB+=		DMGR=""
#.else
#PLIST_SUB+=		DMGR="@comment "
.endif

.if defined(WITH_DG_NTLM)
CONFIGURE_ARGS+=	--enable-ntlm
PLIST_SUB+=		NTLMCONF=""
.else
PLIST_SUB+=		NTLMCONF="@comment "
.endif

.if defined(WITH_DG_EMAIL)
CONFIGURE_ARGS+=	--enable-email
PLIST_SUB+=		EMAILCONF=""
.else
PLIST_SUB+=		EMAILCONF="@comment "
.endif

.if defined(WITH_DG_DEBUG)
CONFIGURE_ARGS+=	--enable-dgdebug
.endif

# User needs to manually download the distfile
.if !(exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})) && !defined(PACKAGE_BUILDING)
IGNORE=	commercial source download is restricted.  Please visit and read ${DG_URL} and download ${DISTNAME}${EXTRACT_SUFX} into ${DISTDIR} before running make
.endif

post-install:
# Display post-install message
	@${CAT} pkg-message

.include <bsd.port.post.mk>
