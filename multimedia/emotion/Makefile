# New ports collection makefile for:	emotion
# Date created:		2006-07-16
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	emotion
PORTVERSION=	0.2.0.65643
PORTEPOCH=	1
CATEGORIES=	multimedia enlightenment
MASTER_SITES=	http://download.enlightenment.org/snapshots/2011-11-28/ \
		http://files.roorback.net/e17/base/

MAINTAINER=	magik@roorback.net
COMMENT=	Video playback wrapper library for Enlightenment

LICENSE=	BSD

DIST_SUBDIR=	e17
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_EFL=	ecore edje eet eio embryo evas libtool_hack modarch_hack
USE_EFL_EVAS_LOADERS=	png jpeg
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

OPTIONS=	GST	"Build GStreamer module"	on \
		XINE	"Build Xine module"		off

# emotion's vlc plugin needs updating due to libvlc API changes
# details: http://trac.enlightenment.org/e/ticket/601
CONFIGURE_ARGS=	--disable-generic-vlc

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64: coredump
.endif

.if defined(WITHOUT_XINE) && defined(WITHOUT_GST)
IGNORE=	is useless without playback library. Please run 'make config' and choose one of XINE and GST
.endif

.if !defined(WITHOUT_XINE)
LIB_DEPENDS+=	xine.2:${PORTSDIR}/multimedia/libxine
CONFIGURE_ARGS+=--enable-xine
PLIST_SUB+=	XINE=""
.else
CONFIGURE_ARGS+=--disable-xine
PLIST_SUB+=	XINE="@comment "
.endif

.if !defined(WITHOUT_GST)
USE_GSTREAMER=	ffmpeg good
CONFIGURE_ARGS+=--enable-gstreamer
PLIST_SUB+=	GST=""
.else
CONFIGURE_ARGS+=--disable-gstreamer
PLIST_SUB+=	GST="@comment "
.endif

.if !defined(NOPORTEXAMPLES)
CONFIGURE_ARGS+=	--enable-install-examples
.else
CONFIGURE_ARGS+=	--disable-install-examples
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|= \$$(datadir)/\$$(PACKAGE)/examples|= $$(datadir)/examples/$$(PACKAGE)|' \
		${WRKSRC}/src/examples/Makefile.in

post-install:
.if defined(NOPORTEXAMPLES)
	@${RMDIR} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
