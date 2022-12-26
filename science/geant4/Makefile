PORTNAME=	geant4
DISTVERSION=	11.0.3
CATEGORIES=	science parallel python devel cad
# Supplementary data files for Geant4 fetched from MASTER_SITES:n with "n"=	"data" - Geant4 itself is fetched from GL_SITE defined further down
MASTER_SITES=	https://cern.ch/geant4-data/datasets/:data
# Names of supplementary data files for Geant4 defined in DISTFILES:n with "n"=	"data"
DISTFILES+=	G4ABLA.3.1.tar.gz:data \
		G4EMLOW.8.0.tar.gz:data \
		G4ENSDFSTATE.2.3.tar.gz:data \
		G4INCL.1.0.tar.gz:data \
		G4NDL.4.6.tar.gz:data \
		G4PARTICLEXS.4.0.tar.gz:data \
		G4PhotonEvaporation.5.7.tar.gz:data \
		G4PII.1.3.tar.gz:data \
		G4RadioactiveDecay.5.6.tar.gz:data \
		G4RealSurface.2.2.tar.gz:data \
		G4SAIDDATA.2.0.tar.gz:data
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	erik@tenku.dk
COMMENT=	Simulate the passage of particles through matter
WWW=		https://geant4.cern.ch/

LICENSE=	GEANT4
LICENSE_NAME=	Geant4 Software License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	git:devel/git
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-util.so:x11/xcb-util \
		libxerces-c.so:textproc/xerces-c3 \
		libxkbcommon.so:x11/libxkbcommon \
		${PY_BOOST}

USES=		cmake \
		compiler:c++17-lang \
		gl \
		motif \
		python:3.9+ \
		xorg
CMAKE_ON=	GEANT4_BUILD_MULTITHREADED \
		GEANT4_USE_GDML \
		GEANT4_USE_OPENGL_X11 \
		GEANT4_USE_PYTHON \
		GEANT4_USE_RAYTRACER_X11 \
		GEANT4_USE_XM \
		GEANT4_USE_FREETYPE
USE_GITLAB=	yes
GL_SITE=	https://gitlab.cern.ch/
GL_COMMIT=	3136fa97238bf2b24eba982206fb72b32b898d96
USE_GL=		egl gl glu opengl
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xau xaw xcb xcomposite \
		xcursor xdamage xdmcp xext xfixes \
		xfont xfont2 xft xi xinerama \
		xkbfile xmu xpm xrandr xrender \
		xres xscrnsaver xt xtst xv xxf86vm

CONFIGURE_WRKSRC?=	${WRKDIR}/.build
STAGEDIR?=		${WRKDIR}/stage
CMAKE_ARGS+=		-DGEANT4_BUILD_TLS_MODEL=global-dynamic

G4_DATADIRS=	G4ABLA3.1 G4EMLOW8.0 G4ENSDFSTATE2.3 \
		G4INCL1.0 G4NDL4.6 G4PARTICLEXS4.0 \
		G4PII1.3 G4SAIDDATA2.0 \
		PhotonEvaporation5.7 \
		RadioactiveDecay5.6 RealSurface2.2

post-install:
.for dir in ${G4_DATADIRS}
	cd ${WRKDIR} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${PREFIX}/share/Geant4-${DISTVERSION}/data/
.endfor

.include <bsd.port.mk>
