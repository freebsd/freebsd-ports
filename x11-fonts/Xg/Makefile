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

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

.include <bsd.port.post.mk>
