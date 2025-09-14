PORTNAME=	intel-pcm
DISTVERSION=	202405
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	imp@FreeBSD.org
COMMENT=	Process Count Monitor (PCM) for Intel processors
WWW=		https://github.com/intel/pcm

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libsimdjson.so:devel/simdjson

USES=		cmake compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	intel
GH_PROJECT=	pcm

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|-O3 -D_FORTIFY_SOURCE=1|-D_FORTIFY_SOURCE=1|g' \
	    ${PATCH_WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|$${CMAKE_INSTALL_DATADIR}/pcm|$${CMAKE_INSTALL_DATADIR}/${PORTNAME}|g' \
	    ${PATCH_WRKSRC}/src/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|$${CMAKE_INSTALL_DOCDIR}|$${CMAKE_INSTALL_DATADIR}/doc/${PORTNAME}|g' \
	    ${PATCH_WRKSRC}/src/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|/usr/share/pcm/|${DATADIR}/|g' \
	     ${PATCH_WRKSRC}/src/pcm-raw.cpp
	@${REINPLACE_CMD} -e 's|/usr/share/pcm/|${DATADIR}/|g' \
	     ${PATCH_WRKSRC}/src/utils.cpp

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/licenses

.include <bsd.port.mk>
