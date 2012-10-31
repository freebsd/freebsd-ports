# Created by: Gerhard Gonter <g.gonter@ieee.org>
# $FreeBSD$

PORTNAME=	mail2sms
PORTVERSION=	1.3.5
CATEGORIES=	mail
MASTER_SITES=	http://www.contactor.se/~dast/stuff/

MAINTAINER=	g.gonter@ieee.org
COMMENT=	Mail to SMS converter

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME}
MAN1=		mail2sms.1
MAN5=		mail2sms.5

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	README REGEX example.conf
.endif

post-patch:
	${CP} ${WRKSRC}/mail2sms.4 ${WRKSRC}/mail2sms.5
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/mail2sms.5
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mail2sms ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/${MAN5} ${PREFIX}/man/man5/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
