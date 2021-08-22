PORTNAME=	normaliz
DISTVERSIONPREFIX=	v
DISTVERSION=	3.9.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool for computations in affine monoids, vector configurations, etc

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp \
		libnauty.so:math/nauty

USES=		autoreconf gmake libtool localbase
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Normaliz
GH_PROJECT=	Normaliz

GNU_CONFIGURE=	yes

TEST_TARGET=	check # at least one test is known to fail: https://github.com/Normaliz/Normaliz/issues/378

.include <bsd.port.mk>
