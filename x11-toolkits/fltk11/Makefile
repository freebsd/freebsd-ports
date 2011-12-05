# New ports collection makefile for:   	fltk11
# Date created:				5 December 2011
# Whom:                			Diane Bruce db@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	fltk11
PORTVERSION=	1.1.10
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_EASYSW}
MASTER_SITE_SUBDIR=	fltk/${PORTVERSION}
DISTNAME=	${OPORTNAME}-${PORTVERSION}-source

MAINTAINER=	db@FreeBSD.org
COMMENT=	Cross-platform C++ graphical user interface toolkit

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_XORG=	xft
USE_GL=		gl glu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-threads \
		--enable-shared \
		--enable-xft \
		--libdir=${PREFIX}/lib/${PORTNAME} \
		--bindir=${PREFIX}/bin/${PORTNAME} \
		--includedir=${PREFIX}/include/${PORTNAME}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPORTNAME=	fltk
WRKSRC=		${WRKDIR}/${OPORTNAME}-${PORTVERSION}

DEPRECATED=	new code should use /x11-toolkits/fltk
EXPIRATION=	2013-01-01

post-patch:
	${REINPLACE_CMD} -e '30s/test //' ${WRKSRC}/Makefile

.include <bsd.port.mk>
