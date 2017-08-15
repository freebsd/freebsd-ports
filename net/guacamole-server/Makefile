# Created by: Richard Gallamore <ultima@FreeBSD.org>
# $FreeBSD$

PORTNAME=	guacamole-server
PORTVERSION=	0.9.13
DISTVERSIONSUFFIX=	-incubating
CATEGORIES=	net

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	HTML5 Clientless Remote Desktop

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libossp-uuid.so:misc/ossp-uuid \
		libpng.so:graphics/png

CONFLICTS_BUILD=pulseaudio-*+jack_* ffmpeg-*+jack_*

USES=		autoreconf jpeg libtool localbase \
		pkgconfig shebangfix ssl

USE_GITHUB=	yes
GH_ACCOUNT=	apache
GH_PROJECT=	incubator-guacamole-server

USE_GNOME=	cairo
USE_LDCONFIG=	yes
USE_RC_SUBR=	guacd
SHEBANG_FILES=	${WRKSRC}/src/protocols/rdp/keymaps/generate.pl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-guacd-conf=${ETCDIR}/guacd.conf
INSTALL_TARGET=	install-strip

USERS=		guacamole
GROUPS=		guacamole

SUB_LIST=	GUACD_USER=${USERS} \
		GUACD_GROUP=${GROUPS}

OPTIONS_DEFINE=		WEBP GUACENC NLS
OPTIONS_DEFAULT=	RDP SSH VNC VORBIS PULSEAUDIO WEBP GUACENC
OPTIONS_GROUP=		SP AUDIO
OPTIONS_GROUP_SP=	RDP SSH VNC
OPTIONS_GROUP_AUDIO=	VORBIS PULSEAUDIO
OPTIONS_SUB=		yes

AUDIO_DESC=		Audio Support
GUACENC_DESC=		Video Encoding Utility
PULSEAUDIO_DESC=	VNC audio support (Experimental)
RDP_DESC=		RDP protocol support
SP_DESC=		Supported Protocols
VNC_DESC=		VNC protocol support

GUACENC_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
NLS_USES=		gettext-runtime
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
RDP_LIB_DEPENDS=	libfreerdp1.so:net/freerdp1
SSH_LIB_DEPENDS=	libssh2.so:security/libssh2
SSH_USE=		GNOME=pango
VNC_LIB_DEPENDS=	libvncserver.so:net/libvncserver
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
			libogg.so:audio/libogg
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp

post-patch:
	@${REINPLACE_CMD} 's|/etc/ssl|${PREFIX}/etc/ssl|g ; \
			 s|/etc/guacamole|${PREFIX}/etc/guacd|g' \
			 ${WRKSRC}/src/guacd/man/guacd.conf.5

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/guacd.conf.sample ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
