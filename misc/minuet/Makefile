PORTNAME=	minuet
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	misc education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE software for music education
WWW=		https://apps.kde.org/minuet/

LIB_DEPENDS=	libaubio.so:audio/aubio \
		libfluidsynth.so:audio/fluidsynth

USES=		cmake compiler:c++17-lang gettext kde:6 pkgconfig qt:6 tar:xz
USE_KDE=	coreaddons crash doctools i18n kirigami-addons kirigami2 \
		qqc2-desktop-style \
		ecm:build
USE_QT=		base declarative multimedia svg

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
