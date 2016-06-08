# New ports collection makefile for:	pcbsd-role-media
#
# $FreeBSD$
#

PORTNAME=	pcbsd-role-media
PORTVERSION=	1421098703
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	joshms@pcbsd.org
COMMENT=	Includes media software

RUN_DEPENDS=	smplayer>=0:${PORTSDIR}/multimedia/smplayer \
		aqualung>=0:${PORTSDIR}/audio/aqualung \
		gtk-youtube-viewer>=0:${PORTSDIR}/multimedia/gtk-youtube-viewer \
		vlc>=0:${PORTSDIR}/multimedia/vlc \
		plexhometheater:${PORTSDIR}/multimedia/plexhometheater

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
