# New ports collection makefile for:	mod_musicindex
# Date created:				Nov 1 2003
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	mod_musicindex
PORTVERSION=	0.99.7
CATEGORIES=	www audio
# Master site don't have a current version'd tarball...
#MASTER_SITES=	http://www.esiee.fr/~puffin/musicindex/
MASTER_SITES=	http://sheepkiller.nerim.net/
DISTNAME=	libapache-mod-musicindex_${PORTVERSION}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module in C implements Perl module Apache::MP3

LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis \
		id3tag.2:${PORTSDIR}/audio/libid3tag \
		mad.2:${PORTSDIR}/audio/libmad \
		FLAC.5:${PORTSDIR}/audio/flac

CPPFLAGS=	-DHAS_MP3 -DHAS_OGG -DHAS_FLAC
CFLAGS+=	-I${LOCALBASE}/include

#WANT_APACHE=	YES
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/libapache-mod-musicindex-${PORTVERSION}

PORTDOCS=	directory.png musicindex.css fetch.png \
		right_arrow.gif general.png sound.png

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache2/Makefile.modules.3rd"

MAKE_ENV+=	APXS=${APXS} CPPFLAGS="${CPPFLAGS}" LDFLAGS="-L${LOCALBASE}/lib"

.if "${AP_VER}"=="2"
MAKE_ENV+=	APACHE_VERSION=2 APRCONFIG=${LOCALBASE}/lib/apache2/apr-config
.endif

.include <bsd.port.post.mk>
