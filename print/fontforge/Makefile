# New ports collection makefile for:	pfaedit
# Date created:		25 March 2001
# Whom:			KANOU Hiroki <kanou@mil.allnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	pfaedit
PORTVERSION=	20${DIST_VER}
CATEGORIES=	print
MASTER_SITES=	http://pfaedit.sourceforge.net/
DISTFILES=	${EXTRACT_ONLY}
.if !defined(NOPORTDOCS)
DISTFILES+=	${DOCFILE}
.endif

MAINTAINER=	kanou@mil.allnet.ne.jp

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		ungif.5:${PORTSDIR}/graphics/libungif \
		freetype.9:${PORTSDIR}/print/freetype2

USE_GMAKE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.static
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
	CFLAGS="$(CFLAGS) -I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2"
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	pfaedit

MAN1=		pfaedit.1 sfddiff.1

DIST_VER=	021229
EXTRACT_ONLY=	${PORTNAME}_full-${DIST_VER}.tgz cidmaps.tgz

.if !defined(NOPORTDOCS)
DOC_VER=	021229
DOCFILE=	${PORTNAME}_htdocs-${DOC_VER}.tgz
.endif

.if !defined(NOPORTDOCS)
post-extract:
	${MKDIR} ${WRKDIR}/html ${WRKSRC}/cidmap
	${TAR} -xzC ${WRKDIR}/html -f ${DISTDIR}/${DOCFILE}
	${RM} ${WRKDIR}/html/cidmaps.tgz
	${MV} ${WRKDIR}/*.cidmap ${WRKSRC}/cidmap
.endif

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKDIR}/html/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
