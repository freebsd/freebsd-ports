# Created by: Winston Weinert <winstonw@lavabit.com>
# $FreeBSD$

PORTNAME=	drawterm
PORTVERSION=	20140106
CATEGORIES=	net
MASTER_SITES=	http://swtch.com/drawterm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	winston@ml1.net
COMMENT=	Plan9 cpu client

# Additionally the Lucent Public License
LICENSE=	MIT

USE_XORG=	x11 xt

PLIST_FILES=	bin/drawterm
PORTDOCS=	LICENSE README
WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ARGS=	CONF=pthread

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/drawterm ${STAGEDIR}${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${WRKSRC}/LICENSE ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
