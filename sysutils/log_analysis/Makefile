# New ports collection makefile for:	log_analysis
# Date created:				5 July 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	log_analysis
PORTVERSION=	0.42
CATEGORIES=	sysutils
MASTER_SITES=	http://lug.umbc.edu/~mabzug1/

MAINTAINER=	petef@FreeBSD.org
COMMENT=	A utility that extracts a summary of useful data from logs

USE_PERL5=	yes

GNU_CONFIGURE=	yes

MAN1=	log_analysis.1

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sample-* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/Tutorial ${DOCSDIR}
.endif

.include <bsd.port.mk>
