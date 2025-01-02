PORTNAME=	M4RIE
PORTVERSION=	20250102
DISTVERSIONPREFIX=	release-
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Library for fast arithmetic with dense matrices over GF(2^e)
WWW=		https://bitbucket.org/malb/m4rie/src/master/

LICENSE=	GPLv2+

LIB_DEPENDS=	libm4ri.so:math/m4ri

USE_GITHUB=	yes
GH_ACCOUNT=	malb
GH_PROJECT=	${PORTNAME:tl}

USES=		autoreconf libtool localbase pathfix pkgconfig

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

TEST_TARGET=	check

.include <bsd.port.mk>
