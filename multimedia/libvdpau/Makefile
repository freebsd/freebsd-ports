# $FreeBSD$

PORTNAME=	libvdpau
PORTVERSION=	0.5
CATEGORIES=	multimedia
MASTER_SITES=	http://people.freedesktop.org/~aplattner/vdpau/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VDPAU wrapper and tracing library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USE_AUTOTOOLS=	autoconf:env automake:env libtool:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-documentation
USE_GMAKE=	yes
USE_XORG=	dri2proto xext
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CFLAGS+=	-DDEBUG
.endif

.if defined(STRIP) && ${STRIP} != ""
INSTALL_TARGET=	install-strip
.endif

pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ./autogen.sh

post-patch:
	${REINPLACE_CMD} 's|$$(libdir)/\(pkgconfig\)|$$(prefix)/libdata/\1|' \
		${WRKSRC}/Makefile.am

.include <bsd.port.post.mk>
