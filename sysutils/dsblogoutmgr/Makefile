# $FreeBSD$

PORTNAME=	dsblogoutmgr
PORTVERSION=	1.3.2
CATEGORIES=	sysutils
MASTER_SITES=	http://freeshell.de/~mk/download/

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	Graphical logout manager

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang gl qmake qt:5 tar:tgz

USE_GL=		gl
USE_QT=		buildtools_build core gui linguisttools_build widgets

OPTIONS_DEFINE=	METALOCK

METALOCK_DESC=	Use metalock for locking the screen

METALOCK_RUN_DEPENDS=	metalock:x11/metalock

.include <bsd.port.mk>
