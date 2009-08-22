# New ports collection makefile for:  	bbdate
# Date created:		May 3 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bbdate
PORTVERSION=	0.2.4
PORTREVISION=	2
CATEGORIES=	x11-clocks
MASTER_SITES=	SF/bbtools/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool made for Blackbox that displays the date in a decorated window

GNU_CONFIGURE=	yes
USE_XORG=	x11 xau xdmcp xext xfixes xi xrandr ice sm

PLIST_FILES=	bin/bbdate share/bbtools/README.bbdate \
		share/bbtools/bbdate.conf share/bbtools/bbdate.nobb \
		share/bbtools/bbdate.style share/bbtools/bbtoolsrc.in

post-install:
	@${ECHO_CMD} "@unexec rmdir %D/share/bbtools 2>/dev/null || true" \
		>> ${TMPPLIST}

.include <bsd.port.mk>
