# $FreeBSD$

PORTNAME=	currtime
PORTVERSION=	0.2.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.neelc.org/files/currtime/${PORTVERSION}/

MAINTAINER=	neel@neelc.org
COMMENT=	Enhanced command-line operated real time clock

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
