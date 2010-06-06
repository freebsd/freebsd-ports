# New ports collection makefile for:	dansguardian
# Date created:				March 26, 2002
# Whom:					Freddie Cash <fcash@sd73.bc.ca>
#
# $FreeBSD$
#

PORTNAME=	dansguardian
PORTVERSION=	2.10.1.1
CATEGORIES=	www
MASTER_SITES=	# empty, see below

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast, feature-rich web content filter for Squid proxy servers

RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre

USE_RC_SUBR=	dansguardian
USE_GNOME=	pkgconfig

CONFLICTS=	dansguardian-2.[6789]*
LATEST_LINK=	dansguardian

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-logdir=/var/log \
		--with-piddir=/var/run \
		--with-libiconv=${LOCALBASE} \
		--enable-fancydm

MAN8=		dansguardian.8

OPTIONS=	APACHE  "Enable Apache support for access denied page" on \
		TRICKLE "Enable the trickle download manager" on \
		CLISCAN "Enable support for CLI content scanners" off \
		CLAMD   "Enable ClamAV daemon support (clamd)" off \
		ICAP    "Enable ICAP AV content scanner support (testing)" off \
		KAV     "Enable Kaspersky AV support (testing)" off \
		NTLM    "Enable NTLM authentication plugin" off \
		EMAIL   "Enable e-mail reporting support" off \
		DEBUG   "Enable debug options - not for production use" off

DG_URL=		http://dansguardian.org/index.php?page=copyright2
CONFDIR=	${PREFIX}/etc/dansguardian

RESTRICTED=	Redistribution and commercial download is restricted.  Check ${DG_URL} for more info

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_APACHE)
USE_APACHE=	1.3+
.endif

.if !defined(WITHOUT_TRICKLE)
CONFIGURE+=		--enable-trickledm
PLIST_SUB+=		TRICKLECONF=""
.else
PLIST_SUB+=		TRICKLECONF="@comment "
.endif

.if defined(WITH_CLISCAN)
CONFIGURE_ARGS+=	--enable-commandline
PLIST_SUB+=		CLISCANCONF=""
.else
PLIST_SUB+=		CLISCANCONF="@comment "
.endif

.if defined(WITH_CLAMD)
CONFIGURE_ARGS+=	--enable-clamd
RUN_DEPENDS+=		${LOCALBASE}/sbin/clamd:${PORTSDIR}/security/clamav
PLIST_SUB+=		CLAMDCONF=""
.else
PLIST_SUB+=		CLAMDCONF="@comment "
.endif

.if defined(WITH_ICAP)
CONFIGURE_ARGS+=	--enable-icap
PLIST_SUB+=		ICAPCONF=""
.else
PLIST_SUB+=		ICAPCONF="@comment "
.endif

.if defined(WITH_KAV)
CONFIGURE_ARGS+=	--enable-kavd
PLIST_SUB+=		KAVDCONF=""
.else
PLIST_SUB+=		KAVDCONF="@comment "
.endif

.if defined(WITH_CLAMD) || defined(WITH_ICAP) || defined(WITH_KAV) || defined(WITH_CLISCAN)
PLIST_SUB+=		SCANNERS=""
.else
PLIST_SUB+=		SCANNERS="@comment "
.endif

.if defined(WITH_NTLM)
CONFIGURE_ARGS+=	--enable-ntlm --with-libiconv=${LOCALBASE}
USE_ICONV=	yes
PLIST_SUB+=		NTLMCONF=""
.else
PLIST_SUB+=		NTLMCONF="@comment "
.endif

.if defined(WITH_EMAIL)
CONFIGURE_ARGS+=	--enable-email
PLIST_SUB+=		EMAILCONF=""
.else
PLIST_SUB+=		EMAILCONF="@comment "
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--with-dgdebug
.endif

#.if defined(NOPORTDOCS)
#PLISTSUB+=              DOCINST="@comment "
#.else
#PLISTSUB+=              DOCINST=""
#.endif

# User needs to manually download the distfile
.if !(exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})) && !defined(PACKAGE_BUILDING)
IGNORE=	commercial source download is restricted.  Please visit and read ${DG_URL} and download ${DISTNAME}${EXTRACT_SUFX} into ${DISTDIR} before running make
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/install-data-am/ s|install-dist_docDATA||' \
		${WRKSRC}/doc/Makefile.in
.endif

post-install:
# Display post-install message
	@${CAT} pkg-message

.include <bsd.port.post.mk>
