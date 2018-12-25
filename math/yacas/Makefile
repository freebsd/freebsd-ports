# Created by: ijliao
# $FreeBSD$

PORTNAME=	yacas
PORTVERSION=	1.6.0
PORTREVISION=	4
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Yet Another Computer Algebra System

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	bash:shells/bash

OPTIONS_DEFINE=	DOCS
DOCS_CMAKE_ON=	-DENABLE_DOCS:BOOL=ON \
		-DDOCSDIR:STRING=${DOCSDIR_REL} \
		-DENABLE_CYACAS_CONSOLE:BOOL=ON \
		-DENABLE_CYACAS_KERNEL:BOOL=OFF \
		-DENABLE_CYACAS_GUI:BOOL=OFF \
		-DENABLE_JYACAS:BOOL=OFF
DOCS_BUILD_DEPENDS=	sphinx-autogen:textproc/py-sphinx

PORTDOCS=	*

TEST_TARGET=	test

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	grzegorzmazur

PLIST_SUB=	SHLIB_VERSION=${PORTVERSION:S/.//}.0

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == "gcc"
CXXFLAGS+=	-D_GLIBCXX_USE_C99
.endif

post-patch:
#	Can't use USES=shebangfix here, cause the path appears several
#	times in the file.
	@${REINPLACE_CMD} -e 's| /bin/bash| ${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/tests/test-yacas
	@${REINPLACE_CMD} -e '/^install/s|^|#|' \
		${WRKSRC}/tests/CMakeLists.txt
.include <bsd.port.post.mk>
