# New ports collection makefile for:	terminus-font
# Date Created:                         04 Nov 2002
# Whom:                                 Michael Hsin <mhsin@mhsin.org>
#
# $FreeBSD$
#

PORTNAME=	terminus-font
PORTVERSION=	3.96
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.is-vn.bg/hamster/

MAINTAINER=	gugod@gugod.org

USE_X_PREFIX=	yes
ALL_TARGET=	pcf
SHAREMODE=	644
XFONTDIR=	${PREFIX}/lib/X11/fonts/local

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
.endif

post-build:
	@gzip ${WRKSRC}/*.pcf

do-install:
	@${MKDIR} ${XFONTDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${XFONTDIR}

.include <bsd.port.post.mk>
