# New ports collection makefile for:	addons for kde
# Date created:				7 August 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kdeaddons
PORTVERSION=	2.2
CATEGORIES?=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src

MAINTAINER?=	ports@FreeBSD.org

USE_KDEBASE_VER=2
LIB_DEPENDS=	noatun.0:${PORTSDIR}/audio/kdemultimedia2
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
PLIST_SUB+=	RM=${RM}

.include <bsd.port.mk>
