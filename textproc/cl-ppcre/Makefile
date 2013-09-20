# Created by: Henrik Motakef <henrik.motakef@web.de>
# $FreeBSD$

PORTNAME=	cl-ppcre
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	textproc lisp
MASTER_SITES=	LOCAL/olgeni

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Portable Perl-Compatible Regular Expression for Common Lisp

NO_BUILD=	yes

USE_ASDF=	yes

NO_STAGE=	yes
do-install:
	@${MKDIR} ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/api.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/charmap.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/charset.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/chartest.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/closures.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/convert.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/errors.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/lexer.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/optimize.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/packages.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/parser.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/regex-class-util.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/regex-class.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/repetition-closures.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/scanner.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/specials.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/util.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/cl-ppcre.asd ${ASDF_PATHNAME}
	@${LN} -sf ${ASDF_PATHNAME}/*.asd ${ASDF_REGISTRY}
# cl-ppcre-test depends on flexi-streams
	@${MKDIR} ${ASDF_PATHNAME}/test
	@${INSTALL_DATA} ${WRKSRC}/test/packages.lisp ${ASDF_PATHNAME}/test
	@${INSTALL_DATA} ${WRKSRC}/test/perl-tests.lisp ${ASDF_PATHNAME}/test
	@${INSTALL_DATA} ${WRKSRC}/test/perltest.pl ${ASDF_PATHNAME}/test
	@${INSTALL_DATA} ${WRKSRC}/test/perltestdata ${ASDF_PATHNAME}/test
	@${INSTALL_DATA} ${WRKSRC}/test/perltestinput ${ASDF_PATHNAME}/test
	@${INSTALL_DATA} ${WRKSRC}/test/simple ${ASDF_PATHNAME}/test
	@${INSTALL_DATA} ${WRKSRC}/test/tests.lisp ${ASDF_PATHNAME}/test
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/index.html ${DOCSDIR}
.endif

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
