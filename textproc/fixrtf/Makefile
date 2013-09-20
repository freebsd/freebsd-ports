# Created by: Xin LI <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fixrtf
PORTVERSION=	0.1.20060303
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	# none
DISTFILES=	# none

# Note: Updates from intron@intron.ac should also be
# considered as maintainer updates.

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	A patch making it possible to embed PNGs into RTFs

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/src

SRC=		${.CURDIR}/src

NO_STAGE=	yes
do-fetch:
	@${DO_NADA}

pre-patch:
	@${CP} -R ${SRC} ${WRKDIR}

.include <bsd.port.mk>
