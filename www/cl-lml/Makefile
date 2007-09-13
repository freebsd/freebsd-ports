# New ports collection Makefile for:	cl-lml
# Date created:				18 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=		lml
PORTVERSION=		2.5.7
CATEGORIES=		www textproc
MASTER_SITES=		http://files.b9.com/lml/ \
					http://people.bsdgroup.de/~as/freebsd/distfiles/
PKGNAMEPREFIX=		cl-

MAINTAINER=		as@bsdgroup.de
COMMENT=		Lisp Markup Language

BUILD_DEPENDS=		${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf
RUN_DEPENDS=		${LOCALBASE}/lib/common-lisp/asdf/asdf.lisp:${PORTSDIR}/devel/cl-asdf

NO_BUILD=		yes # installs the sources only
CL_LIBDIR=		${PREFIX}/lib/common-lisp
DOCSDIR=		${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

.if !defined(NOPORTDOCS)
PORTDOCS=	Makefile make.lisp readme.html readme.lml
.endif

do-install:
	${MKDIR} ${CL_LIBDIR}/lml
	${INSTALL_DATA} ${WRKSRC}/*.lisp ${CL_LIBDIR}/lml
	${INSTALL_DATA} ${WRKSRC}/lml.asd ${CL_LIBDIR}/lml
	${LN} -s ${CL_LIBDIR}/lml/lml.asd ${CL_LIBDIR}/system-registry/lml.asd
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
