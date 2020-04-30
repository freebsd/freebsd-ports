# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	libhomfly
DISTVERSION=	1.02r6
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Library to compute the homfly polynomial of knots and link

LICENSE=	PD

LIB_DEPENDS=	libgc-threaded.so:devel/boehm-gc-threaded

USE_GITHUB=	yes
GH_ACCOUNT=	miguelmarco

USES=		autoreconf libtool localbase

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
TEST_TARGET=	check

PLIST_FILES=	include/homfly.h	\
		lib/libhomfly.a		\
		lib/libhomfly.so	\
		lib/libhomfly.so.0	\
		lib/libhomfly.so.0.0.0

.include <bsd.port.mk>
