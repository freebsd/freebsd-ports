# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	i2pd
PORTVERSION=	2.3.0
CATEGORIES=	security net-p2p

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++ implementation of I2P client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

BROKEN_FreeBSD_9=	does not build

USE_GITHUB=	yes
GH_ACCOUNT=	PurpleI2P

USES=		cmake compiler:c++11-lib
CMAKE_SOURCE_PATH=${WRKSRC}/build
USE_OPENSSL=	yes

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	AESNI UPNP DOCS

AESNI_DESC=	Use AES-NI instructions set
AESNI_CMAKE_ON=	-DWITH_AESNI=ON
AESNI_CMAKE_OFF=-DWITH_AESNI=OFF

UPNP_DESC=	Include support for UPnP client
UPNP_CMAKE_ON=	-DWITH_UPNP=ON
UPNP_CMAKE_OFF=	-DWITH_UPNP=OFF
UPNP_LIB_DEPENDS=libminiupnpc.so:net/miniupnpc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/debian/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/configuration.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
