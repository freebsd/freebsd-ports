PORTNAME=	libsupertone
PORTVERSION=	0.0.2
PORTREVISION=	11
CATEGORIES=	misc
MASTER_SITES=	http://www.soft-switch.org/downloads/unicall/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for supervisory tone generation and detection
WWW=		https://www.soft-switch.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile \
		libspandsp.so:comms/spandsp \
		libtiff.so:graphics/tiff

USES=		gnome tar:tgz libtool
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# Add missing dependency in attempt to fix parallel (-jX) builds
post-patch:
	@${REINPLACE_CMD} -e '/DEPENDENCIES =/s,$$, $$(lib_LTLIBRARIES),' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
