# ex:ts=8
# New ports collection makefile for:	checkservice
# Date created:		Jan 1, 2001
# Whom:	     		Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	checkservice
PORTVERSION=	1.1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.linvision.com/checkservice/files/

MAINTAINER=	ijliao@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Mail/Send.pm:${PORTSDIR}/mail/p5-Mail-Tools

USE_PERL5=	YES

NO_BUILD=	YES

MAN1=		checkservice.1
MAN5=		checkservice.5

post-patch:
.for file in ${PORTNAME} man/${PORTNAME}.1 man/${PORTNAME}.5
	@${PERL} -pi -e "s|/etc|${PREFIX}/etc|g" ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/opensocket.pl ${PREFIX}/lib/perl5/site_perl/${PERL_VER}
	${INSTALL_MAN} ${WRKSRC}/man/checkservice.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/checkservice.5 ${PREFIX}/man/man5
	${MKDIR} -m 755 ${PREFIX}/lib/${PORTNAME}
	${CP} -R ${WRKSRC}/plugins/ ${PREFIX}/lib/${PORTNAME}
	${MKDIR} -m 755 ${PREFIX}/etc/${PORTNAME}
	${CP} -R ${WRKSRC}/config/ ${PREFIX}/etc/${PORTNAME}

post-install:
.if !defined(BATCH)
	@${ECHO} ""
	@${ECHO} "############################################################################"
	@${ECHO} "# Config files are in ${PREFIX}/etc/${PORTNAME}                            #"
	@${ECHO} "# Plugins are in ${PREFIX}/lib/${PORTNAME}                                 #"
	@${ECHO} "############################################################################"
.endif

.include <bsd.port.mk>
