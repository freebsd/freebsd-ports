PORTNAME=	qt6ct
DISTVERSION=	0.11
CATEGORIES=	misc
MASTER_SITES=	https://www.opencode.net/api/v4/projects/5459/packages/generic/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 6 configuration tool
WWW=		https://www.opencode.net/trialuser/qt6ct/

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang gl qt:6 tar:xz
USE_GL=		opengl
USE_QT=		base svg:run tools:build

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
