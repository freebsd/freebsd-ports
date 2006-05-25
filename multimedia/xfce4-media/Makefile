# New ports collection makefile for:	Xfce4-media
# Date created:		23 October 2004
# Whom:			Matt Lancereau <ports@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-media
PORTVERSION=	0.9.1
CATEGORIES=	multimedia xfce
MASTER_SITES=	http://spuriousinterrupt.org/files/xfmedia/
DISTNAME=	xfmedia-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	r.c.ladan@gmail.com
COMMENT=	Lightweight media player for Xfce4 based on the xine engine

LIB_DEPENDS=	xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		xine.15:${PORTSDIR}/multimedia/libxine \
		exo-0.3.0:${PORTSDIR}/x11/libexo

USE_BZIP2=	yes
USE_GETOPT_LONG=yes
USE_GETTEXT=	yes
#NLS is hardcoded to "yes" in source, so no WITHOUT_NLS
USE_GMAKE=	yes
USE_GNOME=	libxml2 intlhack
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g" \
		${WRKSRC}/xfmedia/Makefile.in

.include <bsd.port.mk>
