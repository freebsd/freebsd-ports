PORTNAME=	drawterm
PORTVERSION=	20230903
CATEGORIES=	net x11
MASTER_SITES=	http://swtch.com/drawterm/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Plan9 cpu client
WWW=		https://swtch.com/drawterm/

# Additionally the Lucent Public License
LICENSE=	MIT

USES=		xorg localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	9front
GH_TAGNAME=	c4ea4d299aa1bbbcc972c04adf06c18245ce7674
USE_XORG=	x11 xt

PLIST_FILES=	bin/drawterm \
		share/man/man1/drawterm.1.gz

MAKE_ARGS=	CONF=${OPSYS:tl}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/drawterm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/drawterm.1 ${STAGEDIR}${MAN1PREFIX}/share/man/man1/drawterm.1

.include <bsd.port.mk>
