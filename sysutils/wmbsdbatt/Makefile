# New ports collection Makefile for: 	wmbsdbatt
# Date created:				04 Feb 2004
# Whom:					Josef El-Rayes <josef@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	wmbsdbatt
PORTVERSION=	0.1
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://mailbox.univie.ac.at/~le/wmbsdbatt/files/ \
		http://www.daemon.li/downloads/

MAINTAINER=	josef@FreeBSD.org
COMMENT=	"dockapp for battery & temperature monitoring through ACPI"

USE_XLIB = yes
USE_XPM = yes

PLIST_FILES=	bin/wmbsdbatt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmbsdbatt ${PREFIX}/bin

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		Does not compile on 4.x
.endif

.include <bsd.port.post.mk>
