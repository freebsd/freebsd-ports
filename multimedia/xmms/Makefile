# Created by: Espen Skoglund <esk@ira.uka.de>
# $FreeBSD$

PORTNAME=	xmms
PORTVERSION=	1.2.11
PORTREVISION=	18
CATEGORIES+=	multimedia audio ipv6
MASTER_SITES=	http://www.xmms.org/files/1.2.x/ \
		http://legacy.xmms2.org/ \
		LOCAL/beech
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER?=	c.petrik.sosa@gmail.com
COMMENT?=	X Multimedia System -- An audio player with Winamp GUI

USE_BZIP2=	yes
USE_GL=		gl
USE_GNOME=	desktopfileutils gtk12
USE_GMAKE=	yes
USES=		pathfix gettext iconv
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	automake autoconf libtool
AUTOTOOLSFILES=	aclocal.m4
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib" \
		INPUT_PLUGINS="${INPUT_PLUGINS}" \
		OUTPUT_PLUGINS="${OUTPUT_PLUGINS}" \
		VISUALIZATION_PLUGINS="${VISUALIZATION_PLUGINS}"
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--enable-static=no
MAN1=		wmxmms.1 xmms.1
SUB_FILES=	pkg-message xmms.desktop

CONFLICTS=	ru-xmms-[0-9]*

INPUT_PLUGINS=	cdaudio mpg123 tonegen wav
OUTPUT_PLUGINS=	OSS disk_writer
VISUALIZATION_PLUGINS=	blur_scope sanalyzer

OPTIONS_DEFINE=	IPV6 MIKMOD SIMD SPEC VFILEINFO VORBIS RUSXMMS_PATCHES
OPTIONS_DEFAULT=	IPV6 MIKMOD SIMD VORBIS
OPTIONS_EXCLUDE_amd64=	SIMD
SPEC_DESC=	Visualization opengl_spectrum
VFILEINFO_DESC=	Enable Extended Vorbis Fileinfo
RUSXMMS_PATCHES_DESC=	Custom IDv3 patches

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MRUSXMMS_PATCHES}
ENC_PATCHLEVEL=	41
DISTFILES+=	RusXMMS2-csa${ENC_PATCHLEVEL}${EXTRACT_SUFX}:enc
MASTER_SITES+=	SF/rusxmms/rusxmms2/csa41%20%28${PORTVERSION}%29:enc
MASTER_SITE_SUBDIR+=	rusxmms/:enc

LIB_DEPENDS+=	rcc:${PORTSDIR}/devel/librcc
LIB_DEPENDS+=	rcd:${PORTSDIR}/devel/librcd
.endif

.if ${PORT_OPTIONS:MVFILEINFO}
CFLAGS+=	-DALL_VORBIS_TAGS
.endif

.if ${PORT_OPTIONS:MMIKMOD}
LIB_DEPENDS+=	mikmod:${PORTSDIR}/audio/libmikmod
INPUT_PLUGINS+=	mikmod
PLIST_SUB+=	MIKMODPLUGIN:=""
.else
CONFIGURE_ARGS+=	--disable-mikmod
PLIST_SUB+=	MIKMODPLUGIN:="@comment "
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
INPUT_PLUGINS+=	vorbis
PLIST_SUB+=	VORBISPLUGIN:=""
.else
CONFIGURE_ARGS+=	--disable-vorbis
PLIST_SUB+=	VORBISPLUGIN:="@comment "
.endif

.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
OUTPUT_PLUGINS+=	esd
PLIST_SUB+=	ESDPLUGIN:=""
.else
CONFIGURE_ARGS+=	--disable-esd
PLIST_SUB+=	ESDPLUGIN:="@comment "
.endif

.if ${PORT_OPTIONS:MSIMD}
CONFIGURE_ARGS+=	--enable-simd
.else
.if ${ARCH} == "i386"
BROKEN=	must use option SIMD on ${ARCH} see pr ports/63456
.endif
.endif

.if ${PORT_OPTIONS:MSPEC}
PLIST_SUB+=	SPEC=""
VISUALIZATION_PLUGINS+=	opengl_spectrum
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Visualization_Makefile.am
PLIST_SUB+=	SPEC="@comment "
.endif

post-extract:
.if ! ${PORT_OPTIONS:MSIMD}
	(cd ${WRKSRC}/Input/mpg123 && ${MV} decode_i586.s decode_i586.S && \
	  cd ${WRKSRC}/Visualization/blur_scope && ${MV} blur_8.s blur_8.S);
	${REINPLACE_CMD} -e 's:\.s :.S :g' -e 's:\.s$$:.S:g' \
	  -e 's:^\.s\.:.S.:g' ${WRKSRC}/Input/mpg123/Makefile.in
	${REINPLACE_CMD} -e 's:\.s :.S :g' -e 's:\.s$$:.S:g' \
	  -e 's:^\.s\.:.S.:g' ${WRKSRC}/Visualization/blur_scope/Makefile.in
.endif

pre-extract:
.if ${HAVE_GNOME:Mesound}!=""
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can disable support for esound by defining"
	@${ECHO_MSG} "WITHOUT_GNOME=esound."
	@${ECHO_MSG} ""
.endif

.if ! ${PORT_OPTIONS:MRUSXMMS_PATCHES}
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can enable support for ID3v2 tags and CP1251"
	@${ECHO_MSG} "encoding by setting the RUSXMMS_PATCHES option."
	@${ECHO_MSG} ""
.endif

post-patch:
.if ${PORT_OPTIONS:MRUSXMMS_PATCHES}
.  for src in source/rcc.c source/rcc.h source/rcc_langs.h
	@${INSTALL_DATA} ${WRKDIR}/RusXMMS2/${src} ${WRKSRC}/libxmms
.  endfor
	@${CAT} ${WRKDIR}/RusXMMS2/3rdparty/mpg123/*.patch | ${PATCH} -s -p1 -d ${WRKSRC}
.  for diff in xmms-ds-rusxmms.patch xmms-ds-rusxmms-charset.patch \
       xmms-ds-playlist.patch xmms-ds-shade.patch xmms-ds-textbox.patch
	@${PATCH} -s -p1 -d ${WRKSRC} < ${WRKDIR}/RusXMMS2/patches/${diff}
.  endfor
.  for diff in xmms-ds-mpg123.patch xmms-ds-mpg123-editor.patch \
       xmms-ds-mpg123-editor-keys.patch xmms-ds-vorbis-editor.patch \
       xmms-ds-vorbis-editor-keys.patch
	@${PATCH} -s -p1 -d ${WRKSRC} < ${WRKDIR}/RusXMMS2/patches/plugins/${diff}
.  endfor
.endif
# If there is no esound installed, the autotools won't find a required macro
.if ${HAVE_GNOME:Mesound}==""
	${REINPLACE_CMD} -e '/AM_PATH_ESD/,/have_esd=no/d' ${WRKSRC}/configure.in
.endif

post-configure:
	@${FIND} ${WRKSRC} -name Makefile | \
		${XARGS} ${REINPLACE_CMD} -e 's|MKDIR_P|mkdir_p|g'

post-install:
	@${INSTALL} -d ${PREFIX}/share/xmms/Skins
	@${INSTALL} -d ${PREFIX}/share/applications
	@${INSTALL_DATA} ${WRKDIR}/xmms.desktop ${PREFIX}/share/applications/
	-update-desktop-database
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
