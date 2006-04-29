# New ports collection makefile for:    totem-gstreamer
# Date created:         04 December 2004
# Whom:                 Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/multimedia/totem-gstreamer/Makefile,v 1.13 2006/03/01 04:32:55 marcus Exp $
#

PORTREVISION=	0
PKGNAMESUFFIX=	-gstreamer

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A Gstreamer-based video player for the Gnome 2 desktop

MASTERDIR=	${.CURDIR}/../totem

OPTIONS=	MOZILLA_PLUGIN "Totem mozilla plugin" off
WITH_GSTREAMER=	yes

CONFLICTS=	totem-[0-9]*

.include "${MASTERDIR}/Makefile"
