# New ports collection makefile for:	rox-session
# Date created:        11 March 2001
# Whom:                Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$

PORTNAME=	rox-session
PORTVERSION=	0.1.21
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rox
DISTNAME=	ROX-Session-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A session manager for the ROX desktop

RUN_DEPENDS=	${LOCALBASE}/bin/rox:${PORTSDIR}/x11-fm/rox-filer

WRKSRC=		${WRKDIR}/ROX-Session-${PORTVERSION}

USE_GNOME=	gtk20 pkgconfig libxml2
USE_AUTOCONF=	yes
HAS_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if (${ARCH} == "i386")
BINARIES=	FreeBSD-ix86
.else
BINARIES=	FreeBSD-${ARCH}
.endif

PLIST_SUB=	BINARIES="${BINARIES}"

CONFIGURE_ARGS=		--enable-rox --with-platform=${BINARIES}
CONFIGURE_WRKSRC=	${WRKSRC}/ROX-Session/src
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
ALL_TARGET=

do-build:
	# Run the custom build procedure
	@cd ${WRKSRC}/ROX-Session && GTK_CONFIG=${GTK_CONFIG} GLIB_CONFIG=${GLIB_CONFIG} ./AppRun --compile

do-install:
	@${MKDIR} ${PREFIX}/apps/ROX-Session
	@cd ${WRKSRC}/ROX-Session && ${CP} -r .DirIcon AppInfo.xml AppRun ${BINARIES} Help Login MakeDefault.sh Messages Options.xml RunROX Setup SetupPanel Styles WindowMans images ${PREFIX}/apps/ROX-Session
	@${CAT} ${FILESDIR}/rox-session | ${SED} -e "s|%%PREFIX%%|${PREFIX}|" > ${PREFIX}/bin/rox-session
	@${CHMOD} 775 ${PREFIX}/bin/rox-session

.include <bsd.port.post.mk>
