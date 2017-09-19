# Created by: Henrik Motakef <henrik.motakef@web.de>
# $FreeBSD$

PORTNAME=	cl-ppcre
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	textproc lisp
MASTER_SITES=	LOCAL/olgeni

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Portable Perl-Compatible Regular Expression for Common Lisp

LICENSE=	BSD2CLAUSE

NO_BUILD=	yes
NO_ARCH=	yes

USE_ASDF=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME} ${STAGEDIR}${ASDF_REGISTRY}
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
	${LN} -sf ${ASDF_PATHNAME}/cl-ppcre.asd ${STAGEDIR}${ASDF_REGISTRY}
# cl-ppcre-test depends on flexi-streams
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME}/test
	${INSTALL_DATA} ${WRKSRC}/test/packages.lisp ${STAGEDIR}${ASDF_PATHNAME}/test
	${INSTALL_DATA} ${WRKSRC}/test/perl-tests.lisp ${STAGEDIR}${ASDF_PATHNAME}/test
	${INSTALL_DATA} ${WRKSRC}/test/perltest.pl ${STAGEDIR}${ASDF_PATHNAME}/test
	${INSTALL_DATA} ${WRKSRC}/test/perltestdata ${STAGEDIR}${ASDF_PATHNAME}/test
	${INSTALL_DATA} ${WRKSRC}/test/perltestinput ${STAGEDIR}${ASDF_PATHNAME}/test
	${INSTALL_DATA} ${WRKSRC}/test/simple ${STAGEDIR}${ASDF_PATHNAME}/test
	${INSTALL_DATA} ${WRKSRC}/test/tests.lisp ${STAGEDIR}${ASDF_PATHNAME}/test

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/index.html ${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
