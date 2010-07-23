# New ports collection Makefile for:	cl-meta
# Date created:				16 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=	meta
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	textproc lisp
MASTER_SITES=	ftp://ftp.linux.org.uk/pub/lisp/experimental/cclan/ \
		ftp://ftp.ntnu.no/pub/lisp/cclan/ \
		http://www-jcsu.jesus.cam.ac.uk/ftp/pub/cclan/
PKGNAMEPREFIX=	cl-
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A parser generator for Common Lisp

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

USE_ASDF=	yes

do-install:
	@${MKDIR} ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/*.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/meta.asd ${ASDF_PATHNAME}
	@${LN} -sf ${ASDF_PATHNAME}/*.asd ${ASDF_REGISTRY}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Prag-Parse.* ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
