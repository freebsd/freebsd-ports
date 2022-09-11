PORTNAME=	libkeduvocdocument
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	misc kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for reading and writing vocabulary files
WWW=		https://edu.kde.org/

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	archive config coreaddons i18n kio service \
		ecm:build
USE_QT=		concurrent core dbus gui network xml \
		buildtools:build qmake:build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
