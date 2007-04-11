# New ports collection makefile for:	tunapie
# Date created:		2006-04-03
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	tunapie
PORTVERSION=	1.4.1
CATEGORIES=	multimedia audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Tuner for streaming internet radio and TV

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mx/__init__.py:${PORTSDIR}/lang/py-mx-base \
		streamripper:${PORTSDIR}/audio/streamripper

NO_BUILD=	yes
USE_PYTHON=	yes
USE_WX=	2.6
WX_COMPS=	python:run

OPTIONS=	ADULT	"non-censored TV listings" off \
		XINE	"use xine instead of mplayer" off \
		AUDACIOUS	"use audacious instead of xmms" off \
		BEEP_MEDIA_PLAYER	"use beep-media-player instead of xmms" off

MAN1=	tunapie.1
PLIST_SUB+=	DESKTOPDIR="${DESKTOPDIR:S,^${PREFIX}/,,}"

WRKSRC=	${WRKDIR}/${DISTNAME:C/-rc4-3$/_rc4/}

FIND_FILES=	-type f -and \( -name "install.sh" -or -name "*.py" \)

post-patch:
	@cd ${WRKSRC} && ${FIND} . ${FIND_FILES} -exec ${REINPLACE_CMD} \
		-e 's|%%DATADIR%%|${DATADIR}|g'\
		-e 's|%%DESKTOPDIR%%|${DESKTOPDIR}|g' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|%%MANPREFIX%%|${MANPREFIX}|g' \
		-e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%AUDIOPLAYER%%|${AUDIOPLAYER}|g' \
		-e 's|%%VIDEOPLAYER%%|${VIDEOPLAYER}|g' \
		-e 's|%%X11BASE%%|${X11BASE}|g' {} ";"

do-install:
	@${MKDIR} ${DESKTOPDIR}
	@cd ${WRKSRC} && ./install.sh ${ADULT_TVLIST}

.include <bsd.port.pre.mk>

.if defined(WITH_ADULT)
ADULT_TVLIST=	--adult
.endif

# default VIDEOPLAYER
.if defined(WITH_XINE)
RUN_DEPENDS+=	xine:${PORTSDIR}/multimedia/xine
VIDEOPLAYER=	${X11BASE}/bin/xine
.else
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
VIDEOPLAYER=	${LOCALBASE}/bin/mplayer
.endif

# default AUDIOPLAYER
.if defined(WITH_AUDACIOUS)
RUN_DEPENDS+=	${PREFIX}/lib/audacious/Container/libpls.so:${PORTSDIR}/multimedia/audacious-plugins
AUDIOPLAYER=	${LOCALBASE}/bin/audacious
.elifdef(WITH_BEEP_MEDIA_PLAYER)
RUN_DEPENDS+=	beep-media-player:${PORTSDIR}/multimedia/beep-media-player
AUDIOPLAYER=	${LOCALBASE}/bin/beep-media-player
.else
RUN_DEPENDS+=	xmms:${PORTSDIR}/multimedia/xmms
AUDIOPLAYER=	${X11BASE}/bin/xmms
.endif

.include <bsd.port.post.mk>
