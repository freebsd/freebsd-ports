PORTNAME=	liblrdf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
CATEGORIES=	textproc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for manipulating RDF files describing LADSPA plugins
WWW=		https://github.com/swh/LRDF

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LIB_DEPENDS=	libraptor2.so:textproc/raptor2

USES=		autoreconf libtool pathfix pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	swh
GH_PROJECT=	LRDF
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

.include <bsd.port.mk>
