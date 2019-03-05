# Created by: Axel Steiner <ast@treibsand.com>
# $FreeBSD$

PORTNAME=	libcmime
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.libcmime.org/files/

MAINTAINER=	ast@treibsand.com
COMMENT=	Lightweight C mime library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison cmake:insource,noninja pkgconfig
USE_LDCONFIG=	yes
CMAKE_ARGS=	--no-warn-unused-cli

PORTDOCS=	AUTHORS CHANGELOG INSTALL README

OPTIONS_DEFINE=	DEBUG DOCS DOXYGEN
OPTIONS_SUB=	yes

DOCS_ALL_TARGET=	doc
DEBUG_CMAKE_BOOL=	ENABLE_DEBUG
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen>=1.8:devel/doxygen \
			dot:graphics/graphviz
DOXYGEN_CMAKE_BOOL=	ENABLE_DOC

post-patch:
	@${REINPLACE_CMD} -E -e 's|\$$\{CMAKE_INSTALL_LIBDIR}(/pkgconfig)|$${CMAKE_INSTALL_PREFIX}/libdata\1|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD}  -e 's|libcmime-\$${CMIME_MAJOR_VERSION}.\$${CMIME_MINOR_VERSION}.\$${CMIME_MICRO_VERSION}|libcmime|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -E -e 's|STRIP_FROM_PATH        = ../src|STRIP_FROM_PATH        = ../|' \
		${WRKSRC}/Doxyfile.cmake

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install-DOXYGEN-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
