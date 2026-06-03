PORTNAME=	angelfish
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	www kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Web browser for Plasma Mobile and Desktop
WWW=		https://apps.kde.org/angelfish/

LIB_DEPENDS=	libQCoro6Core.so:devel/qcoro \
		libfuturesql6.so:databases/futuresql

USES=		cmake desktop-file-utils gettext kde:6 pkgconfig qt:6 tar:xz
USE_KDE=	config coreaddons crash dbusaddons i18n kirigami-addons \
		kirigami2 notifications purpose windowsystem \
		ecm:build \
		qqc2-desktop-style:run
USE_QT=		base declarative positioning svg webchannel webengine \
		sqldriver-sqlite:run

.include <bsd.port.mk>
