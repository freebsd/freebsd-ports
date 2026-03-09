PORTNAME=	kamoso
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	multimedia kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Application to take pictures and videos out of your webcam
WWW=		https://apps.kde.org/kamoso/

LICENSE=	GPLv2

RUN_DEPENDS=	frei0r>0:graphics/frei0r

USES=		cmake compiler:c++20-lang gettext gl gnome gstreamer kde:6 \
		pkgconfig qt:6 tar:xz xorg
USE_GL=		gl
USE_GNOME=	glib20
USE_GSTREAMER=	qt6 v4l2
USE_KDE=	config i18n kio notifications purpose \
		doctools:build ecm:build \
		kirigami2:run
USE_QT=		base declarative
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

# Remove at 13.5-RELEASE EOL:
.if !exists(/usr/bin/clang-scan-deps)
USES+=		llvm
.endif

.include <bsd.port.mk>
