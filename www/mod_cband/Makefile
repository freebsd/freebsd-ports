# New ports collection makefile for:	mod_cband
# Date created:				Sep 7 2005
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_cband
PORTVERSION=	0.9.7.3
CATEGORIES=	www
MASTER_SITES=	http://cband.linux.pl/download/
DISTNAME=	${PORTNAME:C/_/-/}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	A per-virtualhost bandwidth limiter module for Apache 2

USE_APACHE=	20+
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-apxs=${APXS}
ALL_TARGET=	#
PORTDOCS=	libpatricia.copyright

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/libpatricia.copyright ${DOCSDIR}

.include <bsd.port.mk>
