PORTNAME=	aribas
PORTVERSION=	1.65b
CATEGORIES=	math
MASTER_SITES=	https://www.mathematik.uni-muenchen.de/~forster/sw/UNIX_LINUX/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Interpreter for big integer/multi-precision floating point arithmetic
WWW=		https://www.mathematik.uni-muenchen.de/~forster/sw/aribas.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/gnugpl.txt

USES=		tar:tgz

BUILD_WRKSRC=	${WRKSRC}/src

PLIST_FILES=	bin/aribas \
		share/emacs/site-lisp/aribas.el \
		share/man/man1/aribas.1.gz
PORTDOCS=	EL-README README aribas.man aridoc.txt aritut.txt
PORTEXAMPLES=	README factor.ari pi.ari queens.ari

OPTIONS_DEFINE=	DOCS EXAMPLES

ELISPDIR=	share/emacs/site-lisp

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/aribas ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/EL/aribas.el ${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/

post-install-DOCS-on:
	@${CP} ${WRKSRC}/EL/README ${WRKSRC}/doc/EL-README
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/examples/|} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
