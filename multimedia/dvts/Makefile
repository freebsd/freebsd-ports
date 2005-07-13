# New ports collection makefile for:    dvts
# Date created:				2003/05/10
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	dvts
PORTVERSION=	1.0a
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.sfc.wide.ad.jp/DVTS/software/
DISTNAME=	${PORTNAME}${PORTVERSION}

PATCH_SITES=	http://people.freebsd.org/~simokawa/firewire/
PATCHFILES=	dvts-patch-20030805
PATCH_DIST_STRIP=	-p4

MAINTAINER=	simokawa@FreeBSD.org
COMMENT=	An implementation of Digital Video Transport System

USE_AUTOCONF_VER=	253

MAN1=		dvts.1 dvsend.1 dvrecv.1

pre-install:
	@${INSTALL_MAN} ${WRKSRC}/dvts.1          ${MANPREFIX}/man/man1/
	@${INSTALL_MAN} ${WRKSRC}/dvsend/dvsend.1 ${MANPREFIX}/man/man1/
	@${INSTALL_MAN} ${WRKSRC}/dvrecv/dvrecv.1 ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
