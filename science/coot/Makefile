# $FreeBSD$

PORTNAME=	coot
DISTVERSION=	0.8.9.1
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	https://www2.mrc-lmb.cam.ac.uk/personal/pemsley/${PORTNAME}/source/releases/ \
		https://www2.mrc-lmb.cam.ac.uk/personal/pemsley/${PORTNAME}/dependencies/:data
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} refmac-monomer-library${EXTRACT_SUFX}:data reference-structures${EXTRACT_SUFX}:data
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Crystallographic Object-Oriented Toolkit

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libccp4c.so:science/libccp4 \
		libclipper-core.so:science/clipper \
		libcurl.so:ftp/curl \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgtkglext-x11-1.0.so:x11-toolkits/gtkglext \
		libgsl.so:math/gsl \
		libmmdb2.so:science/mmdb2 \
		libpng16.so:graphics/png \
		libsfftw.so:math/fftw-float \
		libssm.so:science/libssm
RUN_DEPENDS=	bash:shells/bash

USES=		desktop-file-utils fortran gettext-runtime gmake libtool localbase:ldflags pkgconfig python:2.7 shebangfix sqlite
SHEBANG_FILES=	src/coot.in
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-python
CONFIGURE_ARGS=	--enable-shared --disable-static
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 libartlgpl2 libgnomecanvas pango pangox-compat
USE_GL=		gl glu glut
USE_XORG=	ice sm x11 xmu xt
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

MAKE_ENV=	PYTHON=${PYTHON_CMD}
CXXFLAGS+=	-I${PYTHON_INCLUDEDIR}

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib/data
	@cd ${WRKDIR} && ${COPYTREE_SHARE} monomers ${STAGEDIR}${DATADIR}/lib/data/
	@cd ${WRKDIR} && ${COPYTREE_SHARE} reference-structures ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
