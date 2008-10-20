# New ports collection makefile for:	bomstrip
# Date created:			14 June 2008
# Whom:				Peter Pentchev <roam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bomstrip
PORTVERSION=	9
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.xs4all.nl/~mechiel/projects/bomstrip/files/:main \
		http://devel.ringlet.net/textproc/bomstrip/:ringlet
DISTFILES=	${DISTNAME}.tgz:main,ringlet \
		${DISTNAME}-roam-02-extra-files.tar.gz:ringlet

PATCHFILES=	${DISTNAME}-roam-02.patch
PATCH_SITES=	http://devel.ringlet.net/textproc/bomstrip/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Strip Byte-Order Marks (BOM) from UTF-8 text

USE_GMAKE=	yes
MAKE_ENV+=	BINGRP="${BINGRP}"

MAN1=		bomstrip.1 bomstrip-files.1
MANCOMPRESSED=	yes

.include <bsd.port.mk>
