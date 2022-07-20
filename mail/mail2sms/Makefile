PORTNAME=	mail2sms
PORTVERSION=	1.3.5
CATEGORIES=	mail
MASTER_SITES=	http://daniel.haxx.se/projects/mail2sms/ \
		http://bitrote.org/distfiles/

MAINTAINER=	jharris@widomaker.com
COMMENT=	Mail to SMS converter

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/mail2sms man/man1/mail2sms.1.gz man/man5/mail2sms.5.gz
PORTDOCS=	README REGEX example.conf

post-patch:
	${CP} ${WRKSRC}/mail2sms.4 ${WRKSRC}/mail2sms.5
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/mail2sms.5
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mail2sms ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mail2sms.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/mail2sms.5 ${STAGEDIR}${PREFIX}/man/man5
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
