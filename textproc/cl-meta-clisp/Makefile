# New ports collection Makefile for:	cl-meta-clisp
# Date created:				20. March 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=		meta
PORTVERSION=		20011114.1
PORTREVISION=	1
CATEGORIES=		textproc
MASTER_SITES=		ftp://ftp.linux.org.uk/pub/lisp/experimental/cclan/ \
			ftp://ftp.ntnu.no/pub/lisp/cclan/ \
			ftp://www.aarg.net/pub/cclan/ \
			http://thingamy.com/cclan/ \
			http://www-jcsu.jesus.cam.ac.uk/ftp/pub/cclan/
PKGNAMEPREFIX=		cl-
PKGNAMESUFFIX=		-clisp
DISTFILES=		# use installed sources from CL_LIBDIR
EXTRACT_ONLY=		# use installed sources from CL_LIBDIR

MAINTAINER=		henrik.motakef@web.de
COMMENT=		A parser generator for Common Lisp

BUILD_DEPENDS=		${LOCALBASE}/lib/common-lisp/meta/meta.asd:${PORTSDIR}/textproc/cl-meta \
			${LOCALBASE}/lib/common-lisp/asdf/clispfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-clisp \
			clisp:${PORTSDIR}/lang/clisp
RUN_DEPENDS=		${LOCALBASE}/lib/common-lisp/meta/meta.asd:${PORTSDIR}/textproc/cl-meta \
			${LOCALBASE}/lib/common-lisp/asdf/clispfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-clisp \
			clisp:${PORTSDIR}/lang/clisp

do-build:
	FBSD_ASDF_COMPILE_PORT=t WRKSRC=${WRKSRC}/ \
	clisp	-q -ansi -norc -E ISO-8859-1 \
		-i ${LOCALBASE}/etc/asdf-init \
		-x "(asdf:oos 'asdf:compile-op :meta)"

do-install:
	${MKDIR} ${PREFIX}/lib/common-lisp/meta/clispfasl
	${INSTALL_DATA} ${WRKSRC}/*.fasl ${PREFIX}/lib/common-lisp/meta/clispfasl/

.include <bsd.port.mk>
