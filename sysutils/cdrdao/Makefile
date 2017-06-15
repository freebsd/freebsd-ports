# Created by: futatuki
# $FreeBSD$

PORTNAME?=	cdrdao
PORTVERSION=	1.2.3
PORTREVISION?=	5
CATEGORIES=	sysutils audio
MASTER_SITES=	SF/cdrdao/cdrdao/${PORTVERSION}
DISTNAME=	cdrdao-${PORTVERSION}

MAINTAINER=	marius@FreeBSD.org
COMMENT?=	Record CD-R[W]s in disk-at-once mode

LICENSE=	GPLv2

USES=		alias gmake tar:bzip2
GNU_CONFIGURE=	yes

MP3OGG_LIB_DEPENDS=	libao.so:audio/libao \
			libmad.so:audio/libmad \
			libvorbis.so:audio/libvorbis

.if ${PORTNAME} == "cdrdao"
OPTIONS_DEFINE=		DOCS TOC2MP3 MP3OGG

OPTIONS_DEFAULT=	MP3OGG
MP3OGG_DESC=		Build with MP3/Ogg support (for sysutils/gcdmaster)
TOC2MP3_DESC=		Build with toc2mp3 (requires audio/lame)

.include <bsd.port.options.mk>
.endif

.if ${PORTNAME} == "gcdmaster"
USES+=			pkgconfig shared-mime-info
WANT_GNOME=		yes
GCONF_SCHEMAS=		gcdmaster.schemas
LIB_DEPENDS+=		${MP3OGG_LIB_DEPENDS} \
			libgnomeuimm-2.6.so:x11-toolkits/libgnomeuimm26
RUN_DEPENDS+=		${LOCALBASE}/bin/cdrdao:sysutils/cdrdao \
			${LOCALBASE}/share/mime/packages/freedesktop.org.xml:misc/shared-mime-info
CONFIGURE_ARGS+=	--with-lame=no
.else
CONFIGURE_ARGS+=	--with-xdao=no
.if ${PORT_OPTIONS:MTOC2MP3}
LIB_DEPENDS+=		libmp3lame.so:audio/lame
CONFIGURE_ARGS+=	--with-lame-include=${LOCALBASE}/include \
			--with-lame-lib=${LOCALBASE}/lib
PLIST_SUB+=		TOC2MP3=""
.else
CONFIGURE_ARGS+=	--with-lame=no
PLIST_SUB+=		TOC2MP3="@comment "
.endif
.if ${PORT_OPTIONS:MMP3OGG}
USES+=			pkgconfig
LIB_DEPENDS+=		${MP3OGG_LIB_DEPENDS}
CONFIGURE_ENV+=		AO_CFLAGS=-I${LOCALBASE}/include \
			AO_LIBS="-L${LOCALBASE}/lib -lao" \
			MAD_CFLAGS=-I${LOCALBASE}/include \
			MAD_LIBS="-L${LOCALBASE}/lib -lmad" \
			VORBISFILE_CFLAGS=-I${LOCALBASE}/include \
			VORBISFILE_LIBS="-L${LOCALBASE}/lib -lvorbisfile"
.else
CONFIGURE_ARGS+=	--with-mp3-support=no --with-ogg-support=no
.endif
.endif

CONFIGURE_ARGS+=	--without-pcctsbin --without-pcctsinc \
			--with-posix-threads=no --with-scglib
MAKE_ENV=		CCOM=cc
SCSILIBTARGET=		${ARCH:S/powerpc64/powerpc/}-freebsd-cc

BROKEN_aarch64=		Fails to install: gmake: p: Command not found
BROKEN_armv6=		Fails to install: gmake: p: Command not found
BROKEN_mips=		Fails to install: gmake: p: Command not found
BROKEN_mips64=		Fails to install: gmake: p: Command not found

.include <bsd.port.pre.mk>

post-extract:
	@(cd ${WRKSRC}/scsilib/RULES && ${CP} os-freebsd.id os-dragonfly.id)
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
.for i in include/schily.h libschily/fexec.c
	@${REINPLACE_CMD} -e 's|fexecve|js_fexecve|g' ${WRKSRC}/scsilib/${i}
.endfor
	@${REINPLACE_CMD} -e 's|int	getline|int	get_line|g' ${WRKSRC}/scsilib/include/schily.h
	@${REINPLACE_CMD} -e 's|(getline|(get_line|g' ${WRKSRC}/scsilib/libscg/scsitransp.c
	@${REINPLACE_CMD} -e 's|^getline|get_line|g' ${WRKSRC}/scsilib/libschily/stdio/fgetline.c
