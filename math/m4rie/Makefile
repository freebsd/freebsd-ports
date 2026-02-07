PORTNAME=	M4RIE
DISTVERSION=	20250103
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/malb/${PORTNAME:tl}/downloads/
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for fast arithmetic with dense matrices over GF(2^e)
WWW=		https://bitbucket.org/malb/m4rie/src/master/

LICENSE=	GPLv2+

LIB_DEPENDS=	libm4ri.so:math/m4ri

USES=		autoreconf libtool localbase:ldflags pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_SUB=	VER=${PORTVERSION}

.include <bsd.port.mk>
