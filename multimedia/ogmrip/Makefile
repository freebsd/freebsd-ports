# New ports collection makefile for:	ogmrip
# Date created:				2004-11-19
# Whom:					Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ogmrip
DISTVERSION=	0.10.0-rc4
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Application and libraries for encoding DVDs into DivX/OGM files

BUILD_DEPENDS=	mencoder:${PORTSDIR}/multimedia/mplayer \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		ogmmerge:${PORTSDIR}/multimedia/ogmtools \
		lame:${PORTSDIR}/audio/lame \
		gocr:${PORTSDIR}/graphics/gocr \
		gsed:${PORTSDIR}/textproc/gsed
RUN_DEPENDS=	mencoder:${PORTSDIR}/multimedia/mplayer \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		ogmmerge:${PORTSDIR}/multimedia/ogmtools \
		lame:${PORTSDIR}/audio/lame \
		gocr:${PORTSDIR}/graphics/gocr
LIB_DEPENDS=	xvidcore:${PORTSDIR}/multimedia/xvid \
		dvdread:${PORTSDIR}/multimedia/libdvdread \
		theora:${PORTSDIR}/multimedia/libtheora \
		enchant:${PORTSDIR}/textproc/enchant

USE_LDCONFIG=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnomeprefix gtk20 glib20 gconf2 libglade2 intlhack
GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
GCONF_SCHEMAS=	ogmrip.schemas

CONFIGURE_ARGS=	--sharedstatedir=${PREFIX}/libdata
GMAKE_ENV+=	GMSGFMT=${localbase}/bin/msgfmt

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
