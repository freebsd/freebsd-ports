# New ports collection makefile for:	xmms-alarm
# Date created:			15 April 2002
# Whom:				Christian Brueffer <chris@unixpages.org>
#
# $FreeBSD$
#

PORTNAME=	xmms-alarm
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.snika.uklinux.net/xmms-alarm/ \
		http://unixpages.org/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alarm timer plugin for the X Multimedia System

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
