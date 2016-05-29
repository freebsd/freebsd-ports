# $FreeBSD$

PORTNAME=	qtpass
PORTVERSION=	1.1.1
DISTVERSIONPREFIX=v
CATEGORIES=sysutils

MAINTAINER=	brouwer@annejan.com
COMMENT=	Qt GUI for pass, the standard unix password manager

LICENSE=	GPLv3

RUN_DEPENDS=	pass:sysutils/password-store

USES=		qmake
USE_GITHUB=	yes
GH_ACCOUNT=	IJhack
USE_QT5=	buildtools core gui linguisttools network widgets 
USE_GL=		gl
PLIST_FILES=	bin/qtpass

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qtpass ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
