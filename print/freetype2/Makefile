# New ports collection makefile for:	freetype
# Date created:		January 24, 1998
# Whom:			jseger@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	freetype2
PORTVERSION=	2.1.9
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S,%SUBDIR%,freetype,} \
		http://sunsite.cnlab-switch.ch/ftp/mirror/freetype/%SUBDIR%/ \
		http://www.funet.fi/pub/mirrors/ftp.freetype.org/%SUBDIR%/ \
		http://ftp.sunet.se/pub/text-processing/freetype/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/freetype/&,} \
		ftp://ftp.freetype.org/freetype/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME:S/2//}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A free and portable TrueType font rendering engine

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ENV=	TOP=""
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gnometarget pkgconfig
USE_REINPLACE=	yes
LIBTOOLFILES=	builds/unix/configure
CONFIGURE_ARGS=	--disable-nls
CONFIGURE_WRKSRC=	${WRKSRC}/builds/unix

.if !defined(WITHOUT_TTF_BYTECODE_ENABLED)
CFLAGS+=	-DTT_CONFIG_OPTION_BYTECODE_INTERPRETER
.endif

.if defined(WITH_CJK)
PATCH_SITES+=	ftp://local-distfiles.freebsd.org.cn/pub/china-ports/hamigua/ \
		http://bsdchat.com/dist/firefly-cjk-patchset/
PATCHFILES+=	cjk-freetype-2.1.9-20050315.patch.gz
PATCH_DIST_STRIP+=	-p1
.endif

pre-everything::
.if !defined(WITHOUT_TTF_BYTECODE_ENABLED)
	@${ECHO_MSG}
	@${ECHO_MSG} "You may want not to compile a bytecode interpreter into the"
	@${ECHO_MSG} "TrueType driver. Without this you will only compile the code"
	@${ECHO_MSG} "necessary to load TrueType glyphs without hinting."
	@${ECHO_MSG}
	@${ECHO_MSG} "Hit Ctrl-C now and use \"make WITHOUT_TTF_BYTECODE_ENABLED=yes\""
	@${ECHO_MSG}
	@${ECHO_MSG} "Note that there are important patent issues related to the"
	@${ECHO_MSG} "use of the interpreter."
	@${ECHO_MSG}
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/builds/unix/install.mk

post-configure:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} setup)

.include <bsd.port.mk>
