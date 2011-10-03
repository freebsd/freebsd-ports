# New ports collection makefile for:	postfix-logwatch
# Date created:				2011-08-19
# Whom:					Alexander Moisseev <moiseev@mezonplus.ru>
#
# $FreeBSD$
#

PORTNAME=	postfix-logwatch
PORTVERSION=	1.39.07
CATEGORIES=	mail
MASTER_SITES=	SF/logreporters/${PORTNAME}/release/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	moiseev@mezonplus.ru
COMMENT=	Postfix MTA log parser

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTDOCS=	Bugs Changes README
PORTEXAMPLES=	${PORTNAME}.conf ${PORTNAME}.conf-topn

MAN1=		${PORTNAME}.1

USE_PERL5_RUN=	yes
NO_BUILD=	yes

post-patch:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e '\
		s!/usr/local/etc!${ETCDIR}! \
		' ${PORTNAME} ${PORTNAME}.1 README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
	@${CP} ${WRKSRC}/${PORTNAME}.conf ${WRKSRC}/${PORTNAME}.conf.sample
	@${MKDIR} ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.sample ${ETCDIR}

post-install:
	@if [ ! -f ${ETCDIR}/${PORTNAME}.conf ]; then \
		${CP} -p ${ETCDIR}/${PORTNAME}.conf.sample ${ETCDIR}/${PORTNAME}.conf; \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} ${PORTDOCS} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
