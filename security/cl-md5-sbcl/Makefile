PORTNAME=	md5
PORTVERSION=	2.0.5
PORTREVISION=	8
CATEGORIES=	security lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Native MD5 implementation in Common Lisp
WWW=		https://www.cliki.net/MD5

LICENSE=	PD

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/flexi-streams/sbclfasl/stream.fasl:devel/cl-flexi-streams-sbcl \
		${LOCALBASE}/${CL_LIBDIR_REL}/md5/md5.asd:security/cl-md5
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/flexi-streams/sbclfasl/stream.fasl:devel/cl-flexi-streams-sbcl \
		${LOCALBASE}/${CL_LIBDIR_REL}/md5/md5.asd:security/cl-md5

USES=		cl
FASL_TARGET=	sbcl

.include <bsd.port.mk>
