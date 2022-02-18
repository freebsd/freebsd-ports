PORTNAME=	neochat
DISTVERSION=	1.2.0
PORTREVISION=	5
CATEGORIES=	net-im
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Glossy Matrix IM client based on KDE technologies

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-only.txt

LIB_DEPENDS=	libcmark.so:textproc/cmark \
		libqt5keychain.so:security/qtkeychain
BUILD_DEPENDS=	libquotient>=0.6.11:net-im/libquotient \
		kquickimageeditor>=0.1.2:graphics/kquickimageeditor
# Quotient is a static lib, doesn't need to be in RUN_DEPENDS
RUN_DEPENDS=	kquickimageeditor>=0.1.2:graphics/kquickimageeditor

USES=		cmake compiler:c++17-lang gl kde:5 pkgconfig qt:5 tar:xz
USE_GL=		gl
USE_QT=		core dbus declarative graphicaleffects gui imageformats \
		multimedia network quickcontrols quickcontrols2 \
		svg widgets xml \
		buildtools_build linguist_build qmake_build
USE_KDE=	config coreaddons dbusaddons i18n itemmodels kirigami2 notifications \
		qqc2-desktop-style \
		ecm_build

.include <bsd.port.mk>
