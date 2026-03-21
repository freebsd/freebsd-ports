PORTNAME=	m4rie
DISTVERSION=	20250128
CATEGORIES=	math
#MASTER_SITES=	https://bitbucket.org/malb/${PORTNAME:tl}/downloads/
#DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for fast arithmetic with dense matrices over GF(2^e)
WWW=		https://bitbucket.org/malb/m4rie/src/master/

LICENSE=	GPLv2+

LIB_DEPENDS=	libm4ri.so:math/m4ri

USES=		autoreconf libtool localbase:ldflags pathfix pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	malb

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
