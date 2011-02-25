# New ports collection makefile for:	plugger-plugins-hubbe
# Date created:				11 February 2004
# Whom:					John Merryweather Cooper <coop9211@uidaho.edu>
#
# $FreeBSD$
#

PORTNAME=	plugger-plugins-hubbe
PORTVERSION=	5.0
PORTREVISION=	19
CATEGORIES=	www multimedia audio graphics print editors
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Meta package installing all author-recommended Plugger plugins

RUN_DEPENDS=	sidplay:${PORTSDIR}/audio/sidplay \
		acroread8:${PORTSDIR}/print/acroread8 \
		mpg123:${PORTSDIR}/audio/mpg123 \
		mikmod:${PORTSDIR}/audio/mikmod \
		ogg123:${PORTSDIR}/audio/vorbis-tools \
		xanim:${PORTSDIR}/multimedia/xanim \
		${LOCALBASE}/share/eawpats/acbass.pat:${PORTSDIR}/audio/eawpats \
		xpdf:${PORTSDIR}/graphics/xpdf \
		gqview:${PORTSDIR}/graphics/gqview \
		plugger-controller:${PORTSDIR}/www/plugger \
		gv:${PORTSDIR}/print/gv \
		xmp:${PORTSDIR}/audio/xmp \
		${LOCALBASE}/bin/xscreensaver-hacks/molecule:${PORTSDIR}/x11/xscreensaver-gnome \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		gnumeric:${PORTSDIR}/math/gnumeric \
		abiword:${PORTSDIR}/editors/abiword \
		display:${PORTSDIR}/graphics/ImageMagick

.if exists(${LOCALBASE}/bin/oowrite)
RUN_DEPENDS+=	openoffice-1.1-swriter:${PORTSDIR}/editors/openoffice-1.1
.endif

#
# Missing because not ported to FreeBSD:
#	audio/STsound
#	graphics/p5-gimp-perl
#	www/vrweb
# Missing because HUGE!!
#	openoffice-1.1 (include it only if it already exists)
#

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
