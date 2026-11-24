PORTNAME=	tarsnap-gui
PORTVERSION=	1.0.2
DISTVERSIONPREFIX=	v
PORTREVISION=	5
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross platform GUI for the Tarsnap command line client
WWW=		https://github.com/Tarsnap/tarsnap-gui/wiki

DEPRECATED=	Depends on unsupported Qt5
EXPIRATION_DATE=	2027-01-01

USE_GITHUB=	yes
GH_ACCOUNT=	Tarsnap

USES=		compiler:c++11-lib gl qmake qt:5
USE_QT=		buildtools:build core gui network qmake:build sql sql-sqlite3 widgets
USE_GL=		gl

PLIST_FILES=	bin/tarsnap-gui

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tarsnap-gui ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
