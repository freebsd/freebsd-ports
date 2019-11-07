# $FreeBSD$

PORTNAME=	tarsnap-gui
PORTVERSION=	1.0.2
PORTREVISION=	3
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Cross platform GUI for the Tarsnap command line client

USE_GITHUB=	yes
GH_ACCOUNT=	Tarsnap

USES=		compiler:c++11-lib gl qmake qt:5
USE_QT=		buildtools_build core gui network qmake_build sql sql-sqlite3 widgets
USE_GL=		gl

PLIST_FILES=	bin/tarsnap-gui

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tarsnap-gui ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
