# ex:ts=8
# Ports collection makefile for:	lambda
# Date created:			Mar 23, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	lambda
PORTVERSION=	0.1.4
CATEGORIES=	math
MASTER_SITES=	http://66.47.116.75/~demo/lambda/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lambda calculus interpreter

USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/lambda \
		share/lambda/definitions \
		share/lambda/definitions_with_numbers
PLIST_DIRS=	share/lambda

.if !defined(NOPORTDOCS)
DOCS=		lambda.html lambdamanual.html user_manual_style.css
PORTDOCS=	*
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lambda ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/definitions* ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
