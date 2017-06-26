# $FreeBSD$

PORTNAME=	tcpkali
PORTVERSION=	1.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	neel@neelc.org
COMMENT=	High performance load generator for TCP and WebSocket servers

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	uses i386 assembler

GNU_CONFIGURE=	yes
USES=		autoreconf libtool gmake ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	machinezone

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
