# New ports collection makefile for:	spruce
# Version required:   	0.4.8a
# Date created:		05 June 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $Id: Makefile,v 1.5 1999/07/08 05:34:21 cpiazza Exp $
#

DISTNAME=	spruce-0.4.8a
CATEGORIES=	mail
MASTER_SITES=	http://www.xtorshun.org/spruce/

MAINTAINER=	cpiazza@FreeBSD.org

BROKEN='single master site is unreachable'

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG=${X11BASE}/bin/gtk12-config
USE_GMAKE=	yes

.include <bsd.port.mk>
