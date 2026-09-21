PORTNAME=	union
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11-themes kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt style engine supporting both QtQuick and QtWidgets.

USES=		cmake compiler:c++20-lang kde:6 qt:6 tar:xz
USE_KDE=	colorscheme config coreaddons \
		guiaddons iconthemes kirigami2 \
		ecm:build
# Plasma components
USE_KDE+=	breeze
USE_QT=		base declarative shadertools

# Requires cxx-rust-cssparser
CMAKE_OFF=	BUILD_INPUT_CSS

.include <bsd.port.mk>
