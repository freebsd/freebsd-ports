# $FreeBSD$

PORTNAME=	libass
PORTVERSION=	0.10.1
CATEGORIES=	multimedia devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Portable ASS/SSA subtitle renderer

LICENSE=	ISCL

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2 \
		enca:${PORTSDIR}/converters/enca \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		expat:${PORTSDIR}/textproc/expat2 \
		fribidi:${PORTSDIR}/converters/fribidi

USES=	pathfix pkgconfig
USE_XZ=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
