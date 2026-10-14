PORTNAME=	union
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-themes kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt style engine supporting both QtQuick and QtWidgets.

LIB_DEPENDS=	libcxx-rust-cssparser.so:devel/cxx-rust-cssparser

USES=		cmake compiler:c++20-lang gl kde:6 localbase qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	colorscheme config coreaddons \
		guiaddons iconthemes kirigami2 \
		ecm:build
# Plasma components
USE_KDE+=	breeze
USE_QT=		base declarative shadertools

.include <bsd.port.mk>
