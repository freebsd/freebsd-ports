# New ports collection Makefile for:	cl-ppcre-sbcl
# Date created:				16 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=	cl-ppcre
PORTVERSION=	0.5.4
CATEGORIES=	textproc
MASTER_SITES=	http://weitz.de/files/
PKGNAMESUFFIX=	-sbcl
DISTFILES=		# use installed sources from CL_LIBDIR
EXTRACT_ONLY=		# use installed sources from CL_LIBDIR

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable Perl-Compatible Regular Expression for Common Lisp

BUILD_DEPENDS=	${LOCALBASE}/lib/common-lisp/cl-ppcre/cl-ppcre.asd:${PORTSDIR}/textproc/cl-ppcre \
		${LOCALBASE}/lib/common-lisp/asdf/sbclfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-sbcl \
		sbcl:${PORTSDIR}/lang/sbcl
RUN_DEPENDS=	${LOCALBASE}/lib/common-lisp/cl-ppcre/cl-ppcre.asd:${PORTSDIR}/textproc/cl-ppcre \
		${LOCALBASE}/lib/common-lisp/asdf/sbclfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-sbcl \
		sbcl:${PORTSDIR}/lang/sbcl

do-build:
	FBSD_ASDF_COMPILE_PORT=t WRKSRC=${WRKSRC}/ \
	sbcl	--noinform --userinit /dev/null \
		--eval '#.(load "${LOCALBASE}/etc/asdf-init")' \
		--eval "(asdf:oos 'asdf:compile-op :cl-ppcre)" \
		--eval "(quit)"

do-install:
	${MKDIR} ${PREFIX}/lib/common-lisp/cl-ppcre/sbclfasl
	${INSTALL_DATA} ${WRKSRC}/*.fasl ${PREFIX}/lib/common-lisp/cl-ppcre/sbclfasl/

.include <bsd.port.mk>
