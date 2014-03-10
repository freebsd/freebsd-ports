# Created by: Richard Neese <r.neese@gmail.com>
# $FreeBSD$

PORTNAME=	freeswitch
PORTVERSION=	1.2.3
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

OPTIONS_DEFINE=	VANILLA INSIDEOUT CURL SOUNDS MUSIC SCRIPTS	

VANILLA_DESC=		Vanilla Dialplan Configs
INSIDEOUT_DESC=		Inside Out Basic Dialplan Configs
CURL_DESC=		Curl dialplan configs
SOUNDS_DESC=		Sound files for use with FreeSwitch PBX
MUSIC_DESC=		Music on hold for use with FreeSwitch PBX

OPTIONS_DEFAULT=	VANILLA SOUNDS MUSIC
NO_OPTIONS_SORT=        yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.for conf in vanilla sbc insideout curl
.if ${PORT_OPTIONS:M${conf:U}}
CNF?=	${conf}
.    if ${CNF} == ${conf}
RUN_DEPENDS+=	${LOCALBASE}/etc/freeswitch/conf/.${conf}:${PORTSDIR}/net/freeswitch-${conf}-devel
.    else
IGNORE=	will not allow multiple configuration options selected
.    endif
.  endif
.endfor
.undef CNF

.if ${PORT_OPTIONS:MSOUNDS}
RUN_DEPENDS+=	${LOCALBASE}/share/freeswitch/sounds/.freeswitch-sounds:${PORTSDIR}/audio/freeswitch-sounds
.endif

.if ${PORT_OPTIONS:MMUSIC}
RUN_DEPENDS+=	${LOCALBASE}/share/freeswitch/sounds/.freeswitch-music:${PORTSDIR}/audio/freeswitch-music
.endif

do-install: build
	@${DO_NADA}

.include <bsd.port.mk>
