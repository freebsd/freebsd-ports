# New ports collection makefile for:	rox-session
# Date created:        11 March 2001
# Whom:                Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$

PORTNAME=	rox-session
PORTVERSION=	0.1.18
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rox
DISTNAME=	ROX-Session-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	olgeni@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20 \
		xml2.5:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	${LOCALBASE}/bin/rox:${PORTSDIR}/x11-fm/rox-filer

WRKSRC=		${WRKDIR}/ROX-Session-${PORTVERSION}

.include <bsd.port.pre.mk>

.if (${ARCH} == "i386")
BINARIES=	FreeBSD-ix86
.else
BINARIES=	FreeBSD-${ARCH}
.endif

PLIST_SUB=	BINARIES="${BINARIES}"

do-build:
	# Run the custom build procedure
	@cd ${WRKSRC}/ROX-Session && GTK_CONFIG=${GTK_CONFIG} GLIB_CONFIG=${GLIB_CONFIG} ./AppRun --compile

do-install:
	@${MKDIR} ${PREFIX}/apps/ROX-Session
	@cd ${WRKSRC}/ROX-Session && ${CP} -r .DirIcon AppInfo.xml AppRun ${BINARIES} Help Login MakeDefault.sh Messages Options.xml Setup SetupPanel Styles WindowMans images ${PREFIX}/apps/ROX-Session
	@${CAT} ${FILESDIR}/rox-session | ${SED} -e "s|%%PREFIX%%|${PREFIX}|" > ${PREFIX}/bin/rox-session
	@${CHMOD} 775 ${PREFIX}/bin/rox-session

.include <bsd.port.post.mk>
