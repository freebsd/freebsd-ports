# Created by: Espen Skoglund <esk@ira.uka.de>
# $FreeBSD$

PORTNAME=	xmms
PORTVERSION=	1.2.11
PORTREVISION=	28
CATEGORIES=	multimedia audio ipv6
MASTER_SITES=	http://www.xmms.org/files/1.2.x/ \
		http://legacy.xmms2.org/ \
		LOCAL/beech
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X Multimedia System -- audio player with Winamp GUI

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS?=	ru-xmms-[0-9]* zh-xmms-[0-9]*
GNU_CONFIGURE=	yes
USES=		desktop-file-utils gmake iconv libtool localbase pathfix tar:bzip2
USE_GNOME=	gtk12
USE_LDCONFIG=	yes
USE_XORG=	sm x11 xxf86vm

CONFIGURE_ARGS=	xmms_cv_newpcm_driver=yes --disable-static
CONFIGURE_ENV=	INPUT_PLUGINS="${INPUT_PLUGINS}" \
		OUTPUT_PLUGINS="${OUTPUT_PLUGINS}" \
		VISUALIZATION_PLUGINS="${VISUALIZATION_PLUGINS}"

INPUT_PLUGINS=	cdaudio mpg123 tonegen wav
OUTPUT_PLUGINS=	OSS disk_writer
VISUALIZATION_PLUGINS=	blur_scope sanalyzer

OPTIONS_DEFINE=	ESOUND IPV6 MIKMOD NLS SPEC VFILEINFO VORBIS
OPTIONS_DEFAULT=MIKMOD VORBIS
OPTIONS_DEFINE_i386=	SIMD
OPTIONS_DEFAULT_i386=	SIMD
OPTIONS_SUB=	yes

ESOUND_CONFIGURE_ENABLE=esd
ESOUND_USE=		GNOME=esound
ESOUND_VARS=		OUTPUT_PLUGINS+=esd

IPV6_CONFIGURE_ENABLE=	ipv6

MIKMOD_CONFIGURE_ENABLE=mikmod
MIKMOD_LIB_DEPENDS=	libmikmod.so:audio/libmikmod
MIKMOD_VARS=		INPUT_PLUGINS+=mikmod

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

SIMD_CONFIGURE_ENABLE=	simd

SPEC_DESC=		Visualization opengl_spectrum
SPEC_CONFIGURE_ENABLE=	opengl
SPEC_USE=		GL=gl
SPEC_VARS=		VISUALIZATION_PLUGINS+=opengl_spectrum

VFILEINFO_DESC=		Enable Extended Vorbis Fileinfo
VFILEINFO_CPPFLAGS=	-DALL_VORBIS_TAGS

VORBIS_CONFIGURE_ENABLE=vorbis
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
VORBIS_VARS=		INPUT_PLUGINS+=vorbis

.if !defined(WITH_DEBUG)
INSTALL_TARGET=	install-strip
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/alsa_found=yes/alsa_found=no/' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,@mkdir_p@,${MKDIR},' \
		${WRKSRC}/po/Makefile.in.in
	@${FIND} ${WRKSRC} -name '*.s' | ${XARGS} ${REINPLACE_CMD} \
		-e 's,/.*,,' -e 's/fist /fists /' -e 's/fistp /fistps /' \
		-e '$$s/$$/\${.newline} .section ".note.GNU-stack","",@progbits/'

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xmms/Skins
	${INSTALL_DATA} ${FILESDIR}/xmms.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
