# New ports collection makefile for:	xmms-alarm
# Date created:			15 April 2002
# Whom:				Christian Brueffer <chris@unixpages.org>
#
# $FreeBSD$
#

PORTNAME=	xmms-alarm
PORTVERSION=	0.3.2
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.snika.uklinux.net/xmms-alarm/ \
		http://unixpages.org/distfiles/

MAINTAINER=	chris@unixpages.org

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/audio/xmms
RUN_DEPENDS=	xmms-config:${PORTSDIR}/audio/xmms

USE_X_PREFIX=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
