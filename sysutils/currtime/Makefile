# $FreeBSD$

PORTNAME=	currtime
PORTVERSION=	0.2.5
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced command-line operated real time clock

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	neelchauhan

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
