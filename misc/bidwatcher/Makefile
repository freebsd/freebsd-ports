# New ports collection makefile for:	bidwatcher
# Date created:		24 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=		bidwatcher
PORTVERSION=		1.3.7
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		mph@FreeBSD.org

USE_GNOMENG=		yes
USE_GNOME=		gtk12
GNU_CONFIGURE=		YES

CFLAGS+=		-UHAVE_GMTIME

# The software includes a "fudge factor" for the snipe timer; by default
# it snipes 5 minutes (300 seconds) before the time that you tell it to.
# To change the "fudge factor" to a different value, set TIMEFUDGE to the
# desired number of seconds.

TIMEFUDGE?=		300
CFLAGS+=		-DHAVE_TM_ZONE -DTIMEFUDGE=${TIMEFUDGE}

.include <bsd.port.mk>
