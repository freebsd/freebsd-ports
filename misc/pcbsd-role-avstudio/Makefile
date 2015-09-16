# New ports collection makefile for:	pcbsd-role-avstudio
#
# $FreeBSD$
#

PORTNAME=	pcbsd-role-avstudio
PORTVERSION=	1428097100
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	joshms@pcbsd.org
COMMENT=	Includes audio and video production software

RUN_DEPENDS=	audacity>=0:${PORTSDIR}/audio/audacity \
		avidemux>=0:${PORTSDIR}/multimedia/avidemux \
		kdenlive>=0:${PORTSDIR}/multimedia/kdenlive \
		pacpl>=0:${PORTSDIR}/audio/pacpl \
		cinepaint>=0:${PORTSDIR}/graphics/cinepaint \
		devede>=0:${PORTSDIR}/multimedia/devede

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
