# New ports collection makefile for:    wingz
# Date created:         Wed Nov 27 09:15:10 CST 1996
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	Wingz
PORTVERSION=	142
PORTREVISION=	2
CATEGORIES=	math linux
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/financial/spreadsheet
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Commercial Spreadsheet

RUN_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libXrender.so.1:${PORTSDIR}/x11/linux-XFree86-libs

ONLY_FOR_ARCHS=	i386

USE_LINUX=	yes
NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
