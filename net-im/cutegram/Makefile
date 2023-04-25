PORTNAME=	cutegram
PORTVERSION=	2.7.1
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-stable
PORTREVISION=	5
CATEGORIES=	net-im

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Free and opensource telegram client
WWW=		https://aseman.co/en/products/cutegram/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libqtelegram-ae.so:net-im/libqtelegram-ae \
		libtelegramqml.so:net-im/telegramqml

USE_GITHUB=	yes
GH_ACCOUNT=	Aseman-Land
GH_PROJECT=	Cutegram aseman-qt-tools:tools
GH_TAGNAME=	91bf14b:tools
GH_SUBDIR=	Cutegram/asemantools:tools

USES=		compiler:c++11-lang desktop-file-utils gl gnome qmake:outsource \
		qt:5 ssl
USE_GL=		gl
USE_QT=		qmake:build buildtools:build dbus core declarative graphicaleffects \
		gui multimedia network quickcontrols sql sql-sqlite3 xml \
		widgets webkit
QMAKE_ARGS=	LIBQTELEGRAM_INCLUDE_PATH="${LOCALBASE}/include/libqtelegram-ae" \
		TELEGRAMQML_INCLUDE_PATH="${LOCALBASE}/include/telegramqml"

post-patch:
	@${REINPLACE_CMD} -e "/isEmpty(OPENSSL_INCLUDE_PATH)/d" \
               ${WRKSRC}/Cutegram/Cutegram.pro

.include <bsd.port.mk>
