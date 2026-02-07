PORTNAME=	lml
PORTVERSION=	2.5.7
CATEGORIES=	www textproc
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Lisp Markup Language
WWW=		http://lml.b9.com/

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/system-registry/lml.asd:www/cl-lml
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/system-registry/lml.asd:www/cl-lml

USES=		cl
FASL_TARGET=	clisp
LISP_EXTRA_ARG=	-E UTF-8

.include <bsd.port.mk>
