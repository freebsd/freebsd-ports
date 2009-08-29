# New ports collection makefile for:	txt2tags
# Date created:		2002-12-20
# Whom:			Alan Eldridge <alane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	txt2tags
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Convert simply formatted text into markup (e.g., HTML)

USE_PYTHON=	yes
NO_BUILD=	yes

PORTDOCS=	ChangeLog README TODO userguide.pdf
SAMPLE_DIRS=	css img module

post-patch:
	@${MV} ${WRKSRC}/doc/userguide.pdf ${WRKSRC}/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/txt2tags ${PREFIX}/bin
.for dir in ${SAMPLE_DIRS}
	@${MKDIR} ${EXAMPLESDIR}/${dir}
	${INSTALL_DATA} ${WRKSRC}/samples/${dir}/* ${EXAMPLESDIR}/${dir}
.endfor
	${INSTALL_DATA} ${WRKSRC}/samples/sample* ${EXAMPLESDIR}/
	@${MKDIR} ${EXAMPLESDIR}/extras
	${INSTALL_DATA} ${WRKSRC}/extras/* ${EXAMPLESDIR}/extras
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
