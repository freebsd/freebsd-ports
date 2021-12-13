PORTNAME=	MetaPhysicL
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.3
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Metaprogramming, operator-overloaded classes for numerical simulations

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/date_time/posix_time/posix_time.hpp:devel/boost-libs

USES=		autoreconf gmake libtool
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libMesh
GH_TUPLE=	libMesh:autoconf-submodule:a993d79:autoconf_submodule/m4/autoconf-submodule

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

INSTALL_TARGET=	install-strip

TEST_TARGET=	check

.include <bsd.port.mk>
