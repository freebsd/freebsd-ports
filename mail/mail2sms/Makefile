# New ports collection makefile for:   mail2sms
# Date created:		2003-04-16
# Whom:			Gerhard Gonter <g.gonter@ieee.org>
#
# $FreeBSD$

PORTNAME=	mail2sms
PORTVERSION=	1.3.5
CATEGORIES=	mail
MASTER_SITES=	http://www.contactor.se/~dast/stuff/
DISTNAME=	mail2sms-${PORTVERSION}

MAINTAINER=	g.gonter@ieee.org
COMMENT=	Mail to SMS converter

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=		mail2sms.1
MAN5=		mail2sms.5

post-patch:
	${CP} ${WRKSRC}/mail2sms.4 ${WRKSRC}/mail2sms.5
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/mail2sms.5
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mail2sms ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/${MAN5} ${PREFIX}/man/man5/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mail2sms
	${INSTALL_MAN} ${WRKSRC}/README ${WRKSRC}/REGEX ${WRKSRC}/example.conf \
	${PREFIX}/share/doc/mail2sms
.endif

.include <bsd.port.mk>
