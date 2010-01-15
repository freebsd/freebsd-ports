# New ports collection Makefile for:	cl-meta-sbcl
# Date created:				16 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=	meta
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	textproc lisp
MASTER_SITES=	ftp://ftp.linux.org.uk/pub/lisp/experimental/cclan/ \
		ftp://ftp.ntnu.no/pub/lisp/cclan/ \
		http://www-jcsu.jesus.cam.ac.uk/ftp/pub/cclan/
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A parser generator for Common Lisp

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/meta/meta.asd:${PORTSDIR}/textproc/cl-meta
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/meta/meta.asd:${PORTSDIR}/textproc/cl-meta

USE_ASDF_FASL=	yes
FASL_TARGET=	sbcl
FASL_BUILD=	yes

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
