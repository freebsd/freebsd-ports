PORTNAME=	cl-ppcre
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.1
CATEGORIES=	textproc lisp

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Portable Perl-Compatible Regular Expression for Common Lisp

LICENSE=	BSD2CLAUSE

USE_ASDF=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	edicl

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME}/cl-ppcre-unicode ${STAGEDIR}${ASDF_REGISTRY}
	${INSTALL_DATA} ${WRKSRC}/api.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/charmap.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/charset.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/chartest.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/closures.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/convert.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/errors.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/lexer.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/optimize.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/packages.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/parser.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/regex-class-util.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/regex-class.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/repetition-closures.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/scanner.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/specials.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/util.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/cl-ppcre.asd ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/cl-ppcre-unicode.asd ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/cl-ppcre-unicode/packages.lisp ${STAGEDIR}${ASDF_PATHNAME}/cl-ppcre-unicode
	${INSTALL_DATA} ${WRKSRC}/cl-ppcre-unicode/resolver.lisp ${STAGEDIR}${ASDF_PATHNAME}/cl-ppcre-unicode
	${RLN} ${STAGEDIR}${ASDF_PATHNAME}/cl-ppcre.asd ${STAGEDIR}${ASDF_REGISTRY}
	${RLN} ${STAGEDIR}${ASDF_PATHNAME}/cl-ppcre-unicode.asd ${STAGEDIR}${ASDF_REGISTRY}
# cl-ppcre-test depends on flexi-streams
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME}/test
	${INSTALL_DATA} ${WRKSRC}/test/packages.lisp ${STAGEDIR}${ASDF_PATHNAME}/test
	${INSTALL_DATA} ${WRKSRC}/test/perl-tests.lisp ${STAGEDIR}${ASDF_PATHNAME}/test
	${INSTALL_DATA} ${WRKSRC}/test/perltest.pl ${STAGEDIR}${ASDF_PATHNAME}/test
	${INSTALL_DATA} ${WRKSRC}/test/perltestdata ${STAGEDIR}${ASDF_PATHNAME}/test
	${INSTALL_DATA} ${WRKSRC}/test/perltestinput ${STAGEDIR}${ASDF_PATHNAME}/test
	${INSTALL_DATA} ${WRKSRC}/test/simple ${STAGEDIR}${ASDF_PATHNAME}/test
	${INSTALL_DATA} ${WRKSRC}/test/tests.lisp ${STAGEDIR}${ASDF_PATHNAME}/test
	${INSTALL_DATA} ${WRKSRC}/test/unicode-tests.lisp ${STAGEDIR}${ASDF_PATHNAME}/test
	${INSTALL_DATA} ${WRKSRC}/test/unicodetestdata ${STAGEDIR}${ASDF_PATHNAME}/test

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/index.html ${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
