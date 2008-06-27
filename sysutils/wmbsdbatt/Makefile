# New ports collection Makefile for: 	wmbsdbatt
# Date created:				04 Feb 2004
# Whom:					Josef El-Rayes <josef@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	wmbsdbatt
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://homepage.univie.ac.at/l.ertl/wmbsdbatt/files/

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Dockapp for battery & temperature monitoring through ACPI

USE_XORG=	x11 xpm

PLIST_FILES=	bin/wmbsdbatt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmbsdbatt ${PREFIX}/bin

.include <bsd.port.mk>
