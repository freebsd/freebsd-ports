# New ports collection Makefile for:	cl-meta-cmucl
# Date created:				16 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=		meta
PORTVERSION=		0.1
CATEGORIES=		textproc
MASTER_SITES=		ftp://ftp.linux.org.uk/pub/lisp/experimental/cclan/ \
			ftp://ftp.ntnu.no/pub/lisp/cclan/ \
			ftp://www.aarg.net/pub/cclan/ \
			http://thingamy.com/cclan/ \
			http://www-jcsu.jesus.cam.ac.uk/ftp/pub/cclan/
PKGNAMEPREFIX=		cl-
PKGNAMESUFFIX=		-cmucl
DISTFILES=		# use installed sources from CL_LIBDIR
EXTRACT_ONLY=		# use installed sources from CL_LIBDIR

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A parser generator for Common Lisp

BUILD_DEPENDS=		${LOCALBASE}/lib/common-lisp/meta/meta.asd:${PORTSDIR}/textproc/cl-meta \
			${LOCALBASE}/lib/common-lisp/asdf/cmuclfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-cmucl \
			lisp:${PORTSDIR}/lang/cmucl
RUN_DEPENDS=		${LOCALBASE}/lib/common-lisp/meta/meta.asd:${PORTSDIR}/textproc/cl-meta \
			${LOCALBASE}/lib/common-lisp/asdf/cmuclfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-cmucl \
			lisp:${PORTSDIR}/lang/cmucl

do-build:
	WRKSRC=${WRKSRC}/ FBSD_ASDF_COMPILE_PORT=t\
	lisp -nositeinit -noinit \
		-load ${LOCALBASE}/etc/asdf-init.lisp \
		-eval "(asdf:oos 'asdf:compile-op :meta)" \
		-eval "(quit)"

do-install:
	${MKDIR} ${PREFIX}/lib/common-lisp/meta/cmuclfasl
	${INSTALL_DATA} ${WRKSRC}/*.fasl ${PREFIX}/lib/common-lisp/meta/cmuclfasl/

.include <bsd.port.mk>
