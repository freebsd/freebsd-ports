# ex:ts=8
# New ports collection makefile for:	bidwatcher
# Date created:		24 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=		bidwatcher
PORTVERSION=		1.3.11
PORTREVISION?=		2
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

PATCH_SITES=		http://sourceforge.net/tracker/download.php?group_id=2973&amp;atid=302973&amp;file_id=63934&amp;aid=820963/
PATCHFILES=		add_auction_by_url_also.patch

MAINTAINER=		mph@FreeBSD.org
COMMENT=		Bid monitor for eBay

USE_GNOME=		gtk12
GNU_CONFIGURE=		YES

MAN1=			bidwatcher.1

CFLAGS+=		-UHAVE_GMTIME

# The software includes a "fudge factor" for the snipe timer; by default
# it snipes 5 minutes (300 seconds) before the time that you tell it to.
# This fudge factor is only used in certain cases where the software
# cannot synchronize its time to eBay (for some reason).  To change the
# "fudge factor" to a different value, set TIMEFUDGE to the desired
# number of seconds.

TIMEFUDGE?=		300
CFLAGS+=		-DHAVE_TM_ZONE -DTIMEFUDGE=${TIMEFUDGE}

.include <bsd.port.mk>
