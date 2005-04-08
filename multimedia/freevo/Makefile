# New ports collection makefile for:	freevo
# Date created:		April 10 2004
# Whom:			Lewis Thompson (purple@lewiz.net)
#
# $FreeBSD$
#

PORTNAME=	freevo
PORTVERSION=	1.5.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freevo

MAINTAINER=	lewiz@compsoc.man.ac.uk
COMMENT=	Open source digital jukebox

NO_BUILD=	yes

RUN_DEPENDS=	aumix:${PORTSDIR}/audio/aumix \
		${PYTHON_SITELIBDIR}/osd/__init__.py:${PORTSDIR}/misc/py-osd \
		${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/twisted/__init__.py:${PORTSDIR}/devel/py-twisted \
		${PYTHON_SITELIBDIR}/mmpython/__init__.py:${PORTSDIR}/multimedia/mmpython \
		${PYTHON_SITELIBDIR}/_xmlplus/__init__.py:${PORTSDIR}/textproc/py-xml \

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes
PKGINSTALL=	pkg-install

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
CONF=		${PREFIX}/etc/${PORTNAME}

OPTIONS=	MPLAYER	"Enable mplayer video playback support" On \
		XINE "Enable xine video playback support" On \
		MAME "Enable xmame game support" Off \
		SNES9X "Enable snes9x game support" Off \
		ZSNES "Enable zsnes game support" Off \
		XMLTV "Enable TV guide listings support" On \
		CDPARANOIA "Enable cdparanoia audio extraction support" On \
		LAME "Enable lame MP3 encoding support" On \
		OGG "Enable Ogg Vorbis encoding support" On \
		FLAC "Enable FLAC encoding support" Off \
		LIRC "Enable lirc remote control support" On

.include <bsd.port.pre.mk>

###
# AUTODETECTION
###

.if exists(${X11BASE}/bin/xmame) && !defined(WITHOUT_MAME)
WITH_MAME=	YES
.endif

.if exists(${X11BASE}/bin/snes9x) && !defined(WITHOUT_SNES9X)
WITH_SNES9X=	YES
.endif

.if exists(${X11BASE}/bin/zsnes) && !defined(WITHOUT_ZSNES)
WITH_ZSNES=	YES
.endif

.if exists(${LOCALBASE}/bin/flac) && !defined(WITHOUT_FLAC)
WITH_FLAC=	YES
.endif

###
# CONFIGURE RUN_DEPENDS
###

.if !defined(WITHOUT_MPLAYER)
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if !defined(WITHOUT_XINE)
RUN_DEPENDS+=	xine:${PORTSDIR}/multimedia/xine
.endif

.if defined(WITH_MAME)
RUN_DEPENDS+=	xmame:${PORTSDIR}/emulators/xmame
.endif

.if defined(WITH_SNES9X)
RUN_DEPENDS+=	snes9x:${PORTSDIR}/emulators/snes9x
.endif

.if defined(WITH_ZSNES)
RUN_DEPENDS+=	zsnes:${PORTSDIR}/emulators/zsnes
.endif

.if !defined(WITHOUT_XMLTV)
RUN_DEPENDS+=	tv_cat:${PORTSDIR}/textproc/p5-xmltv
.endif

.if !defined(WITHOUT_CDPARANOIA)
RUN_DEPENDS+=	cdparanoia:${PORTSDIR}/audio/cdparanoia
.endif

.if !defined(WITHOUT_LAME)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

.if !defined(WITHOUT_OGG)
RUN_DEPENDS+=	oggenc:${PORTSDIR}/audio/vorbis-tools
.endif

.if defined(WITH_FLAC)
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif

.if !defined(WITHOUT_LIRC)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pylircmodule.so:${PORTSDIR}/comms/py-lirc
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/freevo|${PREFIX}/etc/freevo|' ${WRKSRC}/freevo_config.py
	@${REINPLACE_CMD} -e 's|/etc/freevo|${PREFIX}/etc/freevo|' ${WRKSRC}/local_conf.py.example

pre-install:
	@BATCH="${BATCH}" ${SH} ${PKGINSTALL} PRE-INSTALL

post-install:
	@${MKDIR} ${CONF} && ${CHMOD} a+rx ${CONF}
	${INSTALL_DATA} ${WRKSRC}/local_conf.py.example ${CONF}
	@${SED} 's|%%PREFIX%%|${PREFIX}|' ${FILESDIR}/freevo.sh.sample > ${WRKDIR}/freevo.sh.sample
	${INSTALL_SCRIPT} ${WRKDIR}/freevo.sh.sample ${PREFIX}/etc/rc.d/
	@${SED} 's|%%PREFIX%%|${PREFIX}|' ${PKGMESSAGE}

.include <bsd.port.post.mk>
