# New ports collection makefile for:    cdrdao
# Date created:         7 April 1999
# Whom:                 futatuki
#
# $FreeBSD$
#

PORTNAME?=	cdrdao
PORTVERSION=	1.1.8
PORTREVISION?=	1
CATEGORIES=	sysutils audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cdrdao
DISTNAME=	cdrdao-${PORTVERSION}

MAINTAINER=	marius@alchemy.franken.de
COMMENT?=	Record CD-R[W]s in disk-at-once mode

BUILD_DEPENDS=	${LOCALBASE}/bin/antlr:${PORTSDIR}/devel/pccts \
		${LOCALBASE}/bin/dlg:${PORTSDIR}/devel/pccts

USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

.if ${PORTNAME} == "gcdmaster"
USE_GNOME=		gnomelibs pkgconfig
LIB_DEPENDS=		gnomeuimm-2.0:${PORTSDIR}/x11-toolkits/libgnomeuimm
RUN_DEPENDS=		${LOCALBASE}/bin/cdrdao:${PORTSDIR}/sysutils/cdrdao
MAN1=			gcdmaster.1
CONFIGURE_ARGS=		--without-lame
.else
MAN1=			cdrdao.1 cue2toc.1
CONFIGURE_ARGS=		--without-xdao
PLIST_SUB=		PORTVERSION=${PORTVERSION}
.if defined(WITH_TOC2MP3)
LIB_DEPENDS=		mp3lame.0:${PORTSDIR}/audio/lame
CONFIGURE_ARGS+=	--with-lame-include=${LOCALBASE}/include \
			--with-lame-lib=${LOCALBASE}/lib
PLIST_SUB+=		TOC2MP3=""
.else
CONFIGURE_ARGS+=	--without-lame
PLIST_SUB+=		TOC2MP3="@comment "
.endif
.endif

CONFIGURE_ARGS+=	--with-pcctsbin=${LOCALBASE}/bin \
			--with-pcctsinc=${LOCALBASE}/include/pccts \
			--without-posix-threads
#CONFIGURE_ARGS+=	--without-scglib
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
MAKE_ENV=		CCOM=${CC}

pre-everything::
.if ${PORTNAME} != "gcdmaster" && !defined(WITH_TOC2MP3)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build option(s):"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_TOC2MP3=yes	builds toc2mp3 (requires audio/lame)"
	@${ECHO_MSG} ""
.endif

post-extract:
.if ${MACHINE_ARCH} != "i386" || ${CC} != "cc"
	@${LN} -sf ${WRKSRC}/scsilib/RULES/i386-freebsd-cc.rul \
		${WRKSRC}/scsilib/RULES/${MACHINE_ARCH}-freebsd-${CC}.rul
.endif

post-patch:
.for i in 45libdeflt 45librscg 55rscsi
	@${RM} ${WRKSRC}/scsilib/TARGETS/${i}
.endfor
.if ${PORTNAME} == "gcdmaster"
	@${REINPLACE_CMD} -E -e 's|(^SUBDIRS.+) utils|\1|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -E -e \
		's|(SET_CDRDAO_PATH.+path=)(cdrdao)|\1${LOCALBASE}\/bin\/\2|g' \
		${WRKSRC}/xdao/Settings.cc
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
	@${INSTALL_DATA} ${WRKSRC}/xdao/gcdmaster.desktop \
		${X11BASE}/share/gnome/apps/Applications
	@${INSTALL_DATA} ${WRKSRC}/xdao/gcdmaster.png \
		${X11BASE}/share/gnome/pixmaps
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
.for i in CREDITS README README.PlexDAE Release-${PORTVERSION}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
.endif

.include <bsd.port.mk>
