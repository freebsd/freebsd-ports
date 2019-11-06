# $FreeBSD$

PORTNAME=	libvdpau
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://cgit.freedesktop.org/~aplattner/libvdpau/snapshot/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	VDPAU wrapper and tracing library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool pkgconfig tar:xz xorg
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-documentation
USE_XORG=	xorgproto xext
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DEBUG

DEBUG_CFLAGS=		-D_DEBUG
DEBUG_CFLAGS_OFF=	-DNDEBUG

post-patch:	.SILENT
	${REINPLACE_CMD} 's|$$(libdir)/\(pkgconfig\)|$$(prefix)/libdata/\1|' \
		${WRKSRC}/Makefile.am
	${REINPLACE_CMD} '/^export /d' ${WRKSRC}/doc/Makefile.am
	cd ${WRKSRC}/src && ${MV} vdpau_wrapper.cfg vdpau_wrapper.cfg.sample
	${REINPLACE_CMD} 's/vdpau_wrapper.cfg/&.sample/' \
		${WRKSRC}/src/Makefile.am

.include <bsd.port.mk>
