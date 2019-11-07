# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bbdate
PORTVERSION=	0.2.4
PORTREVISION=	3
CATEGORIES=	x11-clocks
MASTER_SITES=	SF/bbtools/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool made for Blackbox that displays the date in a decorated window

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		xorg
USE_XORG=	x11 xau xdmcp xext xfixes xi xrandr ice sm

PLIST_FILES=	bin/bbdate share/bbtools/README.bbdate \
		share/bbtools/bbdate.conf share/bbtools/bbdate.nobb \
		share/bbtools/bbdate.style share/bbtools/bbtoolsrc.in

.include <bsd.port.mk>
