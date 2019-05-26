# $FreeBSD$

PORTNAME=	swapusage
PORTVERSION=	1.0.0
CATEGORIES=	sysutils

MAINTAINER=	aduitsis@douitsis.com
COMMENT=	Get swap usage on a FreeBSD system

LICENSE=	BSD2CLAUSE

GH_ACCOUNT=	aduitsis
GH_PROJECT=	freebsd_swapusage
USE_GITHUB=	yes

INSTALL_TARGET=	# empty

PLIST_FILES=	bin/swapusage

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/swapusage ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
