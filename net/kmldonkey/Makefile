# New ports collection makefile for:	KMLDonkey
# Date created:		Thu Feb 20 22:04:46 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kmldonkey
PORTVERSION=	0.5
CATEGORIES=	net kde
MASTER_SITES=	http://www.gibreel.net/dump/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	KDE integration for MLDonkey eDonkey P2P client

RUN_DEPENDS=	 \
	${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_KDELIBS_VER=3
USE_PYTHON=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=''
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -E -e \
		's|/usr/bin/env python|${LOCALBASE}/bin/python|' \
		${WRKSRC}/scripts/*.py

.include <bsd.port.mk>
