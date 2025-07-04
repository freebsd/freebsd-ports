PORTNAME=	xxdiff
CATEGORIES=	textproc

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Graphical file and directories comparator and merge tool
WWW=		http://furius.ca/xxdiff/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVOR?=	${FLAVORS:[1]}
FLAVORS=	qt5 qt6
qt5_PKGNAMEPREFIX=	qt5-
qt6_PKGNAMEPREFIX=	qt6-

USES=		bison gl gmake
USE_GL=		gl

.if ${FLAVOR} == qt5
USES+=		qt:5
USE_QT=		core gui buildtools:build qmake:build widgets
.else
USES+=		qt:6
USE_QT=		base
.endif

BUILD_WRKSRC=	${WRKSRC}/src

PLIST_FILES=	bin/xxdiff
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

pre-build:
	@(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} QMAKE=${QMAKE} \
		${MAKE_CMD} -f Makefile.bootstrap ${MAKE_ARGS} Makefile)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/xxdiff ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "${PORTDOCS} ! -name Makefile" \
		${STAGEDIR}/${DOCSDIR}

.include "Makefile.master"
