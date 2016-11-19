# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gupnp-ui
PORTVERSION=	0.1.1
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Framework for UPnP devices

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gupnp>=0.3:net/gupnp
LIB_DEPENDS=	libgupnp-1.0.so:net/gupnp \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_GNOME=	gtk20
USE_LDCONFIG=	yes
USES=		libtool pathfix pkgconfig python

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s|tests||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
