# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	BRiAl
PORTVERSION=	1.2.8
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Library for polynomials over boolean rings

LICENSE=	GPLv2

LIB_DEPENDS=	libm4ri.so:math/m4ri		\
		libgd.so:graphics/gd		\
		libpng.so:graphics/png		\
		libboost_thread.so:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	BRiAl

USES=		autoreconf compiler:c++11-lang libtool localbase pkgconfig

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

TEST_TARGET=	check

.include <bsd.port.mk>
