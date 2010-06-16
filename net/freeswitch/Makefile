# Ports collection makefile for: freeswitch
# Date created: Augets 9, 2009
# Whom: Richard Neese <r.neese@gmail.com>
#
# $FreeBSD$
#

PORTNAME=       freeswitch
PORTVERSION=    1.0.6
CATEGORIES=     net
MASTER_SITES=   # none
DISTFILES=      # none
EXTRACT_ONLY=   # none

MAINTAINER=     ecrist@secure-computing.net
COMMENT=        FreeSwitch meta-port to pull in all the components

NO_BUILD=	YES
SUB_FILES=      pkg-message

OPTIONS=        CORE         "FreeSwitch PBX Software" on \
		SOUNDS       "Sound files for use with FreeSwitch PBX" on \
		MUSIC        "Music on hold for use with FreeSwitch PBX" on

.include <bsd.port.options.mk>
.if defined(WITH_CORE)
RUN_DEPENDS+= freeswitch:${PORTSDIR}/net/freeswitch-core
.endif
.if defined(WITH_SOUNDS)
RUN_DEPENDS+= ${LOCALBASE}/share/freeswitch/sounds/.freeswitch-sounds:${PORTSDIR}/audio/freeswitch-sounds
.endif
.if defined(WITH_MUSIC)
RUN_DEPENDS+= ${LOCALBASE}/share/freeswitch/sounds/music:${PORTSDIR}/audio/freeswitch-music
.endif

do-install: build
	@${DO_NADA}

.include <bsd.port.mk>
