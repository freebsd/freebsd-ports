# New ports collection makefile for:	libvdpau
# Date created:				2010-09-08
# Whom:					Anonymous <swell.k@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libvdpau
PORTVERSION=	0.4.1
PORTREVISION=	1
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

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CFLAGS+=	-DDEBUG
.endif

.if defined(STRIP) && ${STRIP} != ""
INSTALL_TARGET=	install-strip
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} 's|$$(libdir)/\(pkgconfig\)|$$(prefix)/libdata/\1|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
