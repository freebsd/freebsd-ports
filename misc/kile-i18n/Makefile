# New ports collection makefile for:    kile-i18n
# Date created:			Thu Nov 11 22:37:03 CET 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kile-i18n
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES?=	misc kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/-i18n//}

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Localized messages and documentation for Kile

BUILD_DEPENDS=	xgettext:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
