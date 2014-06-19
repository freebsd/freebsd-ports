# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	dvts
PORTVERSION=	1.0a
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	http://www.sfc.wide.ad.jp/DVTS/software/
DISTNAME=	${PORTNAME}${PORTVERSION}

PATCH_SITES=	http://people.freebsd.org/~simokawa/firewire/
PATCHFILES=	dvts-patch-20030805
PATCH_DIST_STRIP=	-p4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An implementation of Digital Video Transport System

CONFLICTS=	gdvrecv-[0-9]*

USE_AUTOTOOLS=	autoconf

pre-install:
	@${INSTALL_MAN} ${WRKSRC}/dvts.1          ${STAGEDIR}${MANPREFIX}/man/man1/
	@${INSTALL_MAN} ${WRKSRC}/dvsend/dvsend.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	@${INSTALL_MAN} ${WRKSRC}/dvrecv/dvrecv.1 ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
