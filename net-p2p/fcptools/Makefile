# New ports collection makefile for:	fcptools
# Date created:				Sat May 3 03:05:46 UTC 2003
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fcptools
PORTVERSION=	0.4.7.${RELEASE_DATE}
CATEGORIES=	net-p2p security
MASTER_SITES=	http://freenetproject.org/snapshots/
DISTNAME=	${PORTNAME}-${RELEASE_DATE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeNet client library and command-line tools for shell scripting

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/${PORTNAME:L}

RELEASE_DATE=	20041108

post-install:
	@${INSTALL_DATA} ${WRKSRC}/ezFCPlib/libezfcp.a ${PREFIX}/lib

.include <bsd.port.mk>
