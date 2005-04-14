## New ports collection makefile for:   KDM theme manager
# Date created:			12 April 2005
# Whom:				illusia <illusia@inbox.lv>
#
# $FreeBSD$
#

PORTNAME=	kdmtheme
PORTVERSION=	0.9
CATEGORIES=	x11-themes
MASTER_SITES=	http://smileaf.org/files/
DISTNAME=	kdmtheme-${PORTVERSION}

MAINTAINER=	illusia@inbox.lv
COMMENT=	KDM Theme Manager

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

USE_KDEBASE_VER=3

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
