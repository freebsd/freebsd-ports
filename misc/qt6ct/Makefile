PORTNAME=	qt6ct
DISTVERSION=	0.9
PORTREVISION=	3
CATEGORIES=	misc

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Qt 6 configuration tool
WWW=		https://github.com/trialuser02/qt6ct/tags

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers

USES=		cmake compiler:c++11-lang gettext-runtime gl qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	trialuser02
USE_GL=		gl opengl
USE_QT=		base svg tools

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR} && \
	${INSTALL_DATA}	${WRKSRC}/README ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
