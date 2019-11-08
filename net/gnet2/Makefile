# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnet
PORTVERSION=	2.0.8
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Simple network library built upon Glib-2

USES=		gnome libtool pathfix pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

DOCS_CONFIGURE_ON=	--with-html-dir=${DOCSDIR}
DOCS_CONFIGURE_OFF=	--without-html-dir

post-patch:
	@${REINPLACE_CMD} -e 's|GNET_INTERFACE_AGE=0|GNET_INTERFACE_AGE=8|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
