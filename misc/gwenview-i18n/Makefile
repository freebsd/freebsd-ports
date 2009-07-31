# New ports collection makefile for:    gwenview-i18n
# Date created:			Mon Sep 18 02:03:50 CEST 2006
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gwenview-i18n
PORTVERSION=	1.4.2
PORTREVISION=	2
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/-i18n//}

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Localized messages and documentation for Gwenview

BUILD_DEPENDS=	xgettext:${PORTSDIR}/devel/gettext

CONFLICTS=	gwenview-0.[0-9]* gwenview-1.[0-3]*

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
