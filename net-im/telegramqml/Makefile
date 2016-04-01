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
USE_LDCONFIG=	yes
QMAKE_ARGS=	BUILD_MODE+=lib

.include <bsd.port.mk>
