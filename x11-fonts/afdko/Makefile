PORTNAME=	afdko
PORTVERSION=	5.0.1
CATEGORIES=	x11-fonts
MASTER_SITES=	PYPI \
		https://github.com/adobe-type-tools/afdko/releases/download/${PORTVERSION}/
DISTFILES=	afdko-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Adobe Font Development Kit for OpenType (AFDKO)
WWW=		https://adobe-type-tools.github.io/afdko/ \
		https://github.com/adobe-type-tools/afdko

LICENSE=	APACHE20

LIB_DEPENDS=	libantlr4-runtime.so:devel/antlr4-cpp-runtime

USES=		cmake compiler:c++11-lang gnome python:build
USE_GNOME=	libxml2
USE_PYTHON=	cython

CMAKE_ARGS=	-DSKBUILD_PROJECT_VERSION=${PORTVERSION}
CMAKE_OFF=	SKBUILD

PLIST_FILES=	${PYTHON_SITELIBDIR}/afdko/_internal${PYTHON_TAG}.so

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/third_party/

.include <bsd.port.mk>
