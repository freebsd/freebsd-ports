# Created by: MANTANI Nobutaka <nobutaka@nobutaka.com>
# $FreeBSD$

PORTNAME=	libdvdnav
PORTVERSION=	5.0.2
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/libdvdnav/${PORTVERSION}/ \
		http://dvdnav.mplayerhq.hu/releases/ \
		http://contribs.martymac.org/FreeBSD-ports/distfiles/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	MPlayer version of the libdvdnav project

LICENSE=	GPLv2

LIB_DEPENDS=	libdvdread.so:${PORTSDIR}/multimedia/libdvdread

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		tar:bz2 gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS COPYING ChangeLog README TODO

.include <bsd.port.mk>
