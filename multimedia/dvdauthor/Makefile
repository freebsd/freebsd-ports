# New ports collection makefile for:   dvdauthor
# Date created:        20 April 2003
# Whom:                pb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	dvdauthor
PORTVERSION=	0.6.10
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pb@FreeBSD.org
COMMENT=	Makes a DVD file structure from one or more MPEG2 streams

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison
LIB_DEPENDS=	dvdread.3:${PORTSDIR}/multimedia/libdvdread \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_GETOPT_LONG=yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
MAN1=	dvdauthor.1 spumux.1

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libfreetype.so.9)
WITH_FREETYPE=		yes
.endif
.if exists(${LOCALBASE}/lib/libfridibi.so.0)
WITH_FRIBIDI=		yes
.endif
.if exists(${LOCALBASE}/lib/libiconv.so)
WITH_ICONV=		yes
.endif
.if exists(${LOCALBASE}/lib/libMagick.so.6)
WITH_IMAGEMAGICK=	yes
.endif

.if defined(WITH_FREETYPE)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
.endif
.if defined(WITH_FRIBIDI)
LIB_DEPENDS+=	libfribidi.0:${PORTSDIR}/converters/fribidi
.endif
.if defined(WITH_ICONV)
USE_ICONV=	yes
.endif
.if defined(WITH_IMAGEMAGICK)
LIB_DEPENDS+=	Magick.6:${PORTSDIR}/graphics/ImageMagick
.else
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
.endif

pre-everything::
.if !defined(WITH_FREETYPE)
	@${ECHO_MSG} "You can enable Freetype support by defining WITH_FREETYPE."
	@${ECHO_MSG}
.endif
.if !defined(WITH_FRIBIDI)
	@${ECHO_MSG} "You can enable FriBidi support by defining WITH_FRIBIDI."
	@${ECHO_MSG}
.endif
.if !defined(WITH_ICONV)
	@${ECHO_MSG} "You can enable Iconv support by defining WITH_ICONV."
	@${ECHO_MSG}
.endif
.if !defined(WITH_IMAGEMAGICK)
	@${ECHO_MSG} "You can enable ImageMagick support by defining WITH_IMAGEMAGICK."
	@${ECHO_MSG}
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/dvdauthor
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dvdauthor
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${PREFIX}/share/doc/dvdauthor
	${INSTALL_DATA} ${WRKSRC}/lib.txt ${PREFIX}/share/doc/dvdauthor
	${INSTALL_DATA} ${WRKSRC}/menu.txt ${PREFIX}/share/doc/dvdauthor
	for i in dvdauthor ex-title examples index languages manpages spumux; do \
		${INSTALL_DATA} ${WRKSRC}/doc/$$i.html ${PREFIX}/share/doc/dvdauthor; \
	done
.endif

.include <bsd.port.post.mk>
