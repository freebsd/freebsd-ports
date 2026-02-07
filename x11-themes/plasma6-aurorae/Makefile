PORTNAME=	aurorae
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11-themes kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Themeable window decoration for KWin

USES=		cmake gettext gl kde:6 qt:6 shebangfix tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	colorscheme config coreaddons decoration i18n \
		kcmutils newstuff package \
		ecm:build \
		svg:run
USE_QT=		base declarative tools
USE_XORG=	x11

SHEBANG_FILES=	src/plasma-apply-aurorae.cmake
bash_CMD=	/bin/sh

.include <bsd.port.mk>
