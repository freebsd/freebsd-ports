# Created by: Winston Weinert <winstonw@lavabit.com>
# $FreeBSD$

PORTNAME=	drawterm
PORTVERSION=	20140106
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://swtch.com/drawterm/

MAINTAINER=	winston@ml1.net
COMMENT=	Plan9 cpu client

# Additionally the Lucent Public License
LICENSE=	MIT

USES=		tar:tgz xorg
USE_XORG=	x11 xt

PLIST_FILES=	bin/drawterm
PORTDOCS=	LICENSE README
WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ARGS=	CONF=pthread

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/drawterm ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/LICENSE ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
