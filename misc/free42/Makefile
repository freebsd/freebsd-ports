# $FreeBSD$

PORTNAME=	free42
DISTVERSION=	3.0.1
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
BROKEN_powerpc64=	fails to link: c++: error: no such file or directory: 'gcc111libbid.a'
BROKEN_riscv64=		fails to link: c++: error: no such file or directory: 'gcc111libbid.a'

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler dos2unix gmake gnome localbase pkgconfig tar:tgz xorg
USE_GNOME=	atk cairo gdkpixbuf2 gtk30 pango
USE_XORG=	x11 xmu
DOS2UNIX_FILES=	gtk/IntelRDFPMathLib20U1/LIBRARY/float128/op_system.h gtk/IntelRDFPMathLib20U1/LIBRARY/float128/architecture.h

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing -Wno-constant-conversion # to accommodate some code breaking with clang-50

BUILD_WRKSRC=	${WRKSRC}/gtk

VARIANTS=	bin dec

.for v in ${VARIANTS}
PLIST_FILES+=	bin/${PORTNAME}${v}
.endfor

post-extract:
	@cd ${BUILD_WRKSRC} && tar xvfz ../inteldecimal/IntelRDFPMathLib20U1.tar.gz

post-patch:
	@${REINPLACE_CMD} -e 's|(free42dirname)|("${DATADIR}/skins")|' \
		${BUILD_WRKSRC}/shell_skin.cc

do-build:
.for v in ${VARIANTS}
	@${CP} -r ${BUILD_WRKSRC} ${BUILD_WRKSRC}-${v}
	@cd ${BUILD_WRKSRC}-${v} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} cleaner && \
		${SETENV} ${MAKE_ENV} ${v:S/dec/BCD_MATH=1/:S/bin//} ${MAKE_CMD}
.endfor

do-install:
.for v in ${VARIANTS}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}-${v}/free42${v} ${STAGEDIR}${PREFIX}/bin/
.endfor

.include <bsd.port.mk>
