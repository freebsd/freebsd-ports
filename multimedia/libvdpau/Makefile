# $FreeBSD$

PORTNAME=	libvdpau
PORTVERSION=	0.6
CATEGORIES=	multimedia
MASTER_SITES=	http://cgit.freedesktop.org/~aplattner/libvdpau/snapshot/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	VDPAU wrapper and tracing library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USE_XZ=		yes
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtoolize
ACLOCAL_ARGS=	-I.
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ARGS=	--disable-documentation
USE_XORG=	dri2proto xext
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DEBUG

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CFLAGS+=	-D_DEBUG
.else
CFLAGS+=	-DNDEBUG
.endif

.include <bsd.port.pre.mk>

.if defined(STRIP) && ${STRIP} != ""
INSTALL_TARGET=	install-strip
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} 's|$$(libdir)/\(pkgconfig\)|$$(prefix)/libdata/\1|' \
		${WRKSRC}/Makefile.am
	${REINPLACE_CMD} '/^export /d' ${WRKSRC}/doc/Makefile.am
	cd ${WRKSRC}/src && ${MV} vdpau_wrapper.cfg vdpau_wrapper.cfg.sample
	${REINPLACE_CMD} 's/vdpau_wrapper.cfg/&.sample/' \
		${WRKSRC}/src/Makefile.am

post-install:
	if [ ! -f ${PREFIX}/etc/vdpau_wrapper.cfg ]; then \
		${INSTALL_DATA} ${PREFIX}/etc/vdpau_wrapper.cfg.sample \
			${PREFIX}/etc/vdpau_wrapper.cfg; \
	fi

.include <bsd.port.post.mk>
