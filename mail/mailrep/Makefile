# New ports collection makefile for:    mailrep
# Date created:         2006-04-25
# Whom:                 Marcelo Araujo <araujo@bsdmail.org>
#
# $FreeBSD$
#

PORTNAME=	mailrep
PORTVERSION=	1.1
CATEGORIES=	mail sysutils
MASTER_SITES=	http://server3.bon.matrix.com.br/araujo/pub/mailrep/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Program for reporting mail log information

NO_BUILD=	yes
USE_PERL5=	yes

PORTDOCS=	LICENSE

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${PREFIX}/etc/mailrep
	${INSTALL_SCRIPT} ${WRKSRC}/mailrep.pl ${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/mailrep.conf ${PREFIX}/etc/mailrep/mailrep.conf.sample
.if !exists(${PREFIX}/etc/mailrep/mailrep.conf)
	${INSTALL_DATA} ${WRKSRC}/mailrep.conf ${PREFIX}/etc/mailrep/
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
