# New ports collection Makefile for:	cl-meta
# Date created:				16 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=		meta
PORTVERSION=		0.1
CATEGORIES=		textproc
MASTER_SITES=		ftp://ftp.linux.org.uk/pub/lisp/experimental/cclan/ \
			ftp://ftp.ntnu.no/pub/lisp/cclan/ \
			ftp://www.aarg.net/pub/cclan/ \
			http://thingamy.com/cclan/ \
			http://www-jcsu.jesus.cam.ac.uk/ftp/pub/cclan/
PKGNAMEPREFIX=		cl-
DISTNAME=		${PORTNAME}_${PORTVERSION}

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A parser generator for Common Lisp

BUILD_DEPENDS=		${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf
RUN_DEPENDS=		${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf

WRKSRC=			${WRKDIR}/${PORTNAME}
DOCSDIR=		${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
NO_BUILD=		yes
CL_LIBDIR=		${PREFIX}/lib/common-lisp

do-install:
	${MKDIR} ${CL_LIBDIR}/meta
	${INSTALL_DATA} ${WRKSRC}/*.lisp ${CL_LIBDIR}/meta/
	${INSTALL_DATA} ${WRKSRC}/meta.asd ${CL_LIBDIR}/meta/
	${LN} -s ${CL_LIBDIR}/meta/meta.asd ${CL_LIBDIR}/system-registry/meta.asd
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Prag-Parse.* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
