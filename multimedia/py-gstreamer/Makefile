# New ports collection makefile for:	gstreamer-python
# Date created:		Fri Apr  9 16:24:13 CEST 2004
# Whom:			Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.8.1
CATEGORIES=	multimedia python gnome
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-python/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kwm
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gst-python-${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	A set of Python bindings for gstreamer

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2mod.so:${PORTSDIR}/textproc/py-libxml2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2mod.so:${PORTSDIR}/textproc/py-libxml2

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	xmlto:${PORTSDIR}/textproc/xmlto \
		lynx:${PORTSDIR}/www/lynx
.endif

USE_PYTHON=	yes
USE_GMAKE=	yes
USE_GNOME=	gstreamerplugins \
		pygtk2 \
		gnomehack \
		pkgconfig
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}"
DOCS=		README.html README.txt

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS=	--enable-docs
.else
CONFIGURE_ARGS=	--disable-docs
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|DLFCN|dl|g' ${WRKSRC}/gst/__init__.py

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
