PORTNAME=	cl-ppcre
PORTVERSION=	2.1.2
PORTREVISION=	17
CATEGORIES=	textproc lisp
DISTFILES=	# none

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Portable Perl-Compatible Regular Expression for Common Lisp
WWW=		http://www.weitz.de/cl-ppcre/

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/cl-ppcre/cl-ppcre.asd:textproc/cl-ppcre
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/cl-ppcre/cl-ppcre.asd:textproc/cl-ppcre

USES=		cl
FASL_TARGET=	sbcl

.include <bsd.port.mk>
