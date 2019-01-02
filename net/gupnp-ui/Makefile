# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gupnp-ui
PORTVERSION=	0.1.1
PORTREVISION=	6
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Framework for UPnP devices

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libgupnp-1.2.so:net/gupnp \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	gupnp>=0.3:net/gupnp

USES=		compiler:c++11-lang gnome libtool pathfix pkgconfig python
USE_GNOME=	gtk20

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s|tests||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|gupnp-1.0|gupnp-1.2|' ${WRKSRC}/configure ${WRKSRC}/gupnp-ui-1.0.pc.in

.include <bsd.port.mk>
