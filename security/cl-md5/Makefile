# New ports collection makefile for:	cl-md5
# Date created:				16 January 2010
# Whom:					Jimmy Olgeni <olgeni@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	md5
PORTVERSION=	1.8.5
CATEGORIES=	security lisp
MASTER_SITES=	http://files.b9.com/md5/
PKGNAMEPREFIX=	cl-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A native MD5 implementation in Common Lisp

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
NO_BUILD=	yes

USE_ASDF=	yes

do-install:
	@${MKDIR} ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/*.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/*.asd ${ASDF_PATHNAME}
	@${LN} -sf ${ASDF_PATHNAME}/*.asd ${ASDF_REGISTRY}

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
