# New ports collection makefile for:	libdivxdecore
# Date created:		03 Feb 2001
# Whom:			Mario S F Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdivxdecore
PORTVERSION=	0.4.7
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://download.projectmayo.com/dnload/divx4linux/xmps/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	OpenDivX decoding engine from Project Mayo

ONLY_FOR_ARCHS=	i386
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_SIZE=	yes
INSTALLS_SHLIB=	yes
PLIST_SUB=	LIB_VERSION="${LIB_VERSION}"

LIB_VERSION=	0

post-install:
	@${LN} -sf ${PORTNAME}.so ${PREFIX}/lib/${PORTNAME}.so.${LIB_VERSION}

.include <bsd.port.mk>
