# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	firmware
PORTVERSION=	20140418
CATEGORIES=	science
MASTER_SITES=	#none
PKGNAMEPREFIX=	sigrok-
DISTFILES=	#none

MAINTAINER=	uffe@uffe.org
COMMENT=	Meta package for sigrok firmware packages

RUN_DEPENDS=	parseelf.py:${PORTSDIR}/science/sigrok-firmware-utils \
		${LOCALBASE}/share/sigrok-firmware/fx2lafw-cypress-fx2.fw:${PORTSDIR}/science/sigrok-firmware-fx2lafw

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_MTREE=	yes
NO_INSTALL=	yes

.include <bsd.port.mk>
