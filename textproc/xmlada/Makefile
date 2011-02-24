# New ports collection makefile for:  xmlada
# Date created:                       12 December 2010
# Whom:                               John Marino <draco@marino.st>
#
# $FreeBSD$
#

PORTNAME=	xmlada
PORTVERSION=	4.1w
CATEGORIES=	textproc
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/
DISTFILES=	${PORTNAME}-${PORTVERSION}-${SNAPSHOT}.tar.bz2

MAINTAINER=	draco@marino.st
COMMENT=	Adacore XML suite for the Ada language

BUILD_DEPENDS=	gnat-aux>=20101204:${PORTSDIR}/lang/gnat-aux

SNAPSHOT=	20101125
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CC=		gnatgcc

.include <bsd.port.mk>
