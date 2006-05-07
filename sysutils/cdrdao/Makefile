# New ports collection makefile for:    cdrdao
# Date created:         7 April 1999
# Whom:                 futatuki
#
# $FreeBSD$
#

PORTNAME?=	cdrdao
PORTVERSION=	1.2.1
PORTREVISION?=	0
CATEGORIES=	sysutils audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	cdrdao
DISTNAME=	cdrdao-${PORTVERSION}

MAINTAINER=	marius@FreeBSD.org
COMMENT?=	Record CD-R[W]s in disk-at-once mode

BUILD_DEPENDS=	${LOCALBASE}/bin/antlr:${PORTSDIR}/devel/pccts \
		${LOCALBASE}/bin/dlg:${PORTSDIR}/devel/pccts

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MP3OGG_LIB_DEPENDS=	ao.3:${PORTSDIR}/audio/libao \
			mad.2:${PORTSDIR}/audio/libmad \
			vorbis.3:${PORTSDIR}/audio/libvorbis

.if ${PORTNAME} == "gcdmaster"
USE_GCC=		3.4
USE_GNOME=		gnomehier pkgconfig
LIB_DEPENDS=		${MP3OGG_LIB_DEPENDS} \
			gnomeuimm-2.6.1:${PORTSDIR}/x11-toolkits/libgnomeuimm26
RUN_DEPENDS=		${LOCALBASE}/bin/cdrdao:${PORTSDIR}/sysutils/cdrdao \
			${LOCALBASE}/share/mime/packages/freedesktop.org.xml:${PORTSDIR}/misc/shared-mime-info
MAN1=			gcdmaster.1
CONFIGURE_ARGS=		--without-lame
.else
MAN1=			cdrdao.1 cue2toc.1
CONFIGURE_ARGS=		--without-xdao
.if defined(WITH_TOC2MP3)
LIB_DEPENDS=		mp3lame.0:${PORTSDIR}/audio/lame
CONFIGURE_ARGS+=	--with-lame-include=${LOCALBASE}/include \
			--with-lame-lib=${LOCALBASE}/lib
PLIST_SUB+=		TOC2MP3=""
.else
CONFIGURE_ARGS+=	--without-lame
PLIST_SUB+=		TOC2MP3="@comment "
.endif
.if !defined(WITHOUT_MP3OGG)
USE_GNOME=		pkgconfig
LIB_DEPENDS+=		${MP3OGG_LIB_DEPENDS}
.else
CONFIGURE_ARGS+=	--without-mp3-support --without-ogg-support
.endif
.endif

CONFIGURE_ARGS+=	--with-pcctsbin=${LOCALBASE}/bin \
			--with-pcctsinc=${LOCALBASE}/include/pccts \
			--without-posix-threads --with-scglib=pkg
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.pre.mk>

CCOM!=		${BASENAME} ${CC}
MAKE_ENV=	CCOM=${CCOM} LANG=C
SCSILIBTARGET=	${ARCH}-freebsd-${CCOM}

pre-everything::
.if ${PORTNAME} != "gcdmaster" && \
	(!defined(WITH_TOC2MP3) || !defined(WITHOUT_MP3OGG))
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build option(s):"
	@${ECHO_MSG} ""
.if !defined(WITH_TOC2MP3)
	@${ECHO_MSG} "WITH_TOC2MP3=yes	builds with toc2mp3 (requires audio/lame)"
.endif
.if !defined(WITHOUT_MP3OGG)
	@${ECHO_MSG} "WITHOUT_MP3OGG=yes	builds without support for decoding MP3 and Ogg Vorbis"
	@${ECHO_MSG} "			files (not required unless using sysutils/gcdmaster;"
	@${ECHO_MSG} "			disabling saves a couple of dependencies)"
.endif
	@${ECHO_MSG} ""
.endif