.if ${PORTNAME} == "gcdmaster"
	@${REINPLACE_CMD} -E -e 's|(^SUBDIRS.+) utils|\1|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -E -e 's|(^gladedir.+=).+|\1 ${DATADIR}|' \
		${WRKSRC}/xdao/Makefile.in
	@${REINPLACE_CMD} -E -e \
		's|(SET_CDRDAO_PATH.+path=)(cdrdao)|\1${LOCALBASE}\/bin\/\2|g' \
		${WRKSRC}/xdao/Settings.cc
	@${REINPLACE_CMD} -E -e \
		's|(icon-filename=).+(gcdmaster-doc.png)|\1${LOCALBASE}\/share\/pixmaps\/document-icons\/\2|g' \
		${WRKSRC}/xdao/gcdmaster.keys
	@${REINPLACE_CMD} -e 's|connect(SigC::slot|connect(sigc::ptr_fun|g' \
		${WRKSRC}/xdao/xcdrdao.cc
.else
.for i in cdrdao.man main.cc
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/dao/${i}
.endfor
	@${REINPLACE_CMD} -E -e 's|(^CDRDAO_DATA_DIR.+=).+|\1 ${DATADIR}|' \
		${WRKSRC}/dao/Makefile.in
.for i in toc2cddb.1 toc2cue.1
	@${REINPLACE_CMD} -e 's|1\.2\.2|${PORTVERSION}|g' ${WRKSRC}/utils/${i}
.endfor
.endif

do-install:
.if ${PORTNAME} == "gcdmaster"
	@${INSTALL_PROGRAM} ${WRKSRC}/xdao/gcdmaster ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/xdao/gcdmaster.man \
		${STAGEDIR}${PREFIX}/man/man1/gcdmaster.1
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/share/pixmaps/document-icons
	@${INSTALL_DATA} ${WRKSRC}/xdao/gcdmaster-doc.png \
		${STAGEDIR}${LOCALBASE}/share/pixmaps/document-icons
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/share/application-registry
	@${INSTALL_DATA} ${WRKSRC}/xdao/gcdmaster.applications \
		${STAGEDIR}${LOCALBASE}/share/application-registry
	@${INSTALL_DATA} ${WRKSRC}/xdao/gcdmaster.desktop \
		${STAGEDIR}${LOCALBASE}/share/applications
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/share/mime-info
	@${INSTALL_DATA} ${WRKSRC}/xdao/gcdmaster.keys \
		${STAGEDIR}${LOCALBASE}/share/mime-info
	@${INSTALL_DATA} ${WRKSRC}/xdao/gcdmaster.mime \
		${STAGEDIR}${LOCALBASE}/share/mime-info
	@${INSTALL_DATA} ${WRKSRC}/xdao/gcdmaster.png \
		${STAGEDIR}${LOCALBASE}/share/pixmaps
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/etc/gconf/schemas
	@${INSTALL_DATA} ${WRKSRC}/xdao/gcdmaster.schemas \
		${STAGEDIR}${LOCALBASE}/etc/gconf/schemas
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/share/mime/packages
	@${INSTALL_DATA} ${WRKSRC}/xdao/gcdmaster.xml \
		${STAGEDIR}${LOCALBASE}/share/mime/packages
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/xdao/glade/Preferences.glade \
		${STAGEDIR}${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/xdao/glade/ProjectChooser.glade \
		${STAGEDIR}${DATADIR}
.else
	@${INSTALL_PROGRAM} ${WRKSRC}/dao/cdrdao ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/dao/cdrdao.man \
		${STAGEDIR}${PREFIX}/man/man1/cdrdao.1
	@${INSTALL_PROGRAM} ${WRKSRC}/utils/cue2toc ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/utils/cue2toc.1 ${STAGEDIR}${PREFIX}/man/man1
	@${INSTALL_PROGRAM} ${WRKSRC}/utils/toc2cddb ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/utils/toc2cddb.1 ${STAGEDIR}${PREFIX}/man/man1
	@${INSTALL_PROGRAM} ${WRKSRC}/utils/toc2cue ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/utils/toc2cue.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/dao/cdrdao.drivers \
		${STAGEDIR}${DATADIR}/drivers
.if ${PORT_OPTIONS:MTOC2MP3}
	@${INSTALL_PROGRAM} ${WRKSRC}/utils/toc2mp3 ${STAGEDIR}${PREFIX}/bin
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in CREDITS ChangeLog README README.PlexDAE
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
