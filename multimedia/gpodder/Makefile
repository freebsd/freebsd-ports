# New ports collection makefile for:	gpodder
# Date created:		20 October 2007
# Whom:			Chess Griffin <chess@chessgriffin.com>
#
# $FreeBSD$
#

PORTNAME=	gpodder
PORTVERSION=	2.1
CATEGORIES=	multimedia
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK2 podcast aggregrator written in Python

RUN_DEPENDS=	py*-pysqlite>=2.3:${PORTSDIR}/databases/py-pysqlite23 \
		py*-dbus>=0:${PORTSDIR}/devel/py-dbus \
		py*-notify>=0:${PORTSDIR}/devel/py-notify \
		xdg-open:${PORTSDIR}/devel/xdg-utils \
		wget:${PORTSDIR}/ftp/wget \
		gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme \
		py*-feedparser>=0:${PORTSDIR}/textproc/py-feedparser

OPTIONS=	COVERART "Cover Art syncing support" off \
		IPOD "iPod synchronization support" off \
		MP3TAG "MP3 ID3 tag update support" off \
		OGG2MP3 "Ogg Vorbis conversion to MP3 support" off \
		SHOWNOTES "HTML episode shownotes support" off \
		VIDEO "Video media support using mplayer" off

USE_PYTHON=	yes
USE_GNOME=	pygtk2
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
INSTALLS_EGGINFO=yes

MAN1=		gpo.1 ${PORTNAME}.1 ${PORTNAME}-backup.1

.include <bsd.port.pre.mk>

.if defined(WITH_COVERART)
RUN_DEPENDS+=	py*-imaging>=0:${PORTSDIR}/graphics/py-imaging
.endif

.if defined(WITH_IPOD)
LIB_DEPENDS+=	gpod.5:${PORTSDIR}/audio/libgpod
RUN_DEPENDS+=	py*-mad>=0:${PORTSDIR}/audio/py-mad
.if !exists(${PYTHON_SITELIBDIR}/gpod/__init__.py)
IGNORE=		Requires Python bindings for libgpod. Please uninstall libgpod and reinstall with Python support.
.endif
.endif

.if defined(WITH_MP3TAG)
RUN_DEPENDS+=	py*-eyed3>=0:${PORTSDIR}/audio/py-eyed3
.endif

.if defined(WITH_OGG2MP3)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame \
		oggdec:${PORTSDIR}/audio/vorbis-tools
.endif

.if defined(WITH_SHOWNOTES)
USE_GNOME+=	pygnomeextras
.endif

.if defined(WITH_VIDEO)
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in PKG-INFO README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
