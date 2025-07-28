PORTNAME=	lml
PORTVERSION=	2.5.7
PORTREVISION=	98
CATEGORIES=	www textproc
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Lisp Markup Language
WWW=		http://lml.b9.com/

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/system-registry/lml.asd:www/cl-lml
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/system-registry/lml.asd:www/cl-lml

USES=		cl
FASL_TARGET=	sbcl

.include <bsd.port.mk>
