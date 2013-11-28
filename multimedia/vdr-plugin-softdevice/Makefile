# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-softdevice
PORTVERSION=	0.5.0p20100414
PORTREVISION=	15
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	nox/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - softdevice plugin

LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg

USES=		pkgconfig
USE_BZIP2=	yes
USE_XORG+=	xv x11 xinerama
PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
WRKSRC=		${WRKDIR}/${PLUGIN}
CONFIGURE_ARGS+=	--disable-vidix --disable-fb --disable-dfb --disable-cle266 --disable-alsa #--disable-yaepg
BROKEN=		Broken after ffmpeg update (not sure it ever worked)
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=	2014-01-31

NO_STAGE=	yes

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin
	${REINPLACE_CMD} 's|/usr/X11R6|${LOCALBASE}|;s|g\+\+|${CXX}|' ${WRKSRC}/Makefile ${WRKSRC}/configure

do-configure:
	(cd ${WRKSRC} && ./configure ${CONFIGURE_ARGS})

post-install: post-install-pluginlocales
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
