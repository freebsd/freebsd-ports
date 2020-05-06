# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	iml
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.cs.uwaterloo.ca/~astorjoh/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Integer Matrix Library

LICENSE=	GPLv2

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		blaslapack:openblas libtool localbase tar:bz2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cblas=${LAPACKLIB} --enable-shared
USE_LDCONFIG=	yes

TEST_TARGET=	check

.include <bsd.port.mk>
