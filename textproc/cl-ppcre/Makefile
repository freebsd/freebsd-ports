# New ports collection Makefile for:	cl-ppcre
# Date created:				16 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=	cl-ppcre
PORTVERSION=	0.5.4
PORTREVISION=	1
CATEGORIES=	textproc lisp
MASTER_SITES=	http://weitz.de/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Portable Perl-Compatible Regular Expression for Common Lisp

NO_BUILD=	yes

USE_ASDF=	yes

do-install:
	@${MKDIR} ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/api.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/closures.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/convert.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/lexer.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/load.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/optimize.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/packages.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/parser.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/regex-class.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/repetition-closures.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/scanner.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/specials.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/util.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/cl-ppcre.asd ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/cl-ppcre.system ${ASDF_PATHNAME}
	@${LN} -sf ${ASDF_PATHNAME}/*.asd ${ASDF_REGISTRY}
	@${LN} -sf ${ASDF_PATHNAME}/*.system ${ASDF_REGISTRY}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/doc
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}/doc/
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/cl-ppcre-test.* ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/perltest.pl ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/ppcre-tests.lisp ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/testdata ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/testinput ${EXAMPLESDIR}
.endif

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
