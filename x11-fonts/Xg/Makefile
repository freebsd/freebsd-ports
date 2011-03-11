# New ports collection makefile for:    libXg
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	libXgFonts
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	x11-fonts plan9
MASTER_SITES=	ftp://ftp.cs.usyd.edu.au/matty/unicode/
DISTNAME=	libXg.utf.fonts

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UNICODE fonts for use with 9term and sam

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

NO_WRKSUBDIR=	yes

.include <bsd.port.mk>
