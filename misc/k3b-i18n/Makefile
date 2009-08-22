# New ports collection makefile for:    k3b-i18n
# Date created:			Tue Mar 16 00:33:35 CET 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	k3b-i18n
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES?=	misc kde
MASTER_SITES=	SF/k3b/${PORTNAME}/${PORTVERSION}

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Localized messages and documentation for K3b

BUILD_DEPENDS=	xgettext:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
