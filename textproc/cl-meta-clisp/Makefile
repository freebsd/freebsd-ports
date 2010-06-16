# New ports collection Makefile for:	cl-meta-clisp
# Date created:				20. March 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=	meta
PORTVERSION=	0.1
PORTREVISION=	4
CATEGORIES=	textproc lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A parser generator for Common Lisp

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/meta/meta.asd:${PORTSDIR}/textproc/cl-meta
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/meta/meta.asd:${PORTSDIR}/textproc/cl-meta

BROKEN=		does not build

USE_ASDF_FASL=	yes
FASL_TARGET=	clisp
FASL_BUILD=	yes

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
