# New ports collection Makefile for:	cl-lml-sbcl
# Date created:				18 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=		lml
PORTVERSION=		2.3.4
CATEGORIES=		www textproc
MASTER_SITES=		http://files.b9.com/lml/
PKGNAMEPREFIX=		cl-
PKGNAMESUFFIX=		-sbcl
DISTFILES=		# use installed sources from CL_LIBDIR
EXTRACT_ONLY=		# use installed sources from CL_LIBDIR

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Lisp Markup Language

BUILD_DEPENDS=		${LOCALBASE}/lib/common-lisp/system-registry/lml.asd:${PORTSDIR}/www/cl-lml \
			${LOCALBASE}/lib/common-lisp/asdf/sbclfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-sbcl \
			sbcl:${PORTSDIR}/lang/sbcl
RUN_DEPENDS=		${LOCALBASE}/lib/common-lisp/system-registry/lml.asd:${PORTSDIR}/www/cl-lml \
			${LOCALBASE}/lib/common-lisp/asdf/sbclfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-sbcl \
			sbcl:${PORTSDIR}/lang/sbcl

do-build:
	WRKSRC=${WRKSRC}/ FBSD_ASDF_COMPILE_PORT=t\
	sbcl	--noinform --userinit /dev/null \
		--eval '#.(load "${LOCALBASE}/etc/asdf-init")' \
		--eval "(asdf:oos 'asdf:compile-op :lml)" \
		--eval "(quit)"

do-install:
	${MKDIR} ${PREFIX}/lib/common-lisp/lml/sbclfasl
	${INSTALL_DATA} ${WRKSRC}/*.fasl ${PREFIX}/lib/common-lisp/lml/sbclfasl/

.include <bsd.port.mk>
