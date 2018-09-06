# $FreeBSD$

PORTNAME=	lammps
PORTVERSION=	${GH_TAGNAME:C/stable_([0-9]{1,2})([A-Z][a-z][a-z])([0-9]{4})/\3.\2.\1/S/Jan/01/S/Feb/02/S/Mar/03/S/Apr/04/S/May/05/S/Jun/06/S/Jul/07/S/Aug/08/S/Sep/09/S/Oct/10/S/Nov/11/S/Dec/12/}
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Classical molecular dynamics code with a focus on materials modeling

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng16.so:graphics/png \
		libmpi_cxx.so:net/openmpi

USES=		cmake:outsource eigen:3 jpeg shebangfix
USE_GITHUB=	yes
GH_TAGNAME=	stable_22Aug2018
SHEBANG_GLOB=	*.sh *.bash
SHEBANG_FILES=	lib/kokkos/bin/nvcc_wrapper

CMAKE_SOURCE_PATH=	${WRKSRC}/cmake

OPTIONS_DEFINE=		FFMPEG
OPTIONS_DEFAULT=	FFMPEG

FFMPEG_BUILD_DEPENDS=	ffmpeg:multimedia/ffmpeg
FFMPEG_RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

post-patch-FFMPEG-off:
	@${REINPLACE_CMD} 's|find_program(FFMPEG_EXECUTABLE|#&|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
