# New ports collection makefile for:	qtella
# Date created:				Sunday September 2nd, 2001
# Whom:					Jonathan Belson (jon@witchspace.com)
#
# $FreeBSD$
#

PORTNAME=	qtella
PORTVERSION=	0.7.0
PORTREVISION=	5
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/releases/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Gnutella client using Qt

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		vorbis.4:${PORTSDIR}/audio/libvorbis

USE_KDELIBS_VER=	3
USE_GNOME=	gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ogg-dir=${LOCALBASE} \
		--with-id3-dir=${LOCALBASE}

QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}

.include <bsd.port.mk>
