# @(#) $Id: Makefile,v 1.3 2008/04/26 04:19:19 leres Exp $ (LBL)
# New ports collection makefile for: hf
# Date created:	24 Apr 2008
# Whom:		leres@ee.lbl.gov
# $FreeBSD$
#

PORTNAME=	hf
PORTVERSION=	1.0a11
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ee.lbl.gov/ \
		ftp://ftp.tux.org/sites/ftp.ee.lbl.gov/ \
		ftp://ftp.xemacs.org/sites/ftp.ee.lbl.gov/ \
		http://ftp.riken.go.jp/pub/net/lbl/

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	Address to hostname filter

CONFLICTS=	comms/hf-0.* security/bro-1.*

PLIST_FILES=	bin/hf

MAN1=		hf.1

HAS_CONFIGURE=	yes

# Only install hf
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hf.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
