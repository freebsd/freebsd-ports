PORTNAME=	eclib
PORTVERSION=	20250627
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	C++ library for arithmetic on elliptic curves
WWW=		https://johncremona.github.io/mwrank/index.html

LICENSE=	GPLv2

LIB_DEPENDS=	libntl.so:math/ntl		\
		libpari.so:math/pari		\
		libflint.so:math/flint2		\
		libboost_thread.so:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	JohnCremona

USES=		autoreconf compiler:c++17-lang libtool localbase

OPTIONS_DEFINE=	DOCS

LIBS+=		"-lm"
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_CXXSTD=	c++17
CONFIGURE_ARGS=	--with-flint=${LOCALBASE} --with-boost=${LOCALBASE}
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
