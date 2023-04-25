PORTNAME=	plank-player
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	multimedia kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 Bigscreen Multimedia Player
WWW=		https://www.kde.org/plasma-desktop

USES=		cmake compiler:c++11-lib desktop-file-utils gettext kde:5 \
		pkgconfig qt:5 shebangfix tar:xz
USE_KDE=	ecm i18n kirigami2
USE_QT=		core declarative gui multimedia network quickcontrols2 \
		buildtools:build qmake:build

.include <bsd.port.mk>
