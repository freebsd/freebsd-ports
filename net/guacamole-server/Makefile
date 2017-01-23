# Created by: Ultima <ultima1252@gmail.com>
# $FreeBSD$

PORTNAME=	guacamole-server
PORTVERSION=	0.9.10
DISTVERSIONSUFFIX=	-incubating
CATEGORIES=	net

MAINTAINER=	ultima1252@gmail.com
COMMENT=	HTML5 Clientless Remote Desktop

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libossp-uuid.so:misc/ossp-uuid \
		libpng.so:graphics/png

CONFLICTS_BUILD=pulseaudio-*+jack_* ffmpeg-*+jack_*

USE_GITHUB=	yes
GH_ACCOUNT=	apache
GH_PROJECT=	incubator-guacamole-server

USES=		autoreconf gettext-runtime jpeg libtool localbase \
		pkgconfig shebangfix ssl
USE_GNOME=	cairo
SHEBANG_FILES=	${WRKSRC}/src/protocols/rdp/keymaps/generate.pl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-guacd-conf=${PREFIX}/etc/guacd/guacd.conf
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

USERS=		guacamole
GROUPS=		guacamole

USE_RC_SUBR=	guacd
SUB_LIST+=	GUACD_USER=${USERS} \
		GUACD_GROUP=${GROUPS}

OPTIONS_DEFINE=		RDP SSH VNC VORBIS PULSEAUDIO WEBP GUACENC
OPTIONS_DEFAULT=	RDP SSH VNC VORBIS PULSEAUDIO WEBP GUACENC
OPTIONS_SUB=		yes
GUACENC_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
GUACENC_DESC?=		Video Encoding Utility
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_DESC?=	VNC audio support (Experimental)
RDP_LIB_DEPENDS=	libfreerdp1.so:net/freerdp1
RDP_DESC?=		RDP Protocal Support
SSH_LIB_DEPENDS=	libssh2.so:security/libssh2
SSH_USE=		GNOME=pango
SSH_DESC?=		SSH Support
VNC_LIB_DEPENDS=	libvncserver.so:net/libvncserver
VNC_DESC?=		VNC Protocol Support
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
			libogg.so:audio/libogg
VORBIS_DESC?=		Ogg Vorbis for compression
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_DESC?=		WebP support

post-patch:
	@${REINPLACE_CMD} 's|/etc/ssl|${PREFIX}/etc/ssl|g ; \
			 s|/etc/guacamole|${PREFIX}/etc/guacd|g' \
			 ${WRKSRC}/src/guacd/man/guacd.conf.5
	@${REINPLACE_CMD} 's/-Werror//' \
			  ${WRKSRC}/src/guacenc/Makefile.am

.include <bsd.port.mk>
