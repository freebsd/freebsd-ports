# New ports collection makefile for:   terminus-font
# Date Created:                         04 Nov 2002
# Whom:                                 Michael Hsin <mhsin@mhsin.org>
#
# $FreeBSD$
#

PORTNAME=	terminus-font
PORTVERSION=	4.20
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.is-vn.bg/hamster/

MAINTAINER=	vlad@vlad.uz.ua
COMMENT=	Terminus Font - a clean fixed width font

BUILD_DEPENDS=	mkitalic:${PORTSDIR}/x11-fonts/mkbold-mkitalic \
		bdftopcf:${X_CLIENTS_PORT}
RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

USE_PERL5=	yes
USE_X_PREFIX=	yes
ALL_TARGET=	pcf
SHAREMODE=	644
FONTDIR=	lib/X11/fonts/${PORTNAME}
PLIST_SUB+=	FONTDIR=${FONTDIR}

post-build:
	@${GZIP_CMD} ${WRKSRC}/*.pcf

do-install:
	@${MKDIR} ${X11BASE}/${FONTDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${X11BASE}/${FONTDIR}

post-install:
	@cd ${X11BASE}/${FONTDIR}; mkfontdir
	@${CP} ${X11BASE}/${FONTDIR}/fonts.dir ${X11BASE}/${FONTDIR}/fonts.scale || true
	@command fc-cache -f -v ${X11BASE}/${FONTDIR} || true

.include <bsd.port.mk>
