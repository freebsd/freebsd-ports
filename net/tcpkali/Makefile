# $FreeBSD$

PORTNAME=	tcpkali
PORTVERSION=	0.4.2
CATEGORIES=	net

MAINTAINER=	neel@neelc.org
COMMENT=	High performance load generator for TCP and WebSocket servers

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
USES=		autoreconf libtool gmake

USE_GITHUB=	yes
GH_ACCOUNT=	machinezone
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	0b99e37

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
