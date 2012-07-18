# @(#) $Id: Makefile,v 1.3 2008/04/26 04:08:44 leres Exp $ (LBL)
# New ports collection makefile for: lbl-cf
# Date created:	24 Apr 2008
# Whom:		leres@ee.lbl.gov
# $FreeBSD$
#

PORTNAME=	cf
PORTVERSION=	1.2.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ee.lbl.gov/ \
		http://www.tux.org//pub/net/ftp.ee.lbl.gov/ \
		http://ftp.riken.go.jp/pub/net/lbl/ \
		http://www.ftpdir.hu/ftp.ee.lbl.gov/
PKGNAMEPREFIX=	lbl-

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	Unix time to formated time and date filter

PLIST_FILES=	bin/cf

MAN1=		cf.1

GNU_CONFIGURE=	yes

post-install:
	(cd ${WRKSRC} && make install-man)

.include <bsd.port.mk>
