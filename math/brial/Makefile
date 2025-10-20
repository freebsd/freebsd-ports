PORTNAME=	BRiAl
DISTVERSION=	1.2.12
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for polynomials over boolean rings
WWW=		https://github.com/BRiAl/BRiAl

LICENSE=	GPLv2

LIB_DEPENDS=	libm4ri.so:math/m4ri		\
		libgd.so:graphics/gd		\
		libpng.so:graphics/png		\
		libboost_thread.so:devel/boost-libs

USES=		autoreconf compiler:c++11-lang libtool localbase:ldflags \
		pkgconfig tar:bz2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
