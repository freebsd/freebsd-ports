# Created by: Espen Skoglund <esk@ira.uka.de>
# $FreeBSD$

PORTNAME=	xmms
PORTVERSION=	1.2.11
PORTREVISION?=	20	# Also chinese/xmms and russian/xmms
CATEGORIES+=	multimedia audio ipv6
MASTER_SITES=	http://www.xmms.org/files/1.2.x/ \
		http://legacy.xmms2.org/ \
		LOCAL/beech
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	X Multimedia System -- An audio player with Winamp GUI

LICENSE=	GPLv2

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
FORBIDDEN=	Vulnerable: CVE-2007-0653 CVE-2007-0654
EXPIRATION_DATE=	2014-05-01

CONFLICTS?=	ru-xmms-[0-9]* zh-xmms-[0-9]*
GNU_CONFIGURE=	yes
USES=		desktop-file-utils pathfix gmake iconv
USE_BZIP2=	yes
USE_GNOME=	gtk12
USE_LDCONFIG=	yes
USE_XORG=	sm x11 xxf86vm

CONFIGURE_ARGS=	xmms_cv_newpcm_driver=yes --disable-static
CONFIGURE_ENV=	INPUT_PLUGINS="${INPUT_PLUGINS}" \
		OUTPUT_PLUGINS="${OUTPUT_PLUGINS}" \
		VISUALIZATION_PLUGINS="${VISUALIZATION_PLUGINS}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INPUT_PLUGINS=	cdaudio mpg123 tonegen wav
OUTPUT_PLUGINS=	OSS disk_writer
VISUALIZATION_PLUGINS=	blur_scope sanalyzer

OPTIONS_DEFINE=	IPV6 MIKMOD NLS SPEC VFILEINFO VORBIS RUSXMMS_PATCHES
OPTIONS_DEFAULT=MIKMOD VORBIS
OPTIONS_DEFINE_i386=	SIMD
OPTIONS_DEFAULT_i386=	SIMD
OPTIONS_SUB=	yes

IPV6_CONFIGURE_ENABLE=	ipv6

MIKMOD_CONFIGURE_ENABLE=mikmod
MIKMOD_LIB_DEPENDS=	libmikmod.so:${PORTSDIR}/audio/libmikmod

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

SIMD_CONFIGURE_ENABLE=	simd

SPEC_DESC=		Visualization opengl_spectrum
SPEC_CONFIGURE_ENABLE=	opengl
SPEC_USE=		GL=gl

VFILEINFO_DESC=		Enable Extended Vorbis Fileinfo
VFILEINFO_CPPFLAGS=	-DALL_VORBIS_TAGS

VORBIS_CONFIGURE_ENABLE=vorbis
VORBIS_LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis

RUSXMMS_PATCHES_DESC=	Patches to handle broken non-Unicode ID3 tags

.if !defined(WITH_DEBUG)
INSTALL_TARGET=	install-strip
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRUSXMMS_PATCHES}
ENC_PATCHLEVEL=	41
DISTFILES+=	RusXMMS2-csa${ENC_PATCHLEVEL}${EXTRACT_SUFX}:enc
MASTER_SITES+=	SF/rusxmms/rusxmms2/csa41%20%28${PORTVERSION}%29:enc
MASTER_SITE_SUBDIR+=	rusxmms/:enc

LIB_DEPENDS+=	librcc.so:${PORTSDIR}/devel/librcc \
		librcd.so:${PORTSDIR}/devel/librcd

USE_AUTOTOOLS=	aclocal autoheader libtoolize autoconf automake
LIBTOOLIZE_ARGS=--install --force
AUTOMAKE_ARGS=	--add-missing --force-missing
USE_OPENSSL=	yes
.endif

.if ${PORT_OPTIONS:MMIKMOD}
INPUT_PLUGINS+=	mikmod
.endif

.if ${PORT_OPTIONS:MVORBIS}
INPUT_PLUGINS+=	vorbis
.endif

.if ${PORT_OPTIONS:MSPEC}
VISUALIZATION_PLUGINS+=	opengl_spectrum
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
OUTPUT_PLUGINS+=	esd
PLIST_SUB+=	ESDPLUGIN:=""
.else
CONFIGURE_ARGS+=	--disable-esd
PLIST_SUB+=	ESDPLUGIN:="@comment "
.endif

pre-everything::
.if ${HAVE_GNOME:Mesound}!=""
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can disable support for esound by defining"
	@${ECHO_MSG} "WITHOUT_GNOME=esound."
	@${ECHO_MSG} ""
.endif

post-patch:
.if ${PORT_OPTIONS:MRUSXMMS_PATCHES}
	@${REINPLACE_CMD} -e 's/AM_PATH_ALSA.*/have_alsa=no/' \
		${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e '/libtool/,$$d' \
		${WRKSRC}/acinclude.m4 ${WRKSRC}/libxmms/acinclude.m4
	@${CP} ${WRKDIR}/RusXMMS2/source/* ${WRKSRC}/libxmms/
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
# If there is no esound installed, the autotools won't find a required macro
.if ${HAVE_GNOME:Mesound}==""
	@${REINPLACE_CMD} -e '/AM_PATH_ESD/,/have_esd=no/d' \
		${WRKSRC}/configure.in
.endif
.endif
	@${REINPLACE_CMD} -e 's/alsa_found=yes/alsa_found=no/' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,@mkdir_p@,${MKDIR},' \
		${WRKSRC}/po/Makefile.in.in
	@${FIND} ${WRKSRC} -name '*.s' | ${XARGS} ${REINPLACE_CMD} \
		-e 's,/.*,,' -e 's/fist /fists /' -e 's/fistp /fistps /' \
		-e '$$s/$$/\${.newline} .section ".note.GNU-stack","",@progbits/'

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xmms/Skins
	${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${FILESDIR}/xmms.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.post.mk>
