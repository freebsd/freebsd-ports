# New ports collection makefile for:    libXg
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	libXgFonts
PORTVERSION=	1.0
CATEGORIES=	x11-fonts plan9
MASTER_SITES=	ftp://ftp.cs.usyd.edu.au/matty/unicode/
DISTNAME=	libXg.utf.fonts

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UNICODE fonts for use with 9term and sam

BUILD_DEPENDS=	bdftopcf:${X_CLIENTS_PORT}
RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

.include <bsd.port.mk>
