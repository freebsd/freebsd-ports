# Created by: anholt
# $FreeBSD$

PORTNAME=	swfdec-plugin
PORTVERSION=	0.8.2
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	http://swfdec.freedesktop.org/download/swfdec-mozilla/0.8/
DISTNAME=	swfdec-mozilla-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flash rendering plugin

LIB_DEPENDS=	libswfdec-0.8.so:graphics/swfdec

USES=		libtool:keepla pkgconfig webplugin:gecko
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
USE_GNOME=	gtk20
CONFIGURE_ARGS=	--with-plugin-dir="${WEBPLUGIN_DIR}"

USE_LDCONFIG=	yes

WEBPLUGIN_FILES=libswfdecmozilla.so

.include <bsd.port.mk>
