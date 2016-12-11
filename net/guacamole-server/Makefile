# Created by: Ultima <ultima1252@gmail.com>
# $FreeBSD$

PORTNAME=	guacamole-server
PORTVERSION=	0.9.9
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	ultima1252@gmail.com
COMMENT=	HTML5 Clientless Remote Desktop

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libossp-uuid.so:misc/ossp-uuid \
		libpng.so:graphics/png

CONFLICTS_BUILD=pulseaudio-*+jack_* ffmpeg-*+jack_*

USE_GITHUB=	yes
GH_ACCOUNT=	glyptodon

USES=		autoreconf jpeg libtool localbase pkgconfig shebangfix ssl
USE_GNOME=	cairo
SHEBANG_FILES=	${WRKSRC}/src/protocols/rdp/keymaps/generate.pl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-guacd-conf=${PREFIX}/etc/guacd/guacd.conf
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes
USERS=		guacamole
GROUPS=		guacamole

USE_RC_SUBR=	guacd
SUB_LIST+=	GUACD_USER=${USERS} \
		GUACD_GROUP=${GROUPS}

OPTIONS_DEFINE=		RDP SSH VNC VORBIS PULSEAUDIO WEBP
OPTIONS_DEFAULT=	RDP SSH VNC VORBIS PULSEAUDIO WEBP
OPTIONS_SUB=		yes
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

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} 's|/etc/ssl|${PREFIX}/etc/ssl|g ; \
			 s|/etc/guacamole|${PREFIX}/etc/guacd|g' \
			 ${WRKSRC}/src/guacd/man/guacd.conf.5
post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libguac.so.*
.if ${PORT_OPTIONS:MSSH}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libguac-client-ssh.so.*
.endif
.if ${PORT_OPTIONS:MRDP}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/freerdp/guacsnd-client.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/freerdp/guacdr-client.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/freerdp/guacsvc-client.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libguac-client-rdp.so.*
.endif
.if ${PORT_OPTIONS:MVNC}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libguac-client-vnc.so.*
.endif

.include <bsd.port.post.mk>
