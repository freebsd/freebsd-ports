# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libepc
PORTVERSION=	0.3.11
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	The Easy Publish and Consume library

LIB_DEPENDS=	libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libavahi-ui.so:${PORTSDIR}/net/avahi-gtk

USES=		gettext gmake libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix gtk20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-static

post-patch:
	@${REINPLACE_CMD} \
		-e '/^examples_server_credentials_LDADD =/s/$$/ $$(LIBEPC_UI_LIBS)/' \
		-e '/^examples_service_browser_LDADD =/s/$$/ $$(LIBEPC_LIBS)/' \
		-e '/^tests_test_progress_hooks_LDADD =/s/$$/ $$(LIBEPC_UI_LIBS)/' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
