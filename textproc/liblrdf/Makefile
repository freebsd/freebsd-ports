# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	liblrdf
DISTVERSION=	0.6.1
CATEGORIES=	textproc
MASTER_SITES=	GENTOO

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for manipulating RDF files describing LADSPA plugins

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LIB_DEPENDS=	libraptor2.so:textproc/raptor2

USES=		autoreconf libtool pathfix pkgconfig ssl
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/LRDF-${DISTVERSION}

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

.include <bsd.port.mk>
