PORTNAME=	M4RI
DISTVERSIONPREFIX=	release-
DISTVERSION=	20240729
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for fast arithmetic with dense matrices over F2
WWW=		https://bitbucket.org/malb/m4ri/src/master/

LICENSE=	GPLv2+

LIB_DEPENDS=	libpng.so:graphics/png

USE_GITHUB=	yes
GH_ACCOUNT=	malb
GH_PROJECT=	${PORTNAME:tl}

USES=		autoreconf libtool:ldflags localbase pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.if defined(MAINTAINER_MODE)
TEST_TARGET=	check
# Only needed for tests
USES+=		gmake
.endif

.include <bsd.port.mk>
