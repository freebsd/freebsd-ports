# New ports collection makefile for:	fcptools
# Date created:				Sat May 3 03:05:46 UTC 2003
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fcptools
PORTVERSION=	0.4.7
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://freenetproject.org/snapshots/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	FreeNet client library and command-line tools for shell scripting

USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_SIZE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/${PORTNAME:L}
INSTALLS_SHLIB=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}-stable

.include <bsd.port.mk>
