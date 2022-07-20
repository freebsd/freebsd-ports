PORTNAME=	nyancat
PORTVERSION=	1.5.2
PORTEPOCH=	1
CATEGORIES=	net games

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Animated telnet server that renders a loop of the nyan cat animation

LICENSE=	NCSA

USE_GITHUB=	yes
GH_ACCOUNT=	klange

SUB_FILES=	pkg-message
PLIST_FILES=	bin/nyancat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
