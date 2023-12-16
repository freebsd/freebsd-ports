PORTNAME=	kaccounts-integration
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net-im kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	System to administer web accounts for the KDE desktop
WWW=		https://projects.kde.org/projects/kdereview/kaccounts-integration

LIB_DEPENDS=	libQCoro5Core.so:devel/qcoro@qt5 \
		libaccounts-qt5.so:net-im/libaccounts-qt5 \
		libsignon-qt5.so:sysutils/signon-qt5
RUN_DEPENDS=	signon-ui:sysutils/signon-ui

USES=		cmake compiler:c++11-lang gettext-tools pkgconfig kde:5 \
		qt:5 tar:xz
USE_KDE=	config coreaddons dbusaddons i18n kcmutils kdeclarative kio \
		service wallet \
		ecm:build package:build \
		iconthemes:run
USE_QT=		concurrent core dbus declarative gui network widgets xml \
		buildtools:build qmake:build

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*} && ${OSVERSION} < 1400092
USES+=		llvm:min=16
.endif

.include <bsd.port.mk>
