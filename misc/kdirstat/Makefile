# New ports collection makefile for:   kdirstat
# Date created:        22 April 2000
# Whom:                Andrey Novikov <andrey@novikov.com>
#
# $FreeBSD$
#

PORTNAME=		kdirstat
PORTVERSION=    	0.86
CATEGORIES=		misc kde
MASTER_SITES=		http://www.suse.de/~sh/download/ \
			${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/1.1.2/apps/utils
EXTRACT_SUFX=		.tgz

MAINTAINER=	andrey@novikov.com

LIB_DEPENDS=	kdeui.3:${PORTSDIR}/x11/kdelibs11

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT=	yes

.include <bsd.port.mk>
