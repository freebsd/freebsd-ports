# New ports collection Makefile for:	cl-ppcre-clisp
# Date created:				16 May 2003
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$

PORTNAME=	cl-ppcre
PORTVERSION=	0.5.4
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://weitz.de/files/
PKGNAMESUFFIX=	-clisp
DISTFILES=

MAINTAINER=	henrik.motakef@web.de
COMMENT=	Portable Perl-Compatible Regular Expression for Common Lisp

BUILD_DEPENDS=	${LOCALBASE}/lib/common-lisp/cl-ppcre/cl-ppcre.asd:${PORTSDIR}/textproc/cl-ppcre \
		${LOCALBASE}/lib/common-lisp/asdf/clispfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-clisp \
		clisp:${PORTSDIR}/lang/clisp
RUN_DEPENDS=	${LOCALBASE}/lib/common-lisp/cl-ppcre/cl-ppcre.asd:${PORTSDIR}/textproc/cl-ppcre \
		${LOCALBASE}/lib/common-lisp/asdf/clispfasl/asdf.fasl:${PORTSDIR}/devel/cl-asdf-clisp \
		clisp:${PORTSDIR}/lang/clisp

do-build:
	FBSD_ASDF_COMPILE_PORT=t WRKSRC=${WRKSRC}/ \
	clisp	-q -ansi -norc \
		-i ${LOCALBASE}/etc/asdf-init \
		-x "(asdf:oos 'asdf:compile-op :cl-ppcre)"

do-install:
	${MKDIR} ${PREFIX}/lib/common-lisp/cl-ppcre/clispfasl
	${INSTALL_DATA} ${WRKSRC}/*.fasl ${PREFIX}/lib/common-lisp/cl-ppcre/clispfasl/

.include <bsd.port.mk>
