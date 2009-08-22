# New ports collection makefile for:	freetype
# Date created:		January 24, 1998
# Whom:			jseger@FreeBSD.org
#
# $FreeBSD$
#   $MCom: ports/print/freetype2/Makefile,v 1.16 2009/04/09 03:24:09 mezz Exp $
#

PORTNAME=	freetype2
PORTVERSION=	2.3.9
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	SF/freetype/${PORTNAME}/${PORTVERSION} \
		http://sunsite.cnlab-switch.ch/ftp/mirror/freetype/freetype2/ \
		http://www.funet.fi/pub/mirrors/ftp.freetype.org/freetype2/ \
		http://ftp.sunet.se/pub/text-processing/freetype/freetype2/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/freetype/&,} \
		ftp://ftp.freetype.org/freetype/freetype2/
DISTNAME=	${PORTNAME:S/2//}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A free and portable TrueType font rendering engine

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
MAKE_ENV=	TOP=""
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget pkgconfig
LIBTOOLFILES=	builds/unix/configure
CONFIGURE_ARGS=	--disable-nls
CONFIGURE_WRKSRC=	${WRKSRC}/builds/unix

.if defined(WITH_LCD_FILTERING)
CFLAGS+=	-DFT_CONFIG_OPTION_SUBPIXEL_RENDERING
.endif

.if defined(WITH_CJK)
#PATCH_SITES+=	http://lwj-hinet.myweb.hinet.net/ \
#		ftp://local-distfiles.freebsd.org.cn/pub/china-ports/hamigua/ \
#		http://bsdchat.com/dist/firefly-cjk-patchset/
#PATCHFILES+=	cjk-freetype-2.1.10-20051219.patch.gz
#PATCH_DIST_STRIP+=	-p1
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
.if !defined(WITH_LCD_FILTERING)
	@${ECHO_MSG}
	@${ECHO_MSG} "You may want to enable LCD filtering."
	@${ECHO_MSG}
	@${ECHO_MSG} "Hit Ctrl-C now and use \"make WITH_LCD_FILTERING=yes\""
	@${ECHO_MSG}
	@${ECHO_MSG} "Note that there are possible patent issues related to the"
	@${ECHO_MSG} "use of the LCD filtering technology."
	@${ECHO_MSG}
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/builds/unix/install.mk
.if !defined(WITHOUT_TTF_BYTECODE_ENABLED)
	@${REINPLACE_CMD} -e '/#define TT_CONFIG_OPTION_BYTECODE_INTERPRETER/s,/\* \(.*\) \*/,\1,; /#define TT_CONFIG_OPTION_UNPATENTED_HINTING/s,^\(.*\),/* \1 \*/,' \
		${WRKSRC}/include/freetype/config/ftoption.h
.endif

post-configure:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} setup)

.include <bsd.port.mk>
