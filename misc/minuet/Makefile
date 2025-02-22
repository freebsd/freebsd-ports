PORTNAME=	minuet
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	misc education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE software for music education
WWW=		https://apps.kde.org/minuet/

LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth

USES=		cmake compiler:c++17-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	coreaddons crash i18n \
		ecm:build
USE_QT=		base declarative

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
