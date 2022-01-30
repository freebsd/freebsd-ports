PORTNAME=	pffft
PORTVERSION=	g20210806
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pretty Fast FFT (PFFFT) library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	marton78
GH_TAGNAME=	9603871

CMAKE_ON=	BUILD_SHARED_LIBS INSTALL_PFDSP INSTALL_PFFASTCONV

post-install: # move headers into a dedicated directory
	cd ${STAGEDIR}${PREFIX} && \
		${MKDIR} include/${PORTNAME} && \
		${MV} include/*.h include/*.hpp include/${PORTNAME}

.include <bsd.port.mk>
