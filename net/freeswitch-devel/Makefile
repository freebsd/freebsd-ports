# Created by: Richard Neese <r.neese@gmail.com>
# $FreeBSD$

PORTNAME=	freeswitch
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	# none
PKGNAMESUFFIX=	-devel
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeSwitch meta-port to pull in all the components

RUN_DEPENDS=	freeswitch:${PORTSDIR}/net/freeswitch-core-devel

CONFLICTS=	freeswitch-core-[0-9]*

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	SOUNDS MUSIC

SOUNDS_DESC=		Sound files for use with FreeSwitch PBX
MUSIC_DESC=		Music on hold for use with FreeSwitch PBX

OPTIONS_DEFAULT=	SOUNDS MUSIC
NO_OPTIONS_SORT=        yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSOUNDS}
RUN_DEPENDS+=	${LOCALBASE}/share/freeswitch/sounds/.freeswitch-sounds:${PORTSDIR}/audio/freeswitch-sounds
.endif

.if ${PORT_OPTIONS:MMUSIC}
RUN_DEPENDS+=	${LOCALBASE}/share/freeswitch/sounds/.freeswitch-music:${PORTSDIR}/audio/freeswitch-music
.endif

do-install: build
	@${DO_NADA}

.include <bsd.port.mk>
