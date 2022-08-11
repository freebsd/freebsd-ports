PORTNAME=	M4RIE
PORTVERSION=	20200115
DISTVERSIONPREFIX=	release-
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Library for fast arithmetic with dense matrices over GF(2^e)

LICENSE=	GPLv2+

LIB_DEPENDS=	libm4ri.so:math/m4ri

USE_GITHUB=	yes
GH_ACCOUNT=	malb
GH_PROJECT=	${PORTNAME:tl}

USES=		autoreconf libtool localbase pkgconfig

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

TEST_TARGET=	check

.include <bsd.port.mk>
