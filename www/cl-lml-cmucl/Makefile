# New ports collection Makefile for:	cl-lml-cmucl
# Date created:				18 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=		lml
PORTVERSION=		2.3.4
CATEGORIES=		www textproc
MASTER_SITES=		http://files.b9.com/lml/
PKGNAMEPREFIX=		cl-
PKGNAMESUFFIX=		-cmucl
DISTFILES=		# use installed sources from CL_LIBDIR
EXTRACT_ONLY=		# use installed sources from CL_LIBDIR

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Lisp Markup Language

BUILD_DEPENDS=		${LOCALBASE}/lib/common-lisp/system-registry/lml.asd:${PORTSDIR}/www/cl-lml \
			${LOCALBASE}/lib/common-lisp/asdf/cmuclfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-cmucl \
			lisp:${PORTSDIR}/lang/cmucl
RUN_DEPENDS=		${LOCALBASE}/lib/common-lisp/system-registry/lml.asd:${PORTSDIR}/www/cl-lml \
			${LOCALBASE}/lib/common-lisp/asdf/cmuclfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-cmucl \
			lisp:${PORTSDIR}/lang/cmucl

do-build:
	WRKSRC=${WRKSRC}/ FBSD_ASDF_COMPILE_PORT=t\
	lisp -nositeinit -noinit \
		-load ${LOCALBASE}/etc/asdf-init.lisp \
		-eval "(asdf:oos 'asdf:compile-op :lml)" \
		-eval "(quit)"

do-install:
	${MKDIR} ${PREFIX}/lib/common-lisp/lml/cmuclfasl
	${INSTALL_DATA} ${WRKSRC}/*.fasl ${PREFIX}/lib/common-lisp/lml/cmuclfasl/

.include <bsd.port.mk>
