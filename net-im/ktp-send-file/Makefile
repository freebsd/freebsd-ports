PORTNAME=	ktp-send-file
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net-im kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE instant messaging file transfer application
WWW=		https://community.kde.org/KTp

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtelepathy-qt5.so:net-im/telepathy-qt \
		libKTpCommonInternals.so:net-im/ktp-common-internals
RUN_DEPENDS=	${KDE_PREFIX}/lib/libexec/ktp-filetransfer-handler:net-im/ktp-filetransfer-handler \
		${KDE_PREFIX}/bin/ktp-contactlist:net-im/ktp-contact-list

USES=		compiler:c++11-lang cmake gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		i18n iconthemes jobwidgets kcmutils kio service solid wallet \
		widgetsaddons windowsystem \
		ecm:build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
