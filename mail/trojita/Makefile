# Created by: Marco Broeder <marco.broeder@posteo.eu>
# $FreeBSD$

PORTNAME=	trojita
PORTVERSION=	0.6
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/src/

MAINTAINER=	marco.broeder@posteo.eu
COMMENT?=	Fast cross-platform IMAP e-mail client using Qt 5 toolkit

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_LDCONFIG=	yes

USES=		cmake compiler:c++11-lib cpe desktop-file-utils tar:bzip2
CPE_PROJECT=	trojita_project
CMAKE_ARGS+=	-DWITH_CLEARTEXT_PLUGIN:STRING=ON -DWITH_DBUS:STRING=ON \
		-DWITH_DESKTOP:STRING=ON \
		-DWITH_QTKEYCHAIN_PLUGIN:STRING=ON -DWITH_RAGEL:STRING=OFF \
		-DWITH_SHARED_PLUGINS:STRING=ON -DWITH_TESTS:STRING=OFF \
		-DWITH_ZLIB:STRING=ON

INSTALLS_ICONS=	yes

.if defined(PKGNAMESUFFIX) && ${PKGNAMESUFFIX} == "-qt4"
CONFLICTS_INSTALL=	trojita-[0-9]*
LIB_DEPENDS+=	libqtkeychain.so:security/qtkeychain-qt4
CMAKE_ARGS+=	-DWITH_QT5:STRING=OFF
USE_QT4=	linguisttools_build moc_build qmake_build rcc_build uic_build \
		corelib dbus gui network sql sql-sqlite3 webkit
.else
CONFLICTS_INSTALL=	trojita-qt4-[0-9]*
LIB_DEPENDS+=	libqt5keychain.so:security/qtkeychain-qt5
CMAKE_ARGS+=	-DWITH_QT5:STRING=ON
USE_QT5=	buildtools_build linguisttools_build qmake_build \
		core dbus gui network sql sql-sqlite3 webkit widgets
.endif

.include <bsd.port.mk>
