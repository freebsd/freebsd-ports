# New ports collection makefile for:	oqtplayer
# Date created:				Mon Sep 24 16:26:33 BRT 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	OQTEncoder
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openquicktime
DISTNAME=	${PORTNAME:L}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A simple encoder using OpenQuicktime (TM)

LIB_DEPENDS=	openquicktime.0:${PORTSDIR}/multimedia/openquicktime

USE_SIZE=	yes
MAKE_ENV=	SDL_CONFIG=${SDL_CONFIG}
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
USE_PERL5_BUILD=yes

post-patch:
	@${PERL} -pi -e "s///" ${WRKSRC}/readme

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme ${DOCSDIR}
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME:L} ${PREFIX}/bin

.include <bsd.port.mk>
