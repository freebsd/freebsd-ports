# New ports collection makefile for:	gyach
# Date created:				08 November 2003
# Whom:					Aaron Landwehr <aaron@snaphat.com>
#
# $FreeBSD$
#

PORTNAME=	gyach
PORTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.snaphat.com/pub/software/
DISTNAME=	${PORTNAME}-${PORTVERSION}_patched

MAINTAINER?=	aaron@snaphat.com
COMMENT=	Gyach is a GTK+ based Yahoo! Chat client

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
USE_X_PREFIX=	yes

.include <bsd.port.mk>
