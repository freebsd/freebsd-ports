# New ports collection Makefile for:	cl-lml-clisp
# Date created:				18 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=		lml
PORTVERSION=		2.5.2
PORTREVISION=	1
CATEGORIES=		www textproc
MASTER_SITES=		http://files.b9.com/lml/
PKGNAMEPREFIX=		cl-
PKGNAMESUFFIX=		-clisp
DISTFILES=		# use installed sources from CL_LIBDIR
EXTRACT_ONLY=		# use installed sources from CL_LIBDIR

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Lisp Markup Language

BUILD_DEPENDS=		${LOCALBASE}/lib/common-lisp/system-registry/lml.asd:${PORTSDIR}/www/cl-lml \
			${LOCALBASE}/lib/common-lisp/asdf/clispfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-clisp \
			clisp:${PORTSDIR}/lang/clisp
RUN_DEPENDS=		${LOCALBASE}/lib/common-lisp/system-registry/lml.asd:${PORTSDIR}/www/cl-lml \
			${LOCALBASE}/lib/common-lisp/asdf/clispfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-clisp \
			clisp:${PORTSDIR}/lang/clisp

do-build:
	WRKSRC=${WRKSRC}/ FBSD_ASDF_COMPILE_PORT=t\
	clisp	-q -ansi -norc \
		-i ${LOCALBASE}/etc/asdf-init \
		-x "(asdf:oos 'asdf:compile-op :lml)"

do-install:
	${MKDIR} ${PREFIX}/lib/common-lisp/lml/clispfasl
	${INSTALL_DATA} ${WRKSRC}/*.fasl ${PREFIX}/lib/common-lisp/lml/clispfasl/

.include <bsd.port.mk>
