# $FreeBSD$

PORTNAME=	libass
PORTVERSION=	0.10.2
CATEGORIES=	multimedia devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Portable ASS/SSA subtitle renderer

LICENSE=	ISCL

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libenca.so:${PORTSDIR}/converters/enca \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libfribidi.so:${PORTSDIR}/converters/fribidi

USES=	pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so.*

.include <bsd.port.mk>
