# New ports collection makefile for:	KMLDonkey
# Date created:		Thu Feb 20 22:04:46 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kmldonkey
PORTVERSION=	0.9.1
CATEGORIES=	net kde
MASTER_SITES=	http://savannah.nongnu.org/download/kmldonkey/unstable.pkg/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	KDE integration for MLDonkey eDonkey P2P client

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=''
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
