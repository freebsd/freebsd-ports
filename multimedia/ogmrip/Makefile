# New ports collection makefile for:	ogmrip
# Date created:				2004-11-19
# Whom:					Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ogmrip
PORTVERSION=	0.6.0
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
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	xvidcore:${PORTSDIR}/multimedia/xvid \
		dvdread:${PORTSDIR}/multimedia/libdvdread \
		enchant:${PORTSDIR}/textproc/enchant

USE_REINPLACE=	yes
USE_GNOME=	gtk20 glib20 libgnomeui gconf2 libgnome libglade2
USE_LIBTOOL_VER=15
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
GCONF_SCHEMAS=	ogmrip.schemas

CONFIGURE_ARGS=	--sharedstatedir=${PREFIX}/libdata

.include <bsd.port.pre.mk>

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
