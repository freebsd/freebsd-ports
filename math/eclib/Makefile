# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	eclib
PORTVERSION=	20210223
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	C++ library for arithmetic on elliptic curves

LICENSE=	GPLv2

LIB_DEPENDS=	libntl.so:math/ntl		\
		libpari.so:math/pari		\
		libflint.so:math/flint2		\
		libboost_thread.so:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	JohnCremona

USES=		autoreconf compiler:c++11-lang libtool localbase

OPTIONS_DEFINE=	DOCS

LIBS+=		"-lm"
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-flint=${LOCALBASE} --with-boost=${LOCALBASE}
USE_LDCONFIG=	yes

.include <bsd.port.mk>
