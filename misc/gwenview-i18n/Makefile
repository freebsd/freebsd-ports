# New ports collection makefile for:    gwenview-i18n
# Date created:			Mon Sep 18 02:03:50 CEST 2006
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gwenview-i18n
PORTVERSION=	1.4.2
PORTREVISION=	6
CATEGORIES=	misc kde
MASTER_SITES=	SF/gwenview/gwenview/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Localized messages and documentation for Gwenview

CONFLICTS=	gwenview-0.[0-9]* gwenview-1.[0-3]*

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	build
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
