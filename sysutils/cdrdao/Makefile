# Created by: futatuki

PORTNAME=	cdrdao
PORTVERSION=	1.2.4
PORTREVISION=	4
CATEGORIES=	sysutils audio
MASTER_SITES=	SF/cdrdao
DISTNAME=	cdrdao-${PORTVERSION}

MAINTAINER=	marius@FreeBSD.org
COMMENT?=	Record CD-R[W]s in disk-at-once mode

LICENSE=	GPLv2

USES=		alias compiler:c++11-lang gmake tar:bzip2
GNU_CONFIGURE=	yes
USE_CXXSTD=	c++11

OPTIONS_DEFINE=		DOCS TOC2MP3 MP3OGG
OPTIONS_DEFAULT=	MP3OGG
MP3OGG_DESC=		Build with MP3/Ogg support (for sysutils/gcdmaster)
TOC2MP3_DESC=		Build with toc2mp3 (requires audio/lame)

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--with-gcdmaster=no
.if ${PORT_OPTIONS:MTOC2MP3}
LIB_DEPENDS+=		libmp3lame.so:audio/lame
CONFIGURE_ARGS+=	--disable-lame-test \
			--with-lame-include=${LOCALBASE}/include \
			--with-lame-lib=${LOCALBASE}/lib
PLIST_SUB+=		TOC2MP3=""
.else
CONFIGURE_ARGS+=	--with-lame=no
PLIST_SUB+=		TOC2MP3="@comment "
.endif
.if ${PORT_OPTIONS:MMP3OGG}
USES+=			pkgconfig
LIB_DEPENDS+=		libao.so:audio/libao \
			libmad.so:audio/libmad \
			libvorbis.so:audio/libvorbis
CONFIGURE_ENV+=		AO_CFLAGS=-I${LOCALBASE}/include \
			AO_LIBS="-L${LOCALBASE}/lib -lao" \
			MAD_CFLAGS=-I${LOCALBASE}/include \
			MAD_LIBS="-L${LOCALBASE}/lib -lmad" \
			VORBISFILE_CFLAGS=-I${LOCALBASE}/include \
			VORBISFILE_LIBS="-L${LOCALBASE}/lib -lvorbisfile"
.else
CONFIGURE_ARGS+=	--with-mp3-support=no --with-ogg-support=no
.endif

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--without-pcctsbin --without-pcctsinc \
			--with-posix-threads=no --with-scglib
MAKE_ENV+=		CCOM=cc
SCSILIBXARCH!=		${UNAME} -m

post-extract:
	@(cd ${WRKSRC}/scsilib/RULES && ${CP} -p os-freebsd.id os-dragonfly.id)
.if ${SCSILIBXARCH} != "i386"
	@${LN} -sf ${WRKSRC}/scsilib/RULES/i386-freebsd-cc.rul \
		${WRKSRC}/scsilib/RULES/${SCSILIBXARCH}-${OPSYS:tl}-cc.rul
.endif

post-patch:
.for i in 45libdeflt 45libedc 45libfile 45libhfs_iso 45libparanoia 45libunls \
	45librscg 55cdda2wav 55cdrecord 55cmd 55mkisofs 55mkisofs!@!diag \
	55readcd 55scgcheck 55scgskeleton 55rscsi 85man
	@${RM} ${WRKSRC}/scsilib/TARGETS/${i}
.endfor
.for i in cdrdao.man main.cc
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/dao/${i}
.endfor
	@${REINPLACE_CMD} -E -e 's|(^CDRDAO_DATA_DIR.+=).+|\1 ${DATADIR}|' \
		${WRKSRC}/dao/Makefile.in
.for i in toc2cddb.1 toc2cue.1
	@${REINPLACE_CMD} -e 's|1\.2\.2|${PORTVERSION}|g' ${WRKSRC}/utils/${i}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dao/cdrdao ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dao/cdrdao.man \
		${STAGEDIR}${PREFIX}/man/man1/cdrdao.1
	${INSTALL_PROGRAM} ${WRKSRC}/utils/cue2toc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/utils/cue2toc.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/utils/toc2cddb ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/utils/toc2cddb.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/utils/toc2cue ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/utils/toc2cue.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dao/cdrdao.drivers \
		${STAGEDIR}${DATADIR}/drivers

do-install-TOC2MP3-on:
	${INSTALL_PROGRAM} ${WRKSRC}/utils/toc2mp3 ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in CREDITS ChangeLog README README.PlexDAE
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
