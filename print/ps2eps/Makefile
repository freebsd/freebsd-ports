# Created by: Jui-Nan Lin <jnlin@freebsd.cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	ps2eps
PORTVERSION=	1.64
PORTREVISION=	5
CATEGORIES=	print
MASTER_SITES=	http://www.tm.uka.de/~bless/ \
		http://www.ipv6.tm.uka.de/~bless/

MAINTAINER=	jnlin@freebsd.cs.nctu.edu.tw
COMMENT=	Generate Encapsulated Postscript file from Postscript document

WRKSRC=		${WRKDIR}/ps2eps

USES=		ghostscript:run perl5
USE_PERL5=	run
OPTIONS_DEFINE=	DOCS

do-build:
	${CC} -o ${WRKSRC}/bbox ${WRKSRC}/src/C/bbox.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbox ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ps2eps ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/bbox.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/man1/ps2eps.1 ${STAGEDIR}${PREFIX}/man/man1/

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/pdf
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changes.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/bbox.html ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/ps2eps.html ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/pdf/bbox.pdf ${STAGEDIR}${DOCSDIR}/pdf
	${INSTALL_DATA} ${WRKSRC}/doc/pdf/ps2eps.pdf ${STAGEDIR}${DOCSDIR}/pdf

.include <bsd.port.mk>