post-extract:
.if ${SCSILIBTARGET} != "i386-freebsd-cc"
	@${LN} -sf ${WRKSRC}/scsilib/RULES/i386-freebsd-cc.rul \
		${WRKSRC}/scsilib/RULES/${SCSILIBTARGET}.rul
.endif

post-patch:
.for i in 45libdeflt 45libedc 45libfile 45libhfs_iso 45libparanoia 45libunls \
	45librscg 55cdda2wav 55cdrecord 55cmd 55mkisofs 55mkisofs!@!diag \
	55readcd 55scgcheck 55scgskeleton 55rscsi 85man
	@${RM} ${WRKSRC}/scsilib/TARGETS/${i}
.endfor
.if ${PORTNAME} == "gcdmaster"
	@${REINPLACE_CMD} -E -e 's|(^SUBDIRS.+) utils|\1|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -E -e 's|(^gladedir.+=).+|\1 ${DATADIR}|' \
		${WRKSRC}/xdao/Makefile.in
	@${REINPLACE_CMD} -E -e \
		's|(SET_CDRDAO_PATH.+path=)(cdrdao)|\1${LOCALBASE}\/bin\/\2|g' \
		${WRKSRC}/xdao/Settings.cc
	@${REINPLACE_CMD} -E -e \
		's|(icon-filename=).+(gcdmaster-doc.png)|\1${X11BASE}\/share\/gnome\/pixmaps\/document-icons\/\2|g' \
		${WRKSRC}/xdao/gcdmaster.keys
.else
.for i in cdrdao.man main.cc
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/dao/${i}
.endfor
	@${REINPLACE_CMD} -E -e 's|(^CDRDAO_DATA_DIR.+=).+|\1 ${DATADIR}|' \
		${WRKSRC}/dao/Makefile.in
.endif

do-install:
.if ${PORTNAME} == "gcdmaster"
	@${INSTALL_PROGRAM} ${WRKSRC}/xdao/gcdmaster ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/xdao/gcdmaster.man \
		${PREFIX}/man/man1/gcdmaster.1
	@${INSTALL_DATA} ${WRKSRC}/xdao/gcdmaster-doc.png \
		${X11BASE}/share/gnome/pixmaps/document-icons
	@${INSTALL_DATA} ${WRKSRC}/xdao/gcdmaster.applications \
		${X11BASE}/share/gnome/application-registry
	@${INSTALL_DATA} ${WRKSRC}/xdao/gcdmaster.desktop \
		${X11BASE}/share/gnome/applications
	@${INSTALL_DATA} ${WRKSRC}/xdao/gcdmaster.keys \
		${X11BASE}/share/gnome/mime-info
	@${INSTALL_DATA} ${WRKSRC}/xdao/gcdmaster.mime \
		${X11BASE}/share/gnome/mime-info
	@${INSTALL_DATA} ${WRKSRC}/xdao/gcdmaster.png \
		${X11BASE}/share/gnome/pixmaps
	@${INSTALL_DATA} ${WRKSRC}/xdao/gcdmaster.xml \
		${X11BASE}/share/mime/packages
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/xdao/glade/ProjectChooser.glade ${DATADIR}
.else
	@${INSTALL_PROGRAM} ${WRKSRC}/dao/cdrdao ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/dao/cdrdao.man ${PREFIX}/man/man1/cdrdao.1
	@${INSTALL_PROGRAM} ${WRKSRC}/utils/cue2toc ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/utils/cue2toc.1 ${PREFIX}/man/man1
	@${INSTALL_PROGRAM} ${WRKSRC}/utils/toc2cddb ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/utils/toc2cue ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/dao/cdrdao.drivers ${DATADIR}/drivers
.if defined(WITH_TOC2MP3)
	@${INSTALL_PROGRAM} ${WRKSRC}/utils/toc2mp3 ${PREFIX}/bin
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in CREDITS ChangeLog README README.PlexDAE
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
.endif

.include <bsd.port.post.mk>
