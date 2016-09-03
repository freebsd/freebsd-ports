# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	libqtelegram-ae
PORTVERSION=	6.1
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-stable
CATEGORIES=	net-im

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Fork of libqtelegram by Aseman Team

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	Aseman-Land
GH_PROJECT=	libqtelegram-aseman-edition

USES=		qmake:outsource
USE_QT5=	qmake_build buildtools_build core gui network multimedia
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

# Explicitly disable C++11, as Qt 5.6 defaults to -std=gnu++11 when the
# compiler supports it and the build currently fails.
# ../libqtelegram-aseman-edition-6.1-stable/telegram/types/accountdaysttl.cpp:51:10: error: case value evaluates to 3100684255, which cannot be narrowed to type 'int' [-Wc++11-narrowing]
#     case typeAccountDaysTTL: {
QMAKE_ARGS=	CONFIG-="c++11"

post-patch:
	@${REINPLACE_CMD} -e "/OPENSSL_INCLUDE_PATH/d" \
		${WRKSRC}/libqtelegram-ae.pri

.include <bsd.port.mk>
