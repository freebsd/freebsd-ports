# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	remmina
DISTVERSION=	1.3.5
CATEGORIES=	net gnome

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	GTK+ Remote Desktop Client

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libsodium.so:security/libsodium \
		libsoup-2.4.so:devel/libsoup

USES=		cmake compiler:c11 desktop-file-utils gettext gnome localbase:ldflags pathfix \
		pkgconfig shared-mime-info ssl shebangfix xorg

USE_GITLAB=	yes
GL_ACCOUNT=	Remmina
GL_PROJECT=	Remmina
GL_COMMIT=	e1a0ffd30a0d8e35ed86ec81ecb4719bb870d62c

USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 pango
USE_XORG=	ice sm x11 xext xkbfile
INSTALLS_ICONS=	yes
CMAKE_ARGS=	--build=build \
		-DWITH_APPINDICATOR:BOOL=false
SHEBANG_FILES=	data/desktop/remmina-file-wrapper.sh.in

OPTIONS_DEFINE=		AVAHI GCRYPT NLS SSH TERM
OPTIONS_DEFAULT=	AVAHI GCRYPT SSH TERM
OPTIONS_SUB=		yes

AVAHI_DESC=		Build with Avahi support
GCRYPT_DESC=		Build with libgcrypt support for password encryption
SSH_DESC=		Build with SSH tunneling support
TERM_DESC=		Build with terminal support

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app \
			libavahi-ui-gtk3.so:net/avahi-gtk3
AVAHI_CMAKE_BOOL=	WITH_AVAHI

GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
GCRYPT_CMAKE_BOOL=	WITH_GCRYPT

NLS_CMAKE_BOOL=		WITH_TRANSLATIONS

SSH_LIB_DEPENDS=	libssh.so:security/libssh
SSH_LDFLAGS=		-fstack-protector
SSH_CMAKE_BOOL=		WITH_LIBSSH

TERM_USE=		gnome=vte3
TERM_CMAKE_BOOL=	WITH_VTE

post-patch:
	# do not build plugins and locales , they are provided by separated ports
	${REINPLACE_CMD} -e '/add_subdirectory(plugins/d' \
		-e 's,FreeBSD,FreeBSD|DragonFly,' \
		${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's,FreeBSD,FreeBSD|DragonFly,' \
		${WRKSRC}/src/CMakeLists.txt

.include <bsd.port.mk>
