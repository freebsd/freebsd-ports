# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	cutegram
PORTVERSION=	2.7.1
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-stable
CATEGORIES=	net-im

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Free and opensource telegram client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libqtelegram-ae.so:net-im/libqtelegram-ae \
		libtelegramqml.so:net-im/telegramqml

USE_GITHUB=	yes
GH_ACCOUNT=	Aseman-Land
GH_PROJECT=	Cutegram aseman-qt-tools:tools
GH_TAGNAME=	91bf14b:tools
GH_SUBDIR=	Cutegram/asemantools:tools

USES=		qmake:outsource desktop-file-utils
USE_QT5=	qmake_build buildtools_build core qml quick sql xml multimedia \
		widgets dbus webkit quickcontrols graphicaleffects sql-sqlite3
USE_OPENSSL=	yes
QMAKE_ARGS=	LIBQTELEGRAM_INCLUDE_PATH="${LOCALBASE}/include/libqtelegram-ae" \
		TELEGRAMQML_INCLUDE_PATH="${LOCALBASE}/include/telegramqml"
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e "/isEmpty(OPENSSL_INCLUDE_PATH)/d" \
               ${WRKSRC}/Cutegram/Cutegram.pro

.include <bsd.port.mk>
