# New ports collection makefile for:	KMLDonkey
# Date created:		Thu Feb 20 22:04:46 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kmldonkey
PORTVERSION=	0.10.pre3
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-0.10pre3

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	KDE integration for MLDonkey eDonkey P2P client

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=''
INSTALLS_SHLIB=	yes

MAN1=	kmldonkey.1 kmldonkey_submit.1

.include <bsd.port.mk>
