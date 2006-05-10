# New ports collection makefile for:	qvamps
# Date created:		Thu Jan  5 20:49:59 UTC 2006
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qvamps
PORTVERSION=	0.20
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	vamps

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Dvd rip gui written in qt that uses vamps and dvdauthor

BUILD_DEPENDS=	puic:${PORTSDIR}/x11-toolkits/p5-qt \
		swig1.3:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	dvdread.3:${PORTSDIR}/multimedia/libdvdread
RUN_DEPENDS=	\
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		mplex:${PORTSDIR}/multimedia/mjpegtools \
		ppmtoy4m:${PORTSDIR}/multimedia/mjpegtools \
		puic:${PORTSDIR}/x11-toolkits/p5-qt \
		spumux:${PORTSDIR}/multimedia/dvdauthor \
		play_cell:${PORTSDIR}/multimedia/vamps \
		vamps:${PORTSDIR}/multimedia/vamps

CONFLICTS=	lxdvdrip-{{0.,1.[0-3],1.4[0-7]}*
OPTIONS=	MPLAYER "Enable DVD playing using mplayer" on

USE_GMAKE=	yes
USE_PERL5=	yes
MAKE_ENV=	\
		CC="${CC}" \
		LDFLAGS="${LDFLAGS}"

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/qvamps \
		lib/qvamps/LibDvdRead.so \
		%%DATADIR%%/lib/DesignerMimeSourceFactory_qvamps.pm \
		%%DATADIR%%/lib/DvdIfoRead.pm \
		%%DATADIR%%/lib/DvdMaker.pm \
		%%DATADIR%%/lib/FpcMgr.pm \
		%%DATADIR%%/lib/Iso639.pm \
		%%DATADIR%%/lib/LibDvdRead.pm \
		%%DATADIR%%/lib/MainWindow.pm \
		%%DATADIR%%/lib/MenuDisplay.pm \
		%%DATADIR%%/lib/MenuPreview.pm \
		%%DATADIR%%/lib/MenuTableItems.pm \
		%%DATADIR%%/lib/MenuWriter.pm \
		%%DATADIR%%/lib/QVamps.pm \
		%%DATADIR%%/lib/TitleListItems.pm \
		%%DATADIR%%/lib/VTSList.pm \
		%%DATADIR%%/lib/VTSListItems.pm \
		%%DATADIR%%/lib/XmlWriter.pm \
		%%DATADIR%%/lib/mainwindow.ui.pm \
		%%DATADIR%%/lib/menupreview.ui.pm \
		%%DATADIR%%/lib/vtslist.ui.pm \
		%%DATADIR%%/penguin.jpg \
		%%DATADIR%%/penguin_ntsc.mpg \
		%%DATADIR%%/penguin_pal.mpg \
		%%DATADIR%%/silence.mpa \
		%%DATADIR%%/translations/xx.qm
PLIST_DIRS=	%%DATADIR%%/translations \
		%%DATADIR%%/lib \
		%%DATADIR%% \
		lib/qvamps

FILES_FIX_2K_SECTOR_SIZE=	\
		TitleListItems.pm \
		VTSListItems.pm \
		mainwindow.ui.pm

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|puic|${LOCALBASE}/bin/puic|' \
		-e 's|swig|${LOCALBASE}/bin/swig1.3|' \
		-e 's|\$$\(PREFIX\)/share/qvamps|%%DATADIR%%|' \
		-e 's|[[:space:]]perl[[:space:]]| ${PERL} |' \
		${BUILD_WRKSRC}/${MAKEFILE}
.for file in fakelupd.pl qvamps
	@${REINPLACE_CMD} -E \
		-e 's|/usr/bin/perl|${PERL}|' \
		${WRKSRC}/${file}
.endfor
# PREFIX,DATADIR safeness
.for file in QVamps.pm mainwindow.ui qvamps
	@${REINPLACE_CMD} -E \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/${file}
.endfor
# use 2 Kbytes sector size instead of 512 bytes
.for file in ${FILES_FIX_2K_SECTOR_SIZE}
	@${REINPLACE_CMD} -E \
		-e 's|512\.|2048\.|' \
		${WRKSRC}/${file}
.endfor

do-install:
# application
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
# shared multimedia files
.for extension in jpg mpa mpg
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/*.${extension} ${DATADIR}
.endfor
# shared perl modules
	@${MKDIR} ${DATADIR}/lib
	@${INSTALL_DATA} ${WRKSRC}/*pm ${DATADIR}/lib
# shared library
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/LibDvdRead.so ${PREFIX}/lib/${PORTNAME}
# translations
	@${MKDIR} ${DATADIR}/translations
	@${INSTALL_DATA} ${WRKSRC}/xx.qm ${DATADIR}/translations

.include <bsd.port.pre.mk>

.if defined(STRIP) && ${STRIP} != ""
MAKE_ENV+=	STRIP="${STRIP_CMD}"
.else
MAKE_ENV+=	STRIP="${TRUE}"
.endif

.ifdef(WITH_MPLAYER)
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.include <bsd.port.post.mk>
