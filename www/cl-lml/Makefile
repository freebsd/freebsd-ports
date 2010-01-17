# New ports collection Makefile for:	cl-lml
# Date created:				18 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=	lml
PORTVERSION=	2.5.7
PORTREVISION=	1
CATEGORIES=	www textproc
MASTER_SITES=	http://files.b9.com/lml/ \
		http://people.bsdgroup.de/~as/freebsd/distfiles/
PKGNAMEPREFIX=	cl-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Lisp Markup Language

NO_BUILD=	yes

USE_ASDF=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	Makefile make.lisp readme.html readme.lml
.endif

do-install:
	@${MKDIR} ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/*.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.asd ${ASDF_PATHNAME}
	@${LN} -sf ${ASDF_PATHNAME}/*.asd ${ASDF_REGISTRY}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${DOCSDIR}
.endfor
.endif

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
