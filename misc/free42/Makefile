# $FreeBSD$

PORTNAME=	Free42
DISTVERSION=	2.0.7
CATEGORIES=	misc
MASTER_SITES=	http://thomasokken.com/free42/upstream/
DISTNAME=	${PORTNAME:tl}-nologo-${DISTVERSION}

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

BUILD_WRKSRC=	${WRKSRC}/gtk

post-extract:
	@${RM} `${FIND} ${WRKDIR} -name "*.orig"`
	@cd ${BUILD_WRKSRC} && tar xvfz ../inteldecimal/IntelRDFPMathLib20U1.tar.gz

post-patch:
	@${REINPLACE_CMD} -e 's|"%s/%s.%s", free42dirname, name,|"%s/%s.%s", "${DATADIR:tl}", name,|' \
		${BUILD_WRKSRC}/shell_skin.cc

do-build:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} cleaner && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD}
		# TODO do we need decimal fp arithmetic?: ${MAKE_CMD} BCD_MATH=1 SKIN_SYS_DIR="${DATADIR:tl}"

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/free42bin ${STAGEDIR}${PREFIX}/bin/
	@cd ${WRKSRC} && ${COPYTREE_SHARE} skins ${STAGEDIR}${DATADIR:tl}

.include <bsd.port.mk>
