# New ports collection makefile for:	fontforge
# Date created:		25 March 2001
# Whom:			KANOU Hiroki <kanou@khdd.net>
#
# $FreeBSD$
#

PORTNAME=	fontforge
PORTVERSION=	20050310
PORTREVISION=	0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fontforge
DISTFILES=	${EXTRACT_ONLY} ${DOCFILE}
EXTRACT_ONLY=	${PORTNAME}_full-${PORTVERSION}.tgz

MAINTAINER=	kanou@khdd.net
COMMENT=	Type 1/TrueType/OpenType/bitmap font editor

LIB_DEPENDS=	uninameslist.0:${PORTSDIR}/textproc/libuninameslist \
		tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		ungif.5:${PORTSDIR}/graphics/libungif \
		freetype.9:${PORTSDIR}/print/freetype2 \
		xml2.5:${PORTSDIR}/textproc/libxml2

DOCFILE=	${PORTNAME}_htdocs-${PORTVERSION}.tgz

USE_GMAKE=	yes
USE_XLIB=	yes
USE_ICONV=	yes
PATCH_STRIP=	-l
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
.if !defined(FONTFORGE_NO_MULTILAYER)
CONFIGURE_ARGS=	--with-multilayer --with-devicetables --without-freetype-src
.else
CONFIGURE_ARGS=	--with-devicetables --without-freetype-src
.endif
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CFLAGS="${CFLAGS} \
		-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 \
		-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/freetype2"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=13

MAN1=		fontforge.1 sfddiff.1

post-extract:
	${MKDIR} ${WRKDIR}/html ${WRKSRC}/cidmap
	${TAR} -xzC ${WRKDIR}/html -f ${DISTDIR}/${DOCFILE}
	${TAR} -xzC ${WRKSRC}/cidmap -f ${WRKDIR}/html/cidmaps.tgz
	${RM} ${WRKDIR}/html/cidmaps.tgz

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKDIR}/html/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
