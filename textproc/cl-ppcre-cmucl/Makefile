# New ports collection Makefile for:	cl-ppcre-cmucl
# Date created:				16 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=	cl-ppcre
PORTVERSION=	0.5.4
CATEGORIES=	textproc
MASTER_SITES=	http://weitz.de/files/
PKGNAMESUFFIX=	-cmucl
DISTFILES=		# use installed sources from CL_LIBDIR
EXTRACT_ONLY=		# use installed sources from CL_LIBDIR

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable Perl-Compatible Regular Expression for Common Lisp

BUILD_DEPENDS=	${LOCALBASE}/lib/common-lisp/cl-ppcre/cl-ppcre.asd:${PORTSDIR}/textproc/cl-ppcre \
		${LOCALBASE}/lib/common-lisp/asdf/cmuclfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-cmucl \
		lisp:${PORTSDIR}/lang/cmucl
RUN_DEPENDS=	${LOCALBASE}/lib/common-lisp/cl-ppcre/cl-ppcre.asd:${PORTSDIR}/textproc/cl-ppcre \
		${LOCALBASE}/lib/common-lisp/asdf/cmuclfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-cmucl \
		lisp:${PORTSDIR}/lang/cmucl

do-build:
	WRKSRC=${WRKSRC}/ FBSD_ASDF_COMPILE_PORT=t\
	lisp -nositeinit -noinit \
		-load ${LOCALBASE}/etc/asdf-init.lisp \
		-eval "(asdf:oos 'asdf:compile-op :cl-ppcre)" \
		-eval "(quit)"

do-install:
	${MKDIR} ${PREFIX}/lib/common-lisp/cl-ppcre/cmuclfasl
	${INSTALL_DATA} ${WRKSRC}/*.fasl ${PREFIX}/lib/common-lisp/cl-ppcre/cmuclfasl/

.include <bsd.port.mk>
