# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	telegramqml
PORTVERSION=	0.9.2
DISTVERSIONPREFIX=	v
CATEGORIES=	net-im

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Telegram API tools for QtQML and Qml

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libqtelegram-ae.so:net-im/libqtelegram-ae

USE_GITHUB=	yes
GH_ACCOUNT=	Aseman-Land
GH_PROJECT=	TelegramQML

USES=		qmake:outsource
USE_QT5=	qmake_build buildtools_build core qml quick sql xml multimedia
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
QMAKE_ARGS=	BUILD_MODE+=lib \
		LIBQTELEGRAM_INCLUDE_PATH="${LOCALBASE}/include/libqtelegram-ae"

# Explicitly disable C++11, as Qt 5.6 defaults to -std=gnu++11 when the
# compiler supports it and the build currently fails.
# ../TelegramQML-0.9.2/telegramqml.cpp:4794:10: error: case value evaluates to 2573335900, which cannot be narrowed to type 'int' [-Wc++11-narrowing]
#     case Update::typeUpdateReadHistoryInbox:
QMAKE_ARGS+=	CONFIG-="c++11"

post-patch:
	@${REINPLACE_CMD} -e "/isEmpty(OPENSSL_INCLUDE_PATH)/d" \
		${WRKSRC}/telegramqml.pri

.include <bsd.port.mk>
