# New ports collection makefile for:	tunapie
# Date created:		2006-04-03
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	tunapie
PORTVERSION=	2.1.17
PORTREVISION=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S,.r,rc,}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Tuner for streaming internet radio and TV

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mx/__init__.py:${PORTSDIR}/lang/py-mx-base \
		streamripper:${PORTSDIR}/audio/streamripper

NO_BUILD=	yes
USE_PYTHON=	yes
USE_WX=	2.6+
WX_COMPS=	python:run

OPTIONS=	ADULT	"non-censored TV listings" off \
		VLC	"use vlc instead of mplayer" off \
		XINE	"use xine instead of mplayer" off \
		AUDACIOUS	"use audacious instead of xmms" off \
		BEEP_MEDIA_PLAYER	"use beep-media-player instead of xmms" off

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	tunapie.1
.endif

PLIST_SUB+=	DESKTOPDIR="${DESKTOPDIR:S,^${PREFIX}/,,}"

FIND_FILES=	-type f -and \( -name "install.sh" -or -name "*.py" \)

post-patch:
	@cd ${WRKSRC} && ${FIND} . ${FIND_FILES} -exec ${REINPLACE_CMD} \
		-e 's|%%DATADIR%%|${DATADIR}|g'\
		-e 's|%%DESKTOPDIR%%|${DESKTOPDIR}|g' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|%%MANPREFIX%%|${MANPREFIX}|g' \
		-e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|g' \
		-e 's|%%PYTHON_LIBDIR%%|${PYTHON_LIBDIR}|g' {} ";" \

do-install:
	@${MKDIR} ${DESKTOPDIR}
	@cd ${WRKSRC} && ./install.sh ${ADULT_TVLIST}
.if !defined(NO_INSTALL_MANPAGES)
	@${CP} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1/
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_ADULT)
ADULT_TVLIST=	--adult
.endif

# default VIDEOPLAYER
.if defined(WITH_XINE)
RUN_DEPENDS+=	xine:${PORTSDIR}/multimedia/xine
.elif defined(WITH_VLC)
RUN_DEPENDS+=	vlc:${PORTSDIR}/multimedia/vlc
.else
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

# default AUDIOPLAYER
.if defined(WITH_AUDACIOUS)
RUN_DEPENDS+=	${PREFIX}/lib/audacious/Container/pls.so:${PORTSDIR}/multimedia/audacious-plugins
.elifdef(WITH_BEEP_MEDIA_PLAYER)
RUN_DEPENDS+=	beep-media-player:${PORTSDIR}/multimedia/beep-media-player
.else
RUN_DEPENDS+=	xmms:${PORTSDIR}/multimedia/xmms
.endif

.include <bsd.port.post.mk>
