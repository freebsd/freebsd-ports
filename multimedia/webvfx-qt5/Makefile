# $FreeBSD$

PORTNAME=	webvfx
DISTVERSION=	0.4.4-20160823
PORTREVISION=	11
CATEGORIES=	multimedia
PKGNAMESUFFIX=	-qt5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video effects library based on HTML/QML

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmlt.so:multimedia/mlt

USE_GITHUB=	yes
GH_ACCOUNT=	mltframework
GH_TAGNAME=	e918ce4

USES=		compiler:c++11-lang pkgconfig qmake qt:5
USE_QT=		3d buildtools_build declarative opengl webkit
USE_LDCONFIG=	yes

PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOXYGEN EXAMPLES
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

post-patch-EXAMPLES-on:
	@${REINPLACE_CMD} -i '' -e 's,examples/,,g' ${WRKSRC}/demo/mlt/*

pre-configure:
# Fix make jobs and speed up build.
	@${REINPLACE_CMD} -e 's/debug_and_release//' ${WRKSRC}/common.pri

post-build-DOXYGEN-on:
	cd ${WRKSRC} && ${MAKE} doxydoc

post-install-DOXYGEN-on:
	cd ${WRKSRC}/doxydoc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	cd ${WRKSRC}/demo/examples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/demo && \
		${COPYTREE_SHARE} mlt ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
