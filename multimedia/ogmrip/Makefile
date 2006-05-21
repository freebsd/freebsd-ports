# New ports collection makefile for:	ogmrip
# Date created:				2004-11-19
# Whom:					Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ogmrip
PORTVERSION=	0.9.0
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Application and libraries for encoding DVDs into DivX/OGM files

BUILD_DEPENDS=	mencoder:${PORTSDIR}/multimedia/mplayer \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		ogmmerge:${PORTSDIR}/multimedia/ogmtools \
		lame:${PORTSDIR}/audio/lame \
		gocr:${PORTSDIR}/graphics/gocr
RUN_DEPENDS=	mencoder:${PORTSDIR}/multimedia/mplayer \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		ogmmerge:${PORTSDIR}/multimedia/ogmtools \
		lame:${PORTSDIR}/audio/lame \
		gocr:${PORTSDIR}/graphics/gocr
LIB_DEPENDS=	xvidcore:${PORTSDIR}/multimedia/xvid \
		dvdread:${PORTSDIR}/multimedia/libdvdread \
		enchant:${PORTSDIR}/textproc/enchant

USE_GNOME=	gtk20 glib20 gconf2 libglade2
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GCONF_SCHEMAS=	ogmrip.schemas

CONFIGURE_ARGS=	--sharedstatedir=${PREFIX}/libdata

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-maintainer-mode --enable-devel-mode
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/mkvmerge)
BUILD_DEPENDS+=	mkvmerge:${PORTSDIR}/multimedia/mkvtoolnix
RUN_DEPENDS+=	mkvmerge:${PORTSDIR}/multimedia/mkvtoolnix
PLIST_SUB+=	MKV_SUPPORT=""
.else
PLIST_SUB+=	MKV_SUPPORT="@comment "
.endif

X264_SUPPORT!=	${LOCALBASE}/bin/mencoder -ovc help 2> /dev/null | ${GREP} -q '^ *x264 *- .*$$' \
	  && ${ECHO_CMD} "" || ${ECHO_CMD} "@comment "
PLIST_SUB+=	X264_SUPPORT="${X264_SUPPORT}"

.if !defined(WITH_DEBUG)
pre-extract:
	@${ECHO_MSG} ""
	@${ECHO_MSG} " *** Define WITH_DEBUG to enable debug symbols ***"
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
	  ${WRKSRC}/data/Makefile.in

pre-configure:
	@if ${LOCALBASE}/mencoder -ovc help 2> /dev/null | ${GREP} -q "^ *xvid *- .*" ; then \
	  ${ECHO_MSG} "" ; \
	  ${ECHO_MSG} "This port requires a version of MEncoder compiled with XviD support." ; \
	  ${ECHO_MSG} "" ; \
	  ${FALSE} ; \
	fi

post-install:
	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} ""

.include <bsd.port.post.mk>
