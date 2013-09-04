# New ports collection makefile for:	amavis-logwatch
# Date created:				2011-11-01
# Whom:					Masaki TAGAWA <masaki@club.kyutech.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	amavis-logwatch
PORTVERSION=	1.51.02
CATEGORIES=	mail
MASTER_SITES=	SF/logreporters/${PORTNAME}/release/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	Amavisd-new log parser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTDOCS=	Bugs Changes README
PORTEXAMPLES=	${PORTNAME}.conf

MAN1=		${PORTNAME}.1

USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes

post-patch:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e '\
		s!/usr/local/etc!${ETCDIR}! \
		' ${PORTNAME} ${PORTNAME}.1 README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
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
