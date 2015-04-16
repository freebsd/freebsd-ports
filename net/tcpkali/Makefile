# $FreeBSD$

PORTNAME=	tcpkali
PORTVERSION=	0.5
CATEGORIES=	net

MAINTAINER=	neel@neelc.org
COMMENT=	High performance load generator for TCP and WebSocket servers

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
USES=		autoreconf libtool gmake

USE_GITHUB=	yes
GH_ACCOUNT=	machinezone
GH_TAGNAME=	v${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
