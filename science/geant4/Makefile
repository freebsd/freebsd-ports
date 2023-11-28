PORTNAME=		geant4
DISTVERSIONPREFIX=	v
DISTVERSION=		11.1.2
PORTREVISION=	2
CATEGORIES=		science parallel devel cad
MASTER_SITES=		https://cern.ch/geant4-data/releases/ \
			https://cern.ch/geant4-data/datasets/:data
DISTFILES=		${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=		${PORTNAME} # dataset versions generally span several release versions

MAINTAINER=	erik@tenku.dk
COMMENT=	Simulate the passage of particles through matter
WWW=		https://geant4.cern.ch/

LICENSE=	GEANT4
LICENSE_NAME=	Geant4 Software License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libCLHEP.so:science/clhep \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libptl.so:devel/ptl \
		libtbb.so:devel/onetbb \
		libxerces-c.so:textproc/xerces-c3 \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake \
		compiler:c++17-lang \
		gl \
		motif \
		qt:5 \
		xorg
USE_GL=		egl gl glu opengl
USE_QT=		3d buildtools core gui network \
		opengl printsupport qmake widgets
USE_XORG=	ice sm x11 xau xaw xcb xcomposite \
		xcursor xdamage xdmcp xext xfixes \
		xfont xfont2 xft xi xinerama \
		xkbfile xmu xpm xrandr xrender \
		xres xscrnsaver xt xtst xv xxf86vm

CMAKE_ON=	GEANT4_BUILD_MULTITHREADED \
		GEANT4_USE_SYSTEM_CLHEP \
		GEANT4_USE_SYSTEM_PTL \
		GEANT4_USE_SYSTEM_ZLIB \
		GEANT4_USE_FREETYPE \
		GEANT4_USE_GDML \
		GEANT4_USE_OPENGL_X11 \
		GEANT4_USE_QT \
		GEANT4_USE_RAYTRACER_X11 \
		GEANT4_USE_TBB \
		GEANT4_USE_XM

G4ABLA_VERSION=			3.1
G4EMLOW_VERSION=		8.2
G4ENSDFSTATE_VERSION=		2.3
G4INCL_VERSION=			1.0
G4NDL_VERSION=			4.7
G4PARTICLEXS_VERSION=		4.0
G4PhotonEvaporation_VERSION=	5.7
G4PII_VERSION=			1.3
G4RadioactiveDecay_VERSION=	5.6
G4RealSurface_VERSION=		2.2
G4SAIDDATA_VERSION=		2.0
G4TENDL_VERSION=		1.4
G4_DATASETS=	G4ABLA.${G4ABLA_VERSION} G4EMLOW.${G4EMLOW_VERSION} G4ENSDFSTATE.${G4ENSDFSTATE_VERSION} G4INCL.${G4INCL_VERSION} \
		G4NDL.${G4NDL_VERSION} G4PARTICLEXS.${G4PARTICLEXS_VERSION} G4PhotonEvaporation.${G4PhotonEvaporation_VERSION} G4PII.${G4PII_VERSION} \
		G4RadioactiveDecay.${G4RadioactiveDecay_VERSION} G4RealSurface.${G4RealSurface_VERSION} G4SAIDDATA.${G4SAIDDATA_VERSION} G4TENDL.${G4TENDL_VERSION}
.for dataset in ${G4_DATASETS}
DISTFILES+=	${dataset}${EXTRACT_SUFX}:data
.endfor

PLIST_SUB+=	G4ABLA_VERSION="${G4ABLA_VERSION}" \
		G4EMLOW_VERSION="${G4EMLOW_VERSION}" \
		G4ENSDFSTATE_VERSION="${G4ENSDFSTATE_VERSION}" \
		G4INCL_VERSION="${G4INCL_VERSION}" \
		G4NDL_VERSION="${G4NDL_VERSION}" \
		G4PARTICLEXS_VERSION="${G4PARTICLEXS_VERSION}" \
		G4PhotonEvaporation_VERSION="${G4PhotonEvaporation_VERSION}" \
		G4PII_VERSION="${G4PII_VERSION}" \
		G4RadioactiveDecay_VERSION="${G4RadioactiveDecay_VERSION}" \
		G4RealSurface_VERSION="${G4RealSurface_VERSION}" \
		G4SAIDDATA_VERSION="${G4SAIDDATA_VERSION}" \
		G4TENDL_VERSION="${G4TENDL_VERSION}" \
		SHLIB_VER="${DISTVERSION}"

G4_DATADIRS=	G4ABLA${G4ABLA_VERSION} G4EMLOW${G4EMLOW_VERSION} G4ENSDFSTATE${G4ENSDFSTATE_VERSION} G4INCL${G4INCL_VERSION} \
		G4NDL${G4NDL_VERSION} G4PARTICLEXS${G4PARTICLEXS_VERSION} PhotonEvaporation${G4PhotonEvaporation_VERSION} G4PII${G4PII_VERSION} \
		RadioactiveDecay${G4RadioactiveDecay_VERSION} RealSurface${G4RealSurface_VERSION} G4SAIDDATA${G4SAIDDATA_VERSION} G4TENDL${G4TENDL_VERSION}

post-install:
.for dir in ${G4_DATADIRS}
	cd ${WRKDIR} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${PREFIX}/share/Geant4/data/
.endfor

.include <bsd.port.mk>
