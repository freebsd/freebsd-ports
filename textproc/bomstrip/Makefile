# Created by: Peter Pentchev <roam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bomstrip
PORTVERSION=	9
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.ueber.net/who/mjl/projects/bomstrip/files/:main \
		http://devel.ringlet.net/textproc/bomstrip/:ringlet
DISTFILES=	${DISTNAME}.tgz:main,ringlet \
		${DISTNAME}-roam-02-extra-files.tar.gz:ringlet

PATCHFILES=	${DISTNAME}-roam-02.patch
PATCH_SITES=	http://devel.ringlet.net/textproc/bomstrip/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Strip Byte-Order Marks (BOM) from UTF-8 text

LICENSE=	NONE

USES=		gmake
MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		STRIP=""

.include <bsd.port.mk>
