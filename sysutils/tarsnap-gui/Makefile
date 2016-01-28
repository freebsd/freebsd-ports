# $FreeBSD$

PORTNAME=	tarsnap-gui
PORTVERSION=	0.8
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Cross platform GUI for the Tarsnap command line client

USE_GITHUB=	yes
GH_ACCOUNT=	Tarsnap

USES=		compiler:c++11-lib qmake
USE_QT5=	qmake_build widgets network buildtools_build sql-sqlite3

PLIST_FILES=	bin/tarsnap-gui

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tarsnap-gui ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
