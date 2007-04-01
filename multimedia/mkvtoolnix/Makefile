# New ports collection makefile for:	mkvtoolnix
# Date created:		Tue Feb 24 02:09:12 UTC 2004
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mkvtoolnix
PORTVERSION=	2.0.2
CATEGORIES=	multimedia audio
MASTER_SITES=	http://www.bunkus.org/videotools/mkvtoolnix/sources/ CSME

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Tools to extract from/get info about/create Matroska media streams

LIB_DEPENDS=	FLAC.7:${PORTSDIR}/audio/flac \
		ebml:${PORTSDIR}/textproc/libebml \
		expat.6:${PORTSDIR}/textproc/expat2 \
		lzo2.2:${PORTSDIR}/archivers/lzo2 \
		matroska.0:${PORTSDIR}/multimedia/libmatroska \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		ogg.5:${PORTSDIR}/audio/libogg \
		pcrecpp.0:${PORTSDIR}/devel/pcre

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -lmagic -lz
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man --enable-lzo --enable-bz2 --disable-qt

MAN1=		base64tool.1 mkvextract.1 mkvinfo.1 mkvmerge.1
PLIST_FILES=	bin/base64tool bin/mkvextract bin/mkvinfo bin/mkvmerge

# data files
FILES_DATA=	\
		mkvmerge-gui.hhc \
		mkvmerge-gui.hhk \
		mkvmerge-gui.hhp \
		mkvmerge-gui.html
IMAGES_DATA=	\
		addingremovingattachments.gif \
		addremovefiles.gif \
		attachmentoptions.gif \
		audiotrackoptions.gif \
		chaptereditor.gif \
		generaltrackoptions.gif \
		jobmanager.gif \
		movietitle.gif \
		muxingwindow.gif \
		selectmkvmergeexecutable.gif \
		splitting.gif \
		textsubtitlestrackoptions.gif \
		trackselection.gif \
		videotrackoptions.gif
PLIST_FILES+=	${FILES_DATA:S|^|%%DATADIR%%/|} ${IMAGES_DATA:S|^|%%DATADIR%%/images/|}
PLIST_DIRS+=	%%DATADIR%%/images %%DATADIR%%

.ifndef(WITHOUT_WXGTK)
USE_WX=		yes
WX_UNICODE=	yes
WX_CONF_ARGS=	absolute
MAN1+=		mmg.1
PLIST_FILES+=	bin/mmg
.endif

pre-configure::
.ifndef(WITHOUT_WXGTK)
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> You can disable wxGTK2 support by defining"
	@${ECHO_MSG} "===>  WITHOUT_WXGTK"
	@${ECHO_MSG} "===>"
.endif

pre-install:
	@${INSTALL} -d ${DATADIR}/

.include <bsd.port.mk>
