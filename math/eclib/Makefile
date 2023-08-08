PORTNAME=	eclib
PORTVERSION=	20230424
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	C++ library for arithmetic on elliptic curves
WWW=		https://homepages.warwick.ac.uk/staff/J.E.Cremona/mwrank/

LICENSE=	GPLv2

LIB_DEPENDS=	libntl.so:math/ntl		\
		libpari.so:math/pari		\
		libflint.so:math/flint2		\
		libboost_thread.so:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	JohnCremona

USES=		autoreconf compiler:c++11-lang libtool localbase

OPTIONS_DEFINE=	DOCS

CXXFLAGS+=	-std=c++11
LIBS+=		"-lm"
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-flint=${LOCALBASE} --with-boost=${LOCALBASE}
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
