# $FreeBSD$

PORTNAME=	falkon
DISTVERSION=	3.0.0
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	KDE/stable/falkon/${DISTVERSION:R}/src/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Web browser based on WebKit engine and Qt Framework

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake desktop-file-utils kde:5 qt:5 ssl tar:xz
USE_KDE=	wallet
USE_QT=		core dbus declarative gui location network printsupport \
		sql webchannel webengine widgets x11extras \
		buildtools_build qmake_build
USE_XORG=	xcb

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GNOMEKEYRING ALSA
OPTIONS_DEFAULT=	ALSA
OPTIONS_SUB=	YES

GNOMEKEYRING_CMAKE_BOOL=	BUILD_KEYRING
GNOMEKEYRING_USE=		GNOME=glib20
GNOMEKEYRING_LIB_DEPENDS=	libgnome-keyring.so:security/libgnome-keyring

# Need the plugins to get sound, otherwise messages that the
# pcm_oss plugin can't be opened.
ALSA_RUN_DEPENDS=	alsa-plugins>=0:audio/alsa-plugins

.include <bsd.port.mk>
