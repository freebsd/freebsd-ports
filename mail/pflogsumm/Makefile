# New ports collection makefile for:	pflogsumm
# Date created:				13 April 2001
# Whom:					Sergey A. Osokin <osa@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pflogsumm
PORTVERSION=	1.0.12
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://jimsun.LinxNet.com/downloads/ \
		ftp://jimsun.LinxNet.com/pub/postfix_contrib/

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Postfix Log Entry Summarizer

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc

NO_BUILD=	yes
USE_PERL5=	yes

MAN1=		pflogsumm.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README ToDo pflogsumm-faq.txt
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
