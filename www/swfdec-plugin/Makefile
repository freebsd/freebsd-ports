# Created by: anholt
# $FreeBSD$

PORTNAME=	swfdec-plugin
PORTVERSION=	0.8.2
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://swfdec.freedesktop.org/download/swfdec-mozilla/0.8/
DISTNAME=	swfdec-mozilla-${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Flash rendering plugin

LIB_DEPENDS=	swfdec-0.8:${PORTSDIR}/graphics/swfdec

USES=		pkgconfig
USE_AUTOTOOLS=	libtool
INSTALLS_ICONS=	yes
USE_GNOME=	gtk20
CONFIGURE_ARGS=	--with-plugin-dir="${WEBPLUGINS_DIR}"

USE_LDCONFIG=	yes

USE_WEBPLUGINS=	gecko*
WEBPLUGINS_FILES=libswfdecmozilla.so

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"
.include <bsd.port.post.mk>
