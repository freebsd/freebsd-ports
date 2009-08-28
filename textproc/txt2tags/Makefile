# New ports collection makefile for:	txt2tags
# Date created:		2002-12-20
# Whom:			Alan Eldridge <alane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	txt2tags
PORTVERSION=	2.5
CATEGORIES=	textproc
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert simply formatted text into markup (e.g., HTML)

USE_PYTHON=	yes
NO_BUILD=	yes

DOCS=		ChangeLog README TODO doc/userguide.pdf
SAMPLE_DIRS=	css img module

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
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
