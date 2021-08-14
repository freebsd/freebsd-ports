PORTNAME=	g15daemon
PORTVERSION=	3.0.4
CATEGORIES=	sysutils
MASTER_SITES=	https://gitlab.com/menelkir/${PORTNAME}/-/archive/${PORTVERSION}/

MAINTAINER=	menelkir@itroll.org
COMMENT=	Daemon for Logitech G15 Keyboards

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	libg15.so:sysutils/libg15 \
		libg15render.so:sysutils/libg15render \
		libinput.so:x11/libinput

USES=		gmake localbase libtool

USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=${LOCALBASE}/etc

USE_RC_SUBR=	g15daemon

INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' \
		${WRKSRC}/g15daemon/main.c

.include <bsd.port.mk>
