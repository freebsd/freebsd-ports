PORTNAME=	print-manager
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	print kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Printer manager for KDE
WWW=		https://www.kde.org

LIB_DEPENDS=	libcups.so:print/cups \
		libpackagekitqt6.so:ports-mgmt/packagekit-qt

USES=		cmake compiler:c++11-lang gettext kde:6 pkgconfig qt:6 tar:xz \
		xorg
USE_KDE=	config configwidgets coreaddons dbusaddons i18n itemmodels \
		kcmutils kdeclarative kio kirigami-addons kirigami2 \
		notifications widgetsaddons \
		ecm:build
# Plasma components
USE_KDE+=	libplasma
USE_QT=		base declarative
USE_XORG=	x11

post-patch:
	${REINPLACE_CMD} '/CUPS_DATADIR/s|/usr/share/cups|${LOCALBASE}/share/cups|' \
               ${PATCH_WRKSRC}/src/libkcups/KCupsRequest.cpp

.include <bsd.port.mk>
