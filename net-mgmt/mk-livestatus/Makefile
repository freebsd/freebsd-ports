# New ports collection makefile for:	mk-livestatus
# Date created:		10 april 2010
# Whom:			Peter C. Lai <cowbert@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mk-livestatus
PORTVERSION=	1.1.3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://mathias-kettner.de/download/

MAINTAINER=	cowbert@gmail.com
COMMENT=	Mathias Kettner's mk-livestatus plugin for nagios

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/mk-livestatus/unixcat lib/mk-livestatus/livestatus.o
PLIST_DIRS=	lib/${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
