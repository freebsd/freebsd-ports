# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	tunapie
PORTVERSION=	2.1.18
PORTREVISION=	4
CATEGORIES=	multimedia audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2.1
DISTNAME=	${PORTNAME}-${PORTVERSION:S,.r,rc,}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Tuner for streaming internet radio and TV

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mx/__init__.py:${PORTSDIR}/lang/py-mx-base \
		streamripper:${PORTSDIR}/audio/streamripper

NO_BUILD=	yes
USE_PYTHON=	yes
USE_WX=	2.6+
WX_COMPS=	python:run

OPTIONS_DEFINE=	ADULT AMAROK TOTEM VLC XINE AUDACIOUS
ADULT_DESC=	non-censored TV listings
AMAROK_DESC=	use amarok instead of mplayer
TOTEM_DESC=	use totem instead of mplayer
VLC_DESC=	use vlc instead of mplayer
XINE_DESC=	use xine instead of mplayer
AUDACIOUS_DESC=	use audacious instead of xmms

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	tunapie.1
.endif

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
.if !defined(NO_INSTALL_MANPAGES)
	@${CP} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/
.endif

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
.if ${PORT_OPTIONS:MAUDACIOUS}
RUN_DEPENDS+=	audacious:${PORTSDIR}/multimedia/audacious
.else
RUN_DEPENDS+=	xmms:${PORTSDIR}/multimedia/xmms
.endif

.include <bsd.port.post.mk>
