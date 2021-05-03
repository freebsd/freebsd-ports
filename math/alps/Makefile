PORTNAME=	alps
DISTVERSIONPREFIX=	releases/
DISTVERSION=	2.0.1
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Abstract Library for Parallel Search (ALPS)

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/Alps/LICENSE

LIB_DEPENDS=	libCoinUtils.so:math/clp

USES=		blaslapack gmake libtool pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	CHiPPS-ALPS

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share

.include <bsd.port.mk>
