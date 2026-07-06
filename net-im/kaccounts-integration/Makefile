PORTNAME=	kaccounts-integration
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net-im kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	System to administer web accounts for the KDE desktop
WWW=		https://projects.kde.org/projects/kdereview/kaccounts-integration

LIB_DEPENDS=	libQCoro6Core.so:devel/qcoro \
		libaccounts-qt6.so:net-im/libaccounts-qt \
		libsignon-qt6.so:sysutils/signond

USES=		cmake compiler:c++11-lang gettext-tools kde:6 pkgconfig qt:6 \
		tar:xz
USE_KDE=	config coreaddons dbusaddons i18n kcmutils kdeclarative kio \
		service wallet \
		ecm:build package:build \
		iconthemes:run
USE_QT=		base declarative

.include <bsd.port.mk>
