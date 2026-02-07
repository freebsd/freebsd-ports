PORTNAME=	sonnet
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	textproc kde kde-frameworks

COMMENT=	Multi-language spell checker
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libaspell.so:textproc/aspell \
		libhunspell-1.7.so:textproc/hunspell

USES=		cmake gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	ecm:build
USE_QT=		base declarative tools

# Hsplell can be enabled, Voikko is not ported.
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_HSPELL \
		CMAKE_DISABLE_FIND_PACKAGE_VOIKKO

.include <bsd.port.mk>
