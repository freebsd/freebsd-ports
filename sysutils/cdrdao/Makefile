# New ports collection makefile for:    cdrdao
# Date created:         7 April 1999
# Whom:                 futatuki
#
# $FreeBSD$
#

PORTNAME=	cdrdao
PORTVERSION=	1.1.7
PORTREVISION=	5
CATEGORIES=	sysutils audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	marius@alchemy.franken.de
COMMENT=	Record CD-R[W]s in disk-at-once mode

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
#WANT_GNOME=	yes

MAN1=		cdrdao.1

MAKE_ENV=	CCOM=${CC} COPTX="-DBSD_SCSI_SENSE_BUG"

.include <bsd.port.pre.mk>

.if defined(WITH_TOC2MP3)
LIB_DEPENDS=		mp3lame.0:${PORTSDIR}/audio/lame
.endif

#.if ${HAVE_GNOME:Mgnomelibs} != ""
#USE_GNOME=		gnomelibs
#LIB_DEPENDS+=		gtkmm.2:${PORTSDIR}/x11-toolkits/gtk--
#LIB_DEPENDS+=		gnomemm-1.2.10:${PORTSDIR}/x11-toolkits/gnome--
#CONFIGURE_ARGS=		--with-gtkmm-prefix=${X11BASE}
#PKGNAMESUFFIX?=		-gnome
#PLIST_SUB=		GNOME=""
#MAN1+=			gcdmaster.1
#.else
CONFIGURE_ARGS=		--with-gtkmm-prefix=${NONEXISTENT}
PLIST_SUB=		GNOME="@comment "
_WITHOUT_GNOME=		yes
#.endif

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.if exists(${LOCALBASE}/bin/antlr) && exists(${LOCALBASE}/bin/dlg)
CONFIGURE_ARGS+=	--with-pcctsbin=${LOCALBASE}/bin \
			--with-pcctsinc=${LOCALBASE}/include/pccts
.endif

.if defined(WITHOUT_SCGLIB) && ${OSVERSION} > 300000
CONFIGURE_ARGS+=	--without-scglib
.endif

.if ${OSVERSION} <= 320000 || !defined(WITH_PTHREADS)
CONFIGURE_ARGS+=	--without-posix-threads
.endif

.if defined(WITH_TOC2MP3)
CONFIGURE_ARGS+=	--with-lame-include=${LOCALBASE}/include \
			--with-lame-lib=${LOCALBASE}/lib
PLIST_SUB+=		TOC2MP3=""
.else
CONFIGURE_ARGS+=	--without-lame
PLIST_SUB+=		TOC2MP3="@comment "
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITHOUT_SCGLIB=yes	builds without Joerg Schilling's SCSI library"
	@${ECHO_MSG} "WITH_PTHREADS=yes	enables usage of POSIX threads for the ring buffers"
	@${ECHO_MSG} "			(not recommended, increases risk of buffer-underruns)"
	@${ECHO_MSG} "WITH_TOC2MP3=yes	builds toc2mp3 (requires audio/lame)"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "This port builds the gcdmaster frontend if x11/gnomelibs is installed (also"
	@${ECHO_MSG} "requires x11-toolkits/gtk-- and x11-toolkits/gnome--)."
	@${ECHO_MSG} ""

post-extract:
.if ${MACHINE_ARCH} != "i386" || ${CC} != "cc"
	@(cd ${WRKSRC}/scsilib/RULES; \
	  ${LN} -sf i386-freebsd-cc.rul ${MACHINE_ARCH}-freebsd-${CC}.rul)
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|g; \
		s|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
.for i in cdrdao.man main.cc
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/dao/${i}
.endfor

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/dao/cdrdao ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/dao/cdrdao.man ${PREFIX}/man/man1/cdrdao.1
	@${INSTALL_PROGRAM} ${WRKSRC}/utils/toc2cue ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/dao/cdrdao.drivers ${DATADIR}/drivers
.if defined(WITH_TOC2MP3)
	@${INSTALL_PROGRAM} ${WRKSRC}/utils/toc2mp3 ${PREFIX}/bin
.endif
.if !defined(_WITHOUT_GNOME)
	@${INSTALL_PROGRAM} ${WRKSRC}/xdao/gcdmaster ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/xdao/xcdrdao.man \
		${PREFIX}/man/man1/gcdmaster.1
	@${INSTALL_DATA} ${WRKSRC}/xdao/gcdmaster.desktop \
		${X11BASE}/share/gnome/apps/Applications
	@${MKDIR} ${X11BASE}/share/gnome/pixmaps/gcdmaster
.for i in gcdmaster.png pixmap_audiocd.png pixmap_copycd.png \
	pixmap_cursor-tool.xpm pixmap_datacd.png pixmap_dumpcd.png \
	pixmap_help.png pixmap_mixedcd.png pixmap_open.png \
	pixmap_play-pause.xpm pixmap_play-start.xpm pixmap_play-stop.xpm \
	pixmap_zoom-fit.xpm pixmap_zoom-in.xpm pixmap_zoom-out.xpm \
	pixmap_zoom-selection.xpm pixmap_zoom-tool.xpm
	@${INSTALL_DATA} ${WRKSRC}/xdao/${i} \
		${X11BASE}/share/gnome/pixmaps/gcdmaster
.endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in CREDITS INSTALL README README.PlexDAE \
	Release-1.1.0 Release-1.1.2 Release-1.1.3 Release-1.1.4 \
	Release-1.1.5 Release-1.1.6 Release-1.1.7
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
