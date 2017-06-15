# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	liblrdf
PORTVERSION=	0.5.0
PORTREVISION=	11
CATEGORIES=	textproc
MASTER_SITES=	GENTOO

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for manipulating RDF files describing LADSPA plugins

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LIB_DEPENDS=	libraptor2.so:textproc/raptor2

GNU_CONFIGURE=	yes
USES=		autoreconf libtool pathfix pkgconfig ssl
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

WRKSRC=		${WRKDIR}/swh-LRDF-7ebc032

post-patch:
	@${FIND} ${WRKSRC}/m4 -type l -delete

.include <bsd.port.mk>
