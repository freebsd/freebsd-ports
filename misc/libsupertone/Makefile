# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsupertone
PORTVERSION=	0.0.2
PORTREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	http://www.soft-switch.org/downloads/unicall/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Library for supervisory tone generation and detection

LICENSE=	LGPL21

LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile \
		libspandsp.so:comms/spandsp \
		libtiff.so:graphics/tiff \
		libxml2.so:textproc/libxml2

USES=		tar:tgz libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# Add missing dependency in attempt to fix parallel (-jX) builds
post-patch:
	@${REINPLACE_CMD} -e '/DEPENDENCIES =/s,$$, $$(lib_LTLIBRARIES),' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
