# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	buzztard
PORTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20gstreamer%20extensions/
PKGNAMEPREFIX=	gstreamer-plugins-
DISTNAME=	gst-${PORTNAME}-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Buzztard gstreamer plugins

DEPRECATED=	Unused in the ports tree and unmaintained upstream
EXPIRATION_DATE=	2018-12-21

OPTIONS_DEFINE=	DOCS

LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth

USES=		pathfix libtool pkgconfig
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_GSTREAMER=	yes
USE_LDCONFIG=	yes
PLIST_SUB=	GST_VERSION="${GST_VERSION}"

post-patch:
	@${REINPLACE_CMD} -e 's|$${datadir}/gtk-doc/html|${DOCSDIR}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
