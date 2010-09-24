# New ports collection makefile for:	libvdpau
# Date created:				2010-09-08
# Whom:					Anonymous <swell.k@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libvdpau
PORTVERSION=	0.4.1
CATEGORIES=	multimedia
MASTER_SITES=	http://people.freedesktop.org/~aplattner/vdpau/

MAINTAINER=	swell.k@gmail.com
COMMENT=	VDPAU wrapper and tracing library

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-documentation
USE_GMAKE=	yes
USE_XORG=	dri2proto xext
USE_LDCONFIG=	yes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

post-patch:	.SILENT
	${REINPLACE_CMD} 's|$$(libdir)/\(pkgconfig\)|$$(prefix)/libdata/\1|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
