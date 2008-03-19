# New ports collection makefile for:	xfe
# Date created:				Sun, Jul 13 2003
# Whom:					ptiJo
#
# $FreeBSD$
#

PORTNAME=	xfe
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast MS-Explorer like filemanager for X

LIB_DEPENDS=	FOX-1.6:${PORTSDIR}/x11-toolkits/fox16 \
		png.5:${PORTSDIR}/graphics/png

USE_GNOME=	gnomehack gnometarget
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--x-includes=${LOCALBASE}/include \
		--x-libraries=${LOCALBASE}/lib \
		--with-x

MAN1=		xfe.1 xfi.1 xfp.1 xfv.1 xfw.1

CPPFLAGS=	`pkg-config --cflags-only-I freetype2` -I${LOCALBASE}/include
LDFLAGS=	`pkg-config --libs-only-L freetype2` -L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|^CXXFLAGS="-O2"||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-I/usr/include/fox|# -I/usr/include/fox|g' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
