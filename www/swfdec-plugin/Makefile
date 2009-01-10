# Ports collection makefile for:	swfdec-plugin
# Date created:				Jun 14, 2005
# Whom:					anholt
#
# $FreeBSD$
#

PORTNAME=	swfdec-plugin
PORTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://swfdec.freedesktop.org/download/swfdec-mozilla/0.6/
DISTNAME=	swfdec-mozilla-${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Flash rendering plugin

LIB_DEPENDS=	swfdec-0.6:${PORTSDIR}/graphics/swfdec

USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--with-plugin-dir="${WEBPLUGINS_DIR}"

USE_LDCONFIG=	yes

USE_WEBPLUGINS=	gecko*
WEBPLUGINS_FILES=libswfdecmozilla.so

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"
.include <bsd.port.post.mk>
