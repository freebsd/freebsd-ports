# New ports collection Makefile for:	cl-ppcre
# Date created:				16 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=	cl-ppcre
PORTVERSION=	0.5.4
CATEGORIES=	textproc
MASTER_SITES=	http://weitz.de/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable Perl-Compatible Regular Expression for Common Lisp

BUILD_DEPENDS=		${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf
RUN_DEPENDS=		${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf

NO_BUILD=	yes # installs the sources only
CL_LIBDIR=	${PREFIX}/lib/common-lisp

do-install:
	${MKDIR} ${CL_LIBDIR}/cl-ppcre
	${INSTALL_DATA} ${WRKSRC}/api.lisp ${CL_LIBDIR}/cl-ppcre/
	${INSTALL_DATA} ${WRKSRC}/closures.lisp ${CL_LIBDIR}/cl-ppcre/
	${INSTALL_DATA} ${WRKSRC}/convert.lisp ${CL_LIBDIR}/cl-ppcre/
	${INSTALL_DATA} ${WRKSRC}/lexer.lisp ${CL_LIBDIR}/cl-ppcre/
	${INSTALL_DATA} ${WRKSRC}/load.lisp ${CL_LIBDIR}/cl-ppcre/
	${INSTALL_DATA} ${WRKSRC}/optimize.lisp ${CL_LIBDIR}/cl-ppcre/
	${INSTALL_DATA} ${WRKSRC}/packages.lisp ${CL_LIBDIR}/cl-ppcre/
	${INSTALL_DATA} ${WRKSRC}/parser.lisp ${CL_LIBDIR}/cl-ppcre/
	${INSTALL_DATA} ${WRKSRC}/regex-class.lisp ${CL_LIBDIR}/cl-ppcre/
	${INSTALL_DATA} ${WRKSRC}/repetition-closures.lisp ${CL_LIBDIR}/cl-ppcre/
	${INSTALL_DATA} ${WRKSRC}/scanner.lisp ${CL_LIBDIR}/cl-ppcre/
	${INSTALL_DATA} ${WRKSRC}/specials.lisp ${CL_LIBDIR}/cl-ppcre/
	${INSTALL_DATA} ${WRKSRC}/util.lisp ${CL_LIBDIR}/cl-ppcre/
	${INSTALL_DATA} ${WRKSRC}/cl-ppcre.asd ${CL_LIBDIR}/cl-ppcre/
	${INSTALL_DATA} ${WRKSRC}/cl-ppcre.system ${CL_LIBDIR}/cl-ppcre/
	${LN} -s ${CL_LIBDIR}/cl-ppcre/cl-ppcre.asd ${CL_LIBDIR}/system-registry/cl-ppcre.asd
	${LN} -s ${CL_LIBDIR}/cl-ppcre/cl-ppcre.system ${CL_LIBDIR}/system-registry/cl-ppcre.system
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/doc
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}/doc/
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/cl-ppcre-test.* ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/perltest.pl ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ppcre-tests.lisp ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/testdata ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/testinput ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
