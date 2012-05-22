# Ports collection makefile for: freeswitch Version 1.2
# Date created: May 14, 2012
# Whom: Richard Neese <r.neese@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	freeswitch
PORTVERSION=	1.2
CATEGORIES=	net
MASTER_SITES=	# none
PKGNAMESUFFIX=	-devel
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	r.neese@gmail.com
COMMENT=	FreeSwitch meta-port to pull in all the components

RUN_DEPENDS=	freeswitch:${PORTSDIR}/net/freeswitch-core-devel

CONFLICTS=	freeswitch-core-[0-9]*

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

OPTIONS=	VANILLA		"Vanilla Dialplan Configs" off \
		SBC		"Session Border Conroller configs" off \
		INSIDEOUT	"Inside Out Basic Dialplan Configs" off \
		CURL		"Curl dialplan configs" off \
		SOUNDS		"Sound files for use with FreeSwitch PBX" off \
		MUSIC		"Music on hold for use with FreeSwitch PBX" off \
		PIZZADEMO	"Install Pizza Shop voice demo" off \
		SCRIPTS		"Install Freeswitch various scripts" off

.include <bsd.port.options.mk>

.for conf in vanilla sbc insideout curl
.  if defined(WITH_${conf:U})
CNF?=	${conf}
.    if ${CNF} == ${conf}
RUN_DEPENDS+=	${LOCALBASE}/etc/freeswitch/conf/.${conf}:${PORTSDIR}/net/freeswitch-${conf}-devel
.    else
IGNORE=	will not allow multiple configuration options selected
.    endif
.  endif
.endfor
.undef CNF

.if defined(WITH_SOUNDS)
RUN_DEPENDS+=	${LOCALBASE}/share/freeswitch/sounds/.freeswitch-sounds:${PORTSDIR}/audio/freeswitch-sounds
.endif

.if defined(WITH_MUSIC)
RUN_DEPENDS+=	${LOCALBASE}/share/freeswitch/sounds/.freeswitch-music:${PORTSDIR}/audio/freeswitch-music
.endif

.if defined(WITH_PIZZADEMO)
RUN_DEPENDS+=	${LOCALBASE}/share/freeswitch/sounds/.pizza:${PORTSDIR}/misc/freeswitch-pizzademo-devel
.endif

.if defined(WITH_SCRIPTS)
RUN_DEPENDS+=	${LOCALBASE}/etc/freeswitch/scripts/.freeswitch-scripts:${PORTSDIR}/misc/freeswitch-scripts-devel
.endif

do-install: build
	@${DO_NADA}

.include <bsd.port.mk>
