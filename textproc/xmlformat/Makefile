# New ports collection makefile for:	xmlformat
# Date created:		8 Feb 2004
# Whom:			Hiroki Sato <hrs@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	xmlformat
PORTVERSION=	1.02
CATEGORIES=	textproc
MASTER_SITES=	http://www.kitebird.com/software/xmlformat/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	An XML Document Formatter

NO_BUILD=	yes
USE_PERL5=	yes

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	BUGS ChangeLog INSTALL LICENSE README TODO

DOCSRCDIR2=	${WRKSRC}/docs
DOCSDIR2=	${DOCSDIR}/docs
DOC_FILES2=	API catalog.xml \
		tutorial.html tutorial.pdf tutorial.xml \
		xmlformat.conf xmlformat.html xmlformat.pdf xmlformat.xml

EXSRCDIR=	${WRKSRC}/docs/examples
EXDIR=		${DOCSDIR}/docs/examples
EX_FILES=	doc1.xml doc2.conf1 doc2.conf2 doc2.conf3 \
		doc2.conf4 doc2.xml

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xmlformat.pl ${PREFIX}/bin/xmlformat
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S,^,${DOCSRCDIR1}/,} ${DOCSDIR}
	${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S,^,${DOCSRCDIR2}/,} ${DOCSDIR2}
	${MKDIR} ${EXDIR}
	${INSTALL_DATA} ${EX_FILES:S,^,${EXSRCDIR}/,} ${EXDIR}
.endif

.include <bsd.port.mk>
