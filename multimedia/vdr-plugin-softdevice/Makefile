# New ports collection makefile for:	vdr-plugin-softdevie
# Date created:		Wed Apr 14 18:11:42 CEST 2010
# Whom:			Juergen Lock <nox@freebsd.org>
#
# $FreeBSD$
#

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

USE_BZIP2=	yes
USE_GNOME+=	pkgconfig
USE_XORG+=	xv x11 xinerama
PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/${PLUGIN}
CONFIGURE_ARGS+=	--disable-vidix --disable-fb --disable-dfb --disable-cle266 --disable-alsa #--disable-yaepg

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin
	${REINPLACE_CMD} 's|/usr/X11R6|${LOCALBASE}|' ${WRKSRC}/Makefile ${WRKSRC}/configure

do-configure:
	(cd ${WRKSRC} && ./configure ${CONFIGURE_ARGS})

post-install: post-install-pluginlocales
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
