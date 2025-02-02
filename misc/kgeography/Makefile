PORTNAME=	kgeography
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	misc education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE geography trainer
WWW=		https://edu.kde.org/kgeography

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons crash doctools \
		i18n iconthemes itemviews service widgetsaddons xmlgui \
		ecm:build
USE_QT=		base

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
