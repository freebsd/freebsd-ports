# ex:ts=8
# New ports collection makefile for:	checkservice
# Date created:		Jan 1, 2001
# Whom:	     		Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	checkservice
PORTVERSION=	1.2.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.linvision.com/checkservice/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Checkservice is written to check the status of the services

RUN_DEPENDS=	${SITE_PERL}/Mail/Send.pm:${PORTSDIR}/mail/p5-Mail-Tools

USE_PERL5_RUN=	YES
NO_BUILD=	YES

MAN1=		checkservice.1
MAN5=		checkservice.5

post-patch:
.for file in ${PORTNAME} man/${PORTNAME}.1 man/${PORTNAME}.5
	@${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|g" ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	${CP} -R ${WRKSRC}/lib/CS ${SITE_PERL}
	@${MKDIR} -m 755 ${PREFIX}/lib/${PORTNAME}
	${CP} -R ${WRKSRC}/plugins/ ${PREFIX}/lib/${PORTNAME}
	@${MKDIR} -m 755 ${PREFIX}/etc/${PORTNAME}
	${CP} -R ${WRKSRC}/config/ ${PREFIX}/etc/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/man/checkservice.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/checkservice.5 ${PREFIX}/man/man5

post-install:
.if !defined(BATCH)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "############################################################################"
	@${ECHO_CMD} "# Config files are in ${PREFIX}/etc/${PORTNAME}                            #"
	@${ECHO_CMD} "# Plugins are in ${PREFIX}/lib/${PORTNAME}                                 #"
	@${ECHO_CMD} "############################################################################"
.endif

.include <bsd.port.mk>
