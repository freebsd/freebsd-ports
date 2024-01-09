PORTNAME=	aribas
PORTVERSION=	1.64
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://www.mathematik.uni-muenchen.de/~forster/sw/UNIX_LINUX/ \
		http://bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interpreter for big integer/multi-precision floating point arithmetic
WWW=		https://www.mathematik.uni-muenchen.de/~forster/sw/aribas.html

BUILD_WRKSRC=	${WRKSRC}/src

PLIST_FILES=	bin/aribas \
		share/man/man1/aribas.1.gz
PORTDOCS=	README aribas.doc aribas.man aribas.tut
PORTEXAMPLES=	README factor.ari pi.ari queens.ari

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e '/^CC/d;' \
	       -e '/^CFLAGS/{s/=/+=/;s/-O -v//;}' \
		-e 's/CC) -o/CC) $$(CFLAGS) -o/' ${BUILD_WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/aribas ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/examples/|} \
		${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
