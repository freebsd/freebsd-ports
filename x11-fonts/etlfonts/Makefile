# New ports collection makefile for:	etlfonts-noncjk
# Version required:	1.0
# Date created:		3 Nov 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.1.1.1 1997/01/02 19:18:24 max Exp $
#

DISTNAME=	non-cjk
PKGNAME=	etlfonts-noncjk-1.0
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.etl.go.jp/pub/mule/fonts/
EXTRACT_SUFX=	.tar

MAINTAINER=	mita@jp.FreeBSD.org

EXTRACT_ARGS=	-xf
USE_X11=	yes

post-extract:
	@gunzip ${WRKSRC}/*.gz

post-install:
	@/bin/sh ${PKGDIR}/REQ ${PKGNAME} INSTALL

.include <bsd.port.mk>
