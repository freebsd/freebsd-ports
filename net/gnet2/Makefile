# New ports collection makefile for:   gnet2
# Date created:        15 February 2003
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnet
PORTVERSION=	2.0.7
CATEGORIES=	net
MASTER_SITES=	http://www.gnetlibrary.org/src/
PKGNAMESUFFIX=	2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A simple network library built upon Glib-2

USE_GNOME=	gnomehack glib20
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--with-html-dir=${DOCSDIR}
.else
CONFIGURE_ARGS+=	--without-html-dir
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|GNET_INTERFACE_AGE=1|GNET_INTERFACE_AGE=7|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
