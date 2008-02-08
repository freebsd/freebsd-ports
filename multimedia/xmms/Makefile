# New ports collection makefile for:	xmms
# Date created:			3 July 1999
# Whom:				Espen Skoglund <esk@ira.uka.de>
#
# $FreeBSD$
#

PORTNAME=	xmms
PORTVERSION=	1.2.11
PORTREVISION=	2
CATEGORIES+=	multimedia audio ipv6
MASTER_SITES=	http://www.xmms.org/files/1.2.x/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER?=	beech@FreeBSD.org
COMMENT?=	X Multimedia System -- An audio player with Winamp GUI

USE_BZIP2=	yes
USE_GL=		gl
USE_GNOME=	gtk12 gnomehack
USE_GMAKE=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:19 automake:19 autoheader:261 autoconf:261 libtool:15
ACLOCAL_ARGS=	--force
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		INPUT_PLUGINS="${INPUT_PLUGINS}" \
		OUTPUT_PLUGINS="${OUTPUT_PLUGINS}" \
		VISUALIZATION_PLUGINS="${VISUALIZATION_PLUGINS}"
MAN1=		wmxmms.1 xmms.1

CONFLICTS=	ru-xmms-*

INPUT_PLUGINS=	cdaudio mpg123 tonegen wav
OUTPUT_PLUGINS=	OSS disk_writer
VISUALIZATION_PLUGINS=	blur_scope sanalyzer opengl_spectrum

PLIST_SUB+=	DATADIR="share"

OPTIONS=	NLS 		"Internationalization" on \
		IPV6		"Enable ipv6" on \
		VFILEINFO	"Enable Extended Vorbis Fileinfo" off \
		VORBIS		"Enable Vorbis Plugin"	on \
		MIKMOD		"Enable Mikemod Plugin" on \
		SIMD		"Enable x86 SIMD (3DNow!/MMX)" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if defined(WITH_RUSXMMS_PATCHES)
ENC_PATCHLEVEL=	41
DISTFILES+=	RusXMMS2-csa${ENC_PATCHLEVEL}${EXTRACT_SUFX}:enc
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:S/$/:enc/}
MASTER_SITE_SUBDIR+=	rusxmms/:enc

LIB_DEPENDS+=	rcc.2:${PORTSDIR}/devel/librcc
LIB_DEPENDS+=	rcd.1:${PORTSDIR}/devel/librcd
.endif

.if defined(WITH_VFILEINFO)
CFLAGS+=	-DALL_VORBIS_TAGS
.endif

.if !defined(WITHOUT_MIKMOD)
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
INPUT_PLUGINS+=	mikmod
PLIST_SUB+=	MIKMODPLUGIN:=""
.else
CONFIGURE_ARGS+=	--disable-mikmod
PLIST_SUB+=	MIKMODPLUGIN:="@comment "
.endif

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
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

.if ${ARCH} != "i386"
WITHOUT_SIMD+=	yes
.endif

.if !defined(WITHOUT_SIMD)
CONFIGURE_ARGS+=	--enable-simd
.endif

.if defined(WITHOUT_SIMD)
post-extract:
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

.if !defined(WITH_RUSXMMS_PATCHES)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can enable support for ID3v2 tags and CP1251"
	@${ECHO_MSG} "encoding by defining WITH_RUSXMMS_PATCHES."
	@${ECHO_MSG} ""
.endif

post-patch:
.if defined(WITH_RUSXMMS_PATCHES)
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

# There are patches to configure.in and Makefile.in, recreate configure
# scripts
run-autotools:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL} \
		${ACLOCAL_ARGS})
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOHEADER} \
		${AUTOHEADER_ARGS})
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOCONF} \
		${AUTOCONF_ARGS})
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOMAKE} \
		${AUTOMAKE_ARGS})
	@(cd ${CONFIGURE_WRKSRC}/libxmms && ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL} \
		${ACLOCAL_ARGS})
	@(cd ${CONFIGURE_WRKSRC}/libxmms && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOHEADER} \
		${AUTOHEADER_ARGS})
	@(cd ${CONFIGURE_WRKSRC}/libxmms && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOCONF} \
		${AUTOCONF_ARGS})
	@(cd ${CONFIGURE_WRKSRC}/libxmms && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOMAKE} \
		${AUTOMAKE_ARGS})

post-install:
	@${MKDIR} ${PREFIX}/share/xmms/Skins
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
