# New ports collection makefile for:	ps2eps
# Date created:		2005-12-30
# Whom:			Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	ps2eps
PORTVERSION=	1.64
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	http://www.tm.uka.de/~bless/ \
		http://www.ipv6.tm.uka.de/~bless/

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	Generate Encapsulated Postscript file from Postscript document

WRKSRC=		${WRKDIR}/ps2eps

USE_GHOSTSCRIPT_RUN=	yes
USES=		perl5
USE_PERL5=	run
MAN1=		ps2eps.1 bbox.1

do-build:
	${CC} -o ${WRKSRC}/bbox ${WRKSRC}/src/C/bbox.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbox ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ps2eps ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/bbox.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/ps2eps.1 ${PREFIX}/man/man1/

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/html
	@${MKDIR} ${DOCSDIR}/pdf
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changes.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/bbox.html ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/ps2eps.html ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/pdf/bbox.pdf ${DOCSDIR}/pdf
	${INSTALL_DATA} ${WRKSRC}/doc/pdf/ps2eps.pdf ${DOCSDIR}/pdf
.endif

.include <bsd.port.mk>
