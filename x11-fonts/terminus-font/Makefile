# New ports collection makefile for:	terminus-font
# Date Created:                         04 Nov 2002
# Whom:                                 Michael Hsin <mhsin@mhsin.org>
#
# $FreeBSD$
#

PORTNAME=	terminus-font
PORTVERSION=	4.11
PORTREVISION=	0
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.is-vn.bg/hamster/ \
		http://mr700.cjb.net/pub/fc3/2do/

MAINTAINER=	gugod@gugod.org
COMMENT=	Terminus Font - a clean fixed width font

BUILD_DEPENDS=	mkitalic:${PORTSDIR}/x11-fonts/mkbold-mkitalic \
		bdftopcf:${X_CLIENTS_PORT}
RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

USE_PERL5=      yes
USE_X_PREFIX=	yes
ALL_TARGET=	pcf
SHAREMODE=	644
XFONTDIR=	${PREFIX}/lib/X11/fonts/local

post-build:
	@gzip ${WRKSRC}/*.pcf

do-install:
	@${MKDIR} ${XFONTDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${XFONTDIR}
	@cd ${XFONTDIR}; mkfontdir

.include <bsd.port.mk>
