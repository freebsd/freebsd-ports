# New ports collection makefile for:	pfaedit
# Date created:		25 March 2001
# Whom:			KANOU Hiroki <kanou@khdd.net>
#
# $FreeBSD$
#

PORTNAME=	pfaedit
PORTVERSION=	20${DIST_VER}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR =	pfaedit
DISTFILES=	${EXTRACT_ONLY} ${DOCFILES}

MAINTAINER=	kanou@khdd.net
COMMENT=	Type 1/TrueType/OpenType/bitmap font editor

LIB_DEPENDS=	uninameslist.0:${PORTSDIR}/textproc/libuninameslist \
		tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		ungif.5:${PORTSDIR}/graphics/libungif \
		freetype.9:${PORTSDIR}/print/freetype2 \
		xml2:${PORTSDIR}/textproc/libxml2
BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf253

EXTRACT_ONLY=	${PORTNAME}_full-${DIST_VER}.tgz
DOCFILE=	${PORTNAME}_htdocs-${DIST_VER}.tgz
DIST_VER=	031210

USE_GMAKE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 -L${LOCALBASE}/lib"
WRKSRC=		${WRKDIR}/${PORTNAME}-${DIST_VER}

MAN1=		pfaedit.1 sfddiff.1

post-extract:
	${MKDIR} ${WRKDIR}/html ${WRKSRC}/cidmap
	${TAR} -xzC ${WRKDIR}/html -f ${DISTDIR}/${DOCFILE}
	${TAR} -xzC ${WRKSRC}/cidmap -f ${WRKDIR}/html/cidmaps.tgz
	${RM} ${WRKDIR}/html/cidmaps.tgz

# configure is not executed automatically by defining 'USE_AUTOCONF_VER=253'.
pre-configure:
	(cd ${WRKSRC} ; autoconf)

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKDIR}/html/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
