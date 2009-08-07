# New ports collection makefile for:	gpodder
# Date created:		20 October 2007
# Whom:			Chess Griffin <chess@chessgriffin.com>
#
# $FreeBSD$
#

PORTNAME=	gpodder
PORTVERSION=	0.15.0
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	gpodder
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	chess@chessgriffin.com
COMMENT=	A GTK2 podcast aggregrator written in Python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/feedparser.py:${PORTSDIR}/textproc/py-feedparser \
		convert:${PORTSDIR}/graphics/ImageMagick \
		help2man:${PORTSDIR}/misc/help2man
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/feedparser.py:${PORTSDIR}/textproc/py-feedparser \
		${PYTHON_SITELIBDIR}/pysqlite2/_sqlite.so:${PORTSDIR}/databases/py-pysqlite23 \
		wget:${PORTSDIR}/ftp/wget \
		xdg-open:${PORTSDIR}/devel/xdg-utils

USE_GMAKE=	yes
USE_GNOME=	pygtk2 libglade2
USE_GETTEXT=	yes
USE_PYTHON=	yes
PLIST_SUB=	PYDISTUTILS_EGGINFO=${PYDISTUTILS_EGGINFO}
INSTALLS_ICONS=	yes

MANCOMPRESSED=	no
MAN1=		${PORTNAME}.1 gpodder-backup.1

PORTDOCS=	COPYING PKG-INFO README

OPTIONS=	IPOD "iPod synchronization support" off \
		VIDEO "Video media support using mplayer" off \
		MP3TAG "MP3 ID3 tag update support" off \
		OGGTAG "Ogg Vorbis ID3 tag update support" off \
		OGG2MP3 "Ogg Vorbis conversion to MP3 support" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if defined(WITH_IPOD)
LIB_DEPENDS+=	gpod.5:${PORTSDIR}/audio/libgpod
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/madmodule.so:${PORTSDIR}/audio/py-mad
.endif

.if defined(WITH_VIDEO)
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer \
		${PYTHON_SITELIBDIR}/ID3.py:${PORTSDIR}/audio/py-id3
.endif

.if defined(WITH_MP3TAG)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/eyeD3/__init__.py:${PORTSDIR}/audio/py-eyed3
.endif

.if defined(WITH_OGGTAG)
RUN_DEPENDS+=	ogg123:${PORTSDIR}/audio/vorbis-tools
.endif

.if defined(WITH_OGG2MP3)
RUN_DEPENDS+=	oggdec:${PORTSDIR}/audio/vorbis-tools \
		lame:${PORTSDIR}/audio/lame
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
