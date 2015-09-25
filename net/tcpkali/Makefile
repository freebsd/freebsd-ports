# $FreeBSD$

PORTNAME=	tcpkali
PORTVERSION=	0.6
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	neel@neelc.org
COMMENT=	High performance load generator for TCP and WebSocket servers

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64 i386 ia64
ONLY_FOR_ARCHS_REASON=	uses i386 assembler

GNU_CONFIGURE=	yes
USES=		autoreconf libtool gmake

USE_GITHUB=	yes
GH_ACCOUNT=	machinezone

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
