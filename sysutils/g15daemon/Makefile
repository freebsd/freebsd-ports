PORTNAME=	g15daemon
DISTVERSION=	3.0.4
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Daemon for Logitech G15 Keyboards
WWW=		https://gitlab.com/menelkir/g15daemon

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
LIB_DEPENDS=	libg15.so:sysutils/libg15 \
		libg15render.so:sysutils/libg15render \
		libinput.so:x11/libinput

USES=		gmake libtool localbase
USE_GITLAB=	yes
USE_LDCONFIG=	yes
USE_RC_SUBR=	g15daemon

GL_ACCOUNT=	menelkir
GL_TAGNAME=	1f4e8b41a6ea460d59cc07305a4d9b487b575ec6

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc

INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' \
		${WRKSRC}/g15daemon/main.c

.include <bsd.port.mk>
