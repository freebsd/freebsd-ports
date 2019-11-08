# Created by: Marco Broeder <marco.broeder@posteo.eu>
# $FreeBSD$

PORTNAME=	trojita
PORTVERSION=	0.7
PORTREVISION=	9
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/src/

MAINTAINER=	marco.broeder@posteo.eu
COMMENT=	Fast cross-platform IMAP e-mail client using Qt 5 toolkit

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain

INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

CPE_VENDOR=	trojita_project
CMAKE_ARGS+=	-DWITH_CLEARTEXT_PLUGIN:STRING=ON -DWITH_DBUS:STRING=ON \
		-DWITH_DESKTOP:STRING=ON \
		-DWITH_QTKEYCHAIN_PLUGIN:STRING=ON -DWITH_RAGEL:STRING=OFF \
		-DWITH_SHARED_PLUGINS:STRING=ON -DWITH_TESTS:STRING=OFF \
		-DWITH_ZLIB:STRING=ON \
		-DWITH_QT5:STRING=ON
USES=		cmake compiler:c++11-lib cpe desktop-file-utils gnome \
		localbase:ldflags qt:5 tar:xz
USE_QT=		buildtools_build linguisttools_build qmake_build \
		core dbus gui network sql sql-sqlite3 svg webkit widgets

.include <bsd.port.mk>
