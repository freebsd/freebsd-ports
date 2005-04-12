# New ports collection makefile for:   latd
# Date created:        19 December 2003
# Whom:                Tillman Hodgson <tillman@seekingfire.com>
#
# $FreeBSD$
#

PORTNAME=	latd
PORTVERSION=	1.21
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	linux-decnet

MAINTAINER=	tillman@seekingfire.com
COMMENT=	The linux-decnet project LAT protocol suite

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		llogin.1
MAN5=		latd.conf.5
MAN8=		latd.8 latcp.8 moprc.8

.include <bsd.port.mk>
