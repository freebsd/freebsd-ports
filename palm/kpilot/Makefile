# New ports collection makefile for:   kpilot
# Date created:        09 April 1998
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kpilot
PORTVERSION=	3.0.2
CATEGORIES=	palm comms kde
MASTER_SITES=	http://www.slac.com/pilone/kpilot_home/download/

MAINTAINER=	dima@freebsd.org

USE_KDELIBS_VER=1
KDEDIR?=	$(PREFIX)
USE_LIBTOOL=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	KDEDIR="${KDEDIR}"

MAKE_ENV=	KDEDIR="${KDEDIR}"

.include <bsd.port.mk>
