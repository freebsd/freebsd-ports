# Created by: kmoore@FreeBSD.org
# $FreeBSD$

PORTNAME=	octopkg
PORTVERSION=	v0.1.0
CATEGORIES=	ports-mgmt

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	OctoPkg graphical package manager

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	aarnt

USE_QT5=	core concurrent gui network linguist svg \
		buildtools x11extras
USES=		qmake tar:xz
PLIST_FILES=	bin/octopkg

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/octopkg ${STAGEDIR}${PREFIX}/bin/octopkg

.include <bsd.port.mk>
