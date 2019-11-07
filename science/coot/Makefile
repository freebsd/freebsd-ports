# $FreeBSD$

PORTNAME=	coot
DISTVERSION=	0.8.9.2
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	https://www2.mrc-lmb.cam.ac.uk/personal/pemsley/${PORTNAME}/source/releases/ \
		https://www2.mrc-lmb.cam.ac.uk/personal/pemsley/${PORTNAME}/dependencies/:data
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} refmac-monomer-library${EXTRACT_SUFX}:data reference-structures${EXTRACT_SUFX}:data
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Crystallographic Object-Oriented Toolkit

BROKEN=		unfetchable

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	fftw>0:math/fftw
LIB_DEPENDS=	libccp4c.so:science/libccp4 \
		libclipper-core.so:science/clipper \
		libcurl.so:ftp/curl \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgoocanvas.so:graphics/goocanvas \
		libgtkglext-x11-1.0.so:x11-toolkits/gtkglext \
		libgsl.so:math/gsl \
		libmmdb2.so:science/mmdb2 \
		libpng.so:graphics/png \
		libsfftw.so:math/fftw-float \
		libssm.so:science/libssm
RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang desktop-file-utils fortran gettext-runtime \
		gl gmake gnome libtool localbase:ldflags pkgconfig python:2.7 \
		shebangfix sqlite xorg
SHEBANG_FILES=	src/coot.in
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --disable-static --with-goocanvas-prefix=${LOCALBASE}
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 libartlgpl2 libgnomecanvas pango pangox-compat
USE_GL=		gl glu glut
USE_XORG=	ice sm x11 xmu xt
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

MAKE_ENV=	PYTHON=${PYTHON_CMD}
CXXFLAGS+=	-I${PYTHON_INCLUDEDIR} -DANALYSE_REFINEMENT_TIMING

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib/data
	@cd ${WRKDIR} && ${COPYTREE_SHARE} monomers ${STAGEDIR}${DATADIR}/lib/data/
	@cd ${WRKDIR} && ${COPYTREE_SHARE} reference-structures ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
