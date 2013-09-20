# Created by: Henrik Motakef <henrik.motakef@web.de>
# $FreeBSD$

PORTNAME=	cl-ppcre
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	textproc lisp
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Portable Perl-Compatible Regular Expression for Common Lisp

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/cl-ppcre/cl-ppcre.asd:${PORTSDIR}/textproc/cl-ppcre
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/cl-ppcre/cl-ppcre.asd:${PORTSDIR}/textproc/cl-ppcre

USE_ASDF_FASL=	yes
FASL_TARGET=	clisp
FASL_BUILD=	yes

NO_STAGE=	yes
.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
