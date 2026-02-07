PORTNAME=	smurflog
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	PACKETSTORM/UNIX/loggers

MAINTAINER=	mauroeldritch@gmail.com
COMMENT=	Program to assist logging of smurf attacks

USE_CSTD=	gnu89
GNU_CONFIGURE=	yes

PORTDOCS=	README
PLIST_FILES=	sbin/smurflog

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CFLAGS=|#CFLAGS=|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/strip/d' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smurflog ${STAGEDIR}${PREFIX}/sbin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
