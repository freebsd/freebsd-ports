PORTNAME=	print-manager
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	print kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Printer manager for KDE
WWW=		https://www.kde.org

LIB_DEPENDS=	libcups.so:print/cups

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		dbusaddons i18n iconthemes itemviews jobwidgets kcmutils \
		kio notifications plasma-framework service solid widgetsaddons \
		windowsystem \
		ecm:build
USE_QT=		concurrent core dbus declarative gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

post-patch:
	${REINPLACE_CMD} '/CUPS_DATADIR/s|/usr/share/cups|${LOCALBASE}/share/cups|' \
               ${PATCH_WRKSRC}/libkcups/KCupsRequest.cpp

.include <bsd.port.mk>
