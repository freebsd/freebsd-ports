# New ports collection makefile for:	libdivxdecore
# Date created:		03 Feb 2001
# Whom:			Mario S F Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdivxdecore
PORTVERSION=	0.4.7
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	OpenDivX decoding engine from Project Mayo

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
PLIST_SUB=	LIB_VERSION="${LIB_VERSION}"

CONFLICTS=	${PORTNAME}-devel-[0-9]*

LIB_VERSION=	0

post-install:
	@${LN} -sf ${PORTNAME}.so ${PREFIX}/lib/${PORTNAME}.so.${LIB_VERSION}

.include <bsd.port.mk>
