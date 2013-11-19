# Created by: Richard Neese <r.neese@gmail.com>
# $FreeBSD$

PORTNAME=	freeswitch
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeSwitch meta-port to pull in all the components

DEPRECATED=	Depends on expired net/freeswitch-core
EXPIRATION_DATE=2013-12-19

CONFLICTS=	freeswitch-devel-[0-9]*

RUN_DEPENDS=	${LOCALBASE}/bin/freeswitch:${PORTSDIR}/net/freeswitch-core

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	SOUNDS MUSIC PIZZA SCRIPTS
OPTIONS_DEFAULT=	SOUNDS MUSIC
SOUNDS_DESC=	Sound files for use with FreeSwitch PBX
MUSIC_DESC=	Music on hold for use with FreeSwitch PBX
PIZZA_DESC=	Pizza Shop voice demo
SCRIPTS_DESC=	Freeswitch various scripts

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSOUNDS}
RUN_DEPENDS+=	${LOCALBASE}/share/freeswitch/sounds/.freeswitch-sounds:${PORTSDIR}/audio/freeswitch-sounds
.endif

.if ${PORT_OPTIONS:MMUSIC}
RUN_DEPENDS+=	${LOCALBASE}/share/freeswitch/sounds/.freeswitch-music:${PORTSDIR}/audio/freeswitch-music
.endif

.if ${PORT_OPTIONS:MPIZZA}
RUN_DEPENDS+=	${LOCALBASE}/share/freeswitch/sounds/.pizza:${PORTSDIR}/misc/freeswitch-pizzademo
.endif

.if ${PORT_OPTIONS:MSCRIPTS}
RUN_DEPENDS+=	${LOCALBASE}/etc/freeswitch/scripts/.freeswitch-scripts:${PORTSDIR}/misc/freeswitch-scripts
.endif

do-install: build
	@${DO_NADA}

.include <bsd.port.mk>
