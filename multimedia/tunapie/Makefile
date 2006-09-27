# New ports collection makefile for:	tunapie
# Date created:		2006-04-03
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	tunapie
PORTVERSION=	1.0
CATEGORIES=	multimedia audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION:S|.r4.3|-rc4-3|}

MAINTAINER=	nivit@email.it
COMMENT=	Tuner for streaming internet radio and TV

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mx/__init__.py:${PORTSDIR}/lang/py-mx-base \
		${PYTHON_SITELIBDIR}/${WX_PYTHON_DIR}/wxPython/_wx.py:${PORTSDIR}/x11-toolkits/py-wxPython26 \
		streamripper:${PORTSDIR}/audio/streamripper \
		xmms:${PORTSDIR}/multimedia/xmms

NO_BUILD=	yes
USE_PYTHON=	yes

OPTIONS=	ADULT	"non-censored TV listings" off \
		XINE	"use xine instead of mplayer" off

MAN1=	tunapie.1
PLIST_SUB+=	DESKTOPDIR="${DESKTOPDIR:S,^${PREFIX}/,,}"

WRKSRC=	${WRKDIR}/${DISTNAME:C/-rc4-3$/_rc4/}

FIND_FILES=	-type f -and \( -name "install.sh" -or -name "*.py" \)

post-patch:
	cd ${WRKSRC} && ${FIND} . ${FIND_FILES} -exec ${REINPLACE_CMD} \
		-e 's|%%DATADIR%%|${DATADIR}|g'\
		-e 's|%%DESKTOPDIR%%|${DESKTOPDIR}|g' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|%%MANPREFIX%%|${MANPREFIX}|g' \
		-e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%VIDEOPLAYER%%|${VIDEOPLAYER}|g' \
		-e 's|%%X11BASE%%|${X11BASE}|g' \
		-e 's|wxversion.select("2.6")|wxversion.select("${WX_PYTHON_DIR:S/^wx-//g}")|g' {} \;

do-install:
	${MKDIR} ${DATADIR}
	${MKDIR} ${DESKTOPDIR}
	cd ${WRKSRC} && ./install.sh ${ADULT_TVLIST}

.include <bsd.port.pre.mk>

.if defined(WITH_ADULT)
ADULT_TVLIST=	--adult
.endif

.if defined(WITH_XINE)
RUN_DEPENDS+=	xine:${PORTSDIR}/multimedia/xine
VIDEOPLAYER=	${X11BASE}/bin/xine
.else
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
VIDEOPLAYER=	${LOCALBASE}/bin/mplayer
.endif

.if defined(WITH_UNICODE) && (${OSVERSION} > 500000)
WX_PYTHON_DIR=	wx-2.6-gtk2-unicode
.else
WX_PYTHON_DIR=	wx-2.6-gtk2-ansi
.endif

.include <bsd.port.post.mk>
