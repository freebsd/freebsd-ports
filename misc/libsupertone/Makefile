# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsupertone
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.soft-switch.org/downloads/unicall/
EXTRACT_SUFX=	.tgz

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Library for supervisory tone generation and detection

LICENSE=	LGPL21

LIB_DEPENDS=	libaudiofile.so:${PORTSDIR}/audio/libaudiofile \
		libspandsp.so:${PORTSDIR}/comms/spandsp-devel \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libxml2.so:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# Add missing dependency in attempt to fix parallel (-jX) builds
NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '/DEPENDENCIES =/s,$$, $$(lib_LTLIBRARIES),' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
