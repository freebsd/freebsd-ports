# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	emotion
PORTVERSION=	1.7.8
PORTEPOCH=	1
CATEGORIES=	multimedia enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Video playback wrapper library for Enlightenment

LICENSE=	BSD

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig
USE_EFL=	ecore edje eet eio embryo evas libtool_hack modarch_hack
USE_EFL_EVAS_LOADERS=	png jpeg
USE_LDCONFIG=	yes

# emotion's vlc plugin needs updating due to libvlc API changes
# details: http://trac.enlightenment.org/e/ticket/601
CONFIGURE_ARGS=	--disable-generic-vlc

OPTIONS_MULTI=	BACKEND
OPTIONS_MULTI_BACKEND=	GSTREAMER LIBXINE
OPTIONS_DEFAULT=GSTREAMER

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64: coredump
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER=	ffmpeg good
CONFIGURE_ARGS+=--enable-gstreamer
PLIST_SUB+=	GST=""
.else
CONFIGURE_ARGS+=--disable-gstreamer
PLIST_SUB+=	GST="@comment "
.endif

.if ${PORT_OPTIONS:MLIBXINE}
LIB_DEPENDS+=	xine:${PORTSDIR}/multimedia/libxine
CONFIGURE_ARGS+=--enable-xine
PLIST_SUB+=	XINE=""
.else
CONFIGURE_ARGS+=--disable-xine
PLIST_SUB+=	XINE="@comment "
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
CONFIGURE_ARGS+=--enable-install-examples
.else
CONFIGURE_ARGS+=--disable-install-examples
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|= \$$(datadir)/\$$(PACKAGE)/examples|= $$(datadir)/examples/$$(PACKAGE)|' \
		${WRKSRC}/src/examples/Makefile.in

.include <bsd.port.mk>
