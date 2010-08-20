# Ports collection makefile for: freeswitch
# Date created: Augets 9, 2009
# Whom: Richard Neese <r.neese@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	freeswitch
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	ecrist@secure-computing.net
COMMENT=	FreeSwitch meta-port to pull in all the components

RUN_DEPENDS=	${LOCALBASE}/bin/freeswitch:${PORTSDIR}/net/freeswitch-core

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

OPTIONS=	SOUNDS	"Sound files for use with FreeSwitch PBX" on \
		MUSIC	"Music on hold for use with FreeSwitch PBX" on \
		PIZZA	"Install Pizza Shop voice demo" off \
		SCRIPTS	"Install Freeswitch various scripts" off \

.include <bsd.port.options.mk>

.if defined(WITH_SOUNDS)
RUN_DEPENDS+=	${LOCALBASE}/share/freeswitch/sounds/.freeswitch-sounds:${PORTSDIR}/audio/freeswitch-sounds
.endif

.if defined(WITH_MUSIC)
RUN_DEPENDS+=	${LOCALBASE}/share/freeswitch/sounds/.freeswitch-music:${PORTSDIR}/audio/freeswitch-music
.endif

.if defined(WITH_PIZZA)
RUN_DEPENDS+=	${LOCALBASE}/share/freeswitch/sounds/.pizza:${PORTSDIR}/misc/freeswitch-pizzademo
.endif

.if defined(WITH_SCRIPTS)
RUN_DEPENDS+=	${LOCALBASE}/etc/freeswitch/scripts/.freeswitch-scripts:${PORTSDIR}/misc/freeswitch-scripts
.endif

do-install: build
	@${DO_NADA}

.include <bsd.port.mk>
