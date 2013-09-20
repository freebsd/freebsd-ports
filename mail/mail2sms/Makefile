# Created by: Gerhard Gonter <g.gonter@ieee.org>
# $FreeBSD$

PORTNAME=	mail2sms
PORTVERSION=	1.3.5
CATEGORIES=	mail
MASTER_SITES=	http://daniel.haxx.se/projects/mail2sms/ \
		http://bitrote.org/distfiles/

MAINTAINER=	jharris@widomaker.com
COMMENT=	Mail to SMS converter

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME}
MAN1=		mail2sms.1
MAN5=		mail2sms.5

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README REGEX example.conf

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	${CP} ${WRKSRC}/mail2sms.4 ${WRKSRC}/mail2sms.5
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/mail2sms.5
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mail2sms ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/${MAN5} ${PREFIX}/man/man5/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
