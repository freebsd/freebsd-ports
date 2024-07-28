PORTNAME=	neochat
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	3
CATEGORIES=	net-im deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Glossy Matrix IM client based on KDE technologies
WWW=		https://invent.kde.org/network/neochat

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-only.txt

LIB_DEPENDS=	libQCoro5Core.so:devel/qcoro@qt5 \
		libcmark.so:textproc/cmark \
		libqt5keychain.so:security/qtkeychain@qt5 \
		libolm.so:security/olm
BUILD_DEPENDS=	libquotient-qt5>=0.8.1.2:net-im/libquotient@qt5 \
		kquickimageeditor>=0.2.0:graphics/kquickimageeditor \
		kirigami-addons>=0.6.1:x11-toolkits/kirigami-addons
# Quotient is a static lib, doesn't need to be in RUN_DEPENDS
RUN_DEPENDS=	kquickimageeditor>=0.2.0:graphics/kquickimageeditor \
		kirigami-addons>=0.6.1:x11-toolkits/kirigami-addons

USES=		cmake compiler:c++20-lang desktop-file-utils kde:5 \
		pkgconfig qt:5 tar:xz xorg
USE_QT=		concurrent core dbus declarative graphicaleffects gui imageformats \
		location multimedia network quickcontrols quickcontrols2 \
		sql widgets xml \
		buildtools:build linguist:build qmake:build
USE_KDE=	auth codecs completion config configwidgets coreaddons dbusaddons \
		i18n itemmodels jobwidgets kio kirigami2 service solid sonnet \
		notifications qqc2-desktop-style widgetsaddons windowsystem \
		ecm:build
USE_XORG=	x11

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*}
USES+=		llvm:min=16
.elif ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
# Work around compiler bug, see pr: 272285
USES+=		llvm
.endif

.include <bsd.port.mk>
