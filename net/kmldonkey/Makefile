# New ports collection makefile for:	KMLDonkey
# Date created:		Thu Feb 20 22:04:46 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kmldonkey
PORTVERSION=	0.3
CATEGORIES=	net kde
MASTER_SITES=	http://www.gibreel.net/dump/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	KDE integration for MLDonkey eDonkey P2P client

USE_KDELIBS_VER=3
USE_PYTHON=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=''

post-patch:
	@${REINPLACE_CMD} -E -e \
		's|/usr/bin/env python|${LOCALBASE}/bin/python|' \
		${WRKSRC}/scripts/*.py

.include <bsd.port.mk>
