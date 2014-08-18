# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	tunapie
PORTVERSION=	2.1.18
PORTREVISION=	6
CATEGORIES=	multimedia audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2.1
DISTNAME=	${PORTNAME}-${PORTVERSION:S,.r,rc,}

MAINTAINER= ports@FreeBSD.org
COMMENT=	Tuner for streaming internet radio and TV

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mx/__init__.py:${PORTSDIR}/lang/py-mx-base \
		streamripper:${PORTSDIR}/audio/streamripper

NO_BUILD=	yes
USE_PYTHON=	yes
USE_WX=		3.0+
WX_COMPS=	python:run

OPTIONS_DEFINE=	ADULT AMAROK TOTEM VLC XINE
ADULT_DESC=	non-censored TV listings
AMAROK_DESC=	use amarok instead of mplayer
TOTEM_DESC=	use totem instead of mplayer
VLC_DESC=	use vlc instead of mplayer
XINE_DESC=	use xine instead of mplayer

MAN1=	tunapie.1

PLIST_SUB+=	DESKTOPDIR="${DESKTOPDIR:S,^${PREFIX}/,,}"

FIND_FILES=	-type f -and \( -name "install.sh" -or -name "*.py" \)

NO_STAGE=	yes
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
	@${CP} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MADULT}
ADULT_TVLIST=	--adult
.endif

# default VIDEOPLAYER
.if ${PORT_OPTIONS:MAMAROK}
RUN_DEPENDS+=	amarok:${PORTSDIR}/audio/amarok
.elif ${PORT_OPTIONS:MTOTEM}
RUN_DEPENDS+=	totem:${PORTSDIR}/multimedia/totem
.elif ${PORT_OPTIONS:MXINE}
RUN_DEPENDS+=	xine:${PORTSDIR}/multimedia/xine
.elif ${PORT_OPTIONS:MVLC}
RUN_DEPENDS+=	vlc:${PORTSDIR}/multimedia/vlc
.else
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

# default AUDIOPLAYER
RUN_DEPENDS+=	audacious:${PORTSDIR}/multimedia/audacious

.include <bsd.port.post.mk>
