# $FreeBSD$

PORTNAME=        falkon
DISTVERSION=        2.1.99.20180209

CATEGORIES=        www

MAINTAINER=        kde@FreeBSD.org
COMMENT=        Web browser based on WebKit engine and Qt Framework

LICENSE=        GPLv3
LICENSE_FILE=        ${WRKSRC}/LICENSE

USES=                cmake:outsource desktop-file-utils kde:5 ssl
USE_KDE=        wallet
USE_QT5=        core dbus gui location network printsupport qml quick \
                sql webchannel webengine widgets x11extras \
                buildtools_build qmake_build
USE_XORG=        xcb

USE_LDCONFIG=        yes
USE_GITHUB=        yes
GH_ACCOUNT=        KDE
GH_TAGNAME=        31e4d5f

CONFLICTS_INSTALL=        qupzilla-qt[45]*
