# $FreeBSD$

PORTNAME=	tcpkali
PORTVERSION=	1.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High performance load generator for TCP and WebSocket servers

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
USES=		autoreconf compiler:c11 libtool gmake ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	machinezone

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
