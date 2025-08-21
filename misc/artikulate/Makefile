PORTNAME=	artikulate
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	misc education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Pronunciation trainer for KDE
WWW=		https://edu.kde.org/

USES=		cmake compiler:c++11-lang gettext gnome kde:6 qt:6 tar:xz
USE_GNOME=	libxml2
USE_KDE=	archive config crash i18n itemmodels kirigami2 newstuff \
		doctools:build ecm:build
USE_QT=		base declarative multimedia
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
