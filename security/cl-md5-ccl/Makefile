PORTNAME=	md5
PORTVERSION=	1.8.5
CATEGORIES=	security lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Native MD5 implementation in Common Lisp
WWW=		https://www.cliki.net/MD5

LICENSE=	PD

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/md5/md5.asd:security/cl-md5
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/md5/md5.asd:security/cl-md5

USES=		cl
FASL_TARGET=	ccl

.include <bsd.port.mk>
