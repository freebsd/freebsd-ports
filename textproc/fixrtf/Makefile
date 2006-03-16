# New ports collection makefile for:	fixrtf
# Date created:		3 Mar 2006
# Whom:			Xin LI <delphij@FreeBSD.org>
#
# $FreeBSD$
#
# This port is self contained in the src directory.
#

PORTNAME=	fixrtf
PORTVERSION=	0.1.20060303
CATEGORIES=	textproc
MASTER_SITES=	# none
DISTFILES=	# none

# Note: Updates from intron@intron.ac should also be
# considered as maintainer updates.

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	A patch making it possible to embed PNGs into RTFs

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/src

SRC=		${.CURDIR}/src

do-fetch:
	@${DO_NADA}

pre-patch:
	@${CP} -R ${SRC} ${WRKDIR}

.include <bsd.port.mk>
