PORTNAME=	meta
PORTVERSION=	0.1
PORTREVISION=	93
PORTEPOCH=	1
CATEGORIES=	textproc lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Parser generator for Common Lisp
WWW=		http://home.pipeline.com/~hbaker1/Prag-Parse.html

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/meta/meta.asd:textproc/cl-meta
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/meta/meta.asd:textproc/cl-meta

USES=		cl
FASL_TARGET=	sbcl

.include <bsd.port.mk>
