PORTNAME=		dhcpcd-ui
DISTVERSIONPREFIX=	v
DISTVERSION=		0.7.9
CATEGORIES=		net

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	GTK+ / Curses interface to dhcpcd
WWW=		https://roy.marples.name/projects/dhcpcd-ui

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairosvg>=0:graphics/py-cairosvg@${PY_FLAVOR}
LIB_DEPENDS=	libnotify.so:devel/libnotify

USES=		pkgconfig python
USE_GITHUB=	yes
GH_ACCOUNT=	NetworkConfiguration

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-notification \
		--mandir=${MANPREFIX}/man \
		--with-dhcpcd-online \
		--with-icons

OPTIONS_DEFINE=		GTK3
OPTIONS_DEFAULT=	GTK3
OPTIONS_SUB=		yes

GTK3_USES=		gnome
GTK3_USE=		gnome=gdkpixbuf2,gtk30
GTK3_CONFIGURE_WITH=	gtk

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dhcpcd-curses ${STAGEDIR}${PREFIX}/bin/dhcpcd-online

.include <bsd.port.mk>
