# New ports collection makefile for:	baghira
# Date created:			31 August 2004
# Whom:		 		Miguel Mendez <flynn@energyhq.es.eu.org>
#
# $FreeBSD$
#

PORTNAME=	baghira
PORTVERSION=	0.6
CATEGORIES=	x11-themes kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	flynn@energyhq.es.eu.org
COMMENT=	An Aqua like window decoration and widget style for KDE

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

USE_BZIP2=	yes
USE_KDEBASE_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=15

.include <bsd.port.mk>
