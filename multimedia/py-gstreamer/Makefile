# New ports collection makefile for:	gstreamer-python
# Date created:		Fri Apr  9 16:24:13 CEST 2004
# Whom:			Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.7.91
CATEGORIES=	multimedia python gnome
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gst-python-${PORTVERSION}

MAINTAINER=	kwm@rainbow-runner.nl
COMMENT=	A set of Python bindings for gstreamer

.if !defined(NOPORTDOCS)
BUILD_DEPENDS=	xmlto:${PORTSDIR}/textproc/xmlto \
		lynx:${PORTSDIR}/www/lynx
.endif

USE_PYTHON=	yes
USE_GMAKE=	yes
USE_GNOME=	gstreamerplugins \
		pygtk2 \
		gnomehack \
		pkgconfig \
		lthack
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}"
DOCS=		README.html README.txt
EXAMPLES=	gst/bps.py gst/cp.py gst/dvdplay.py gst/f2f.py \
		gst/identity.py gst/ilat.py gst/lat.py gst/rot13.py \
		gst/vorbisplay.py gst/wavenc.py gstplay/player.py

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS=	--enable-docs
.else
CONFIGURE_ARGS=	--disable-docs
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.for i in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
