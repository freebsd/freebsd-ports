PORTNAME=	alps
DISTVERSIONPREFIX=	releases/
DISTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Abstract Library for Parallel Search (ALPS)
WWW=		https://github.com/coin-or/CHiPPS-ALPS

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/Alps/LICENSE

LIB_DEPENDS=	libCoinUtils.so:math/coinutils \
		libopenblas.so:math/openblas

USES=		blaslapack gmake libtool pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	CHiPPS-ALPS

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

post-patch:
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
	@${REINPLACE_CMD} -e 's|std::unary_function|std::__unary_function|' \
		${WRKSRC}/Alps/src/AlpsHelperFunctions.h
.endif

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share

.include <bsd.port.mk>
