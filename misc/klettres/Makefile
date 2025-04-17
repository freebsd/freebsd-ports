PORTNAME=	klettres
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	misc education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Alphabet learning tool for KDE
WWW=		https://edu.kde.org/klettres

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	attica auth codecs completion config configwidgets coreaddons \
		crash i18n itemmodels newstuff phonon service widgetsaddons \
		xmlgui \
		doctools:build ecm:build
USE_QT=		base multimedia

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
