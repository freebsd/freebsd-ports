# $FreeBSD$

PORTNAME=	free42
DISTVERSION=	2.0.20
CATEGORIES=	misc
MASTER_SITES=	http://thomasokken.com/free42/upstream/
DISTNAME=	${PORTNAME}-nologo-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simulation of the HP-42S scientific calculator and HP-82240 printer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=		fails to link: c++: error: no such file or directory: 'gcc111libbid.a'
BROKEN_armv6=		fails to link: c++: error: no such file or directory: 'gcc111libbid.a'
BROKEN_mips64=		fails to link: c++: error: no such file or directory: 'gcc111libbid.a'

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		dos2unix gmake localbase pkgconfig tar:tgz
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 pango
USE_XORG=	x11 xmu
DOS2UNIX_FILES=	gtk/IntelRDFPMathLib20U1/LIBRARY/float128/op_system.h

CXXFLAGS+=	-Wno-c++11-narrowing -Wno-constant-conversion # to accommodate some code breaking with clang-50
BUILD_WRKSRC=	${WRKSRC}/gtk

post-extract:
	@cd ${BUILD_WRKSRC} && tar xvfz ../inteldecimal/IntelRDFPMathLib20U1.tar.gz

post-patch:
	@${REINPLACE_CMD} -e 's|snprintf(free42dirname, FILENAMELEN, "%s/\.free42", home)|strcpy(free42dirname, "${DATADIR}")|' \
		${BUILD_WRKSRC}/shell_main.cc

do-build:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} cleaner && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD}
		# TODO do we need decimal fp arithmetic?: ${MAKE_CMD} BCD_MATH=1 SKIN_SYS_DIR="${DATADIR}"

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/free42bin ${STAGEDIR}${PREFIX}/bin/
	@cd ${WRKSRC} && ${COPYTREE_SHARE} skins ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
