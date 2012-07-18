# @(#) $Id: Makefile,v 1.3 2008/04/26 04:19:19 leres Exp $ (LBL)
# New ports collection makefile for: lbl-hf
# Date created:	24 Apr 2008
# Whom:		leres@ee.lbl.gov
# $FreeBSD$
#

PORTNAME=	hf
PORTVERSION=	1.3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ee.lbl.gov/ \
		ftp://ftp.tux.org/sites/ftp.ee.lbl.gov/ \
		ftp://ftp.xemacs.org/sites/ftp.ee.lbl.gov/ \
		http://ftp.riken.go.jp/pub/net/lbl/
PKGNAMEPREFIX=	lbl-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	Address to hostname filter

MAKE_JOBS_UNSAFE=	yes

CONFLICTS=	hf-[0-9]*

PLIST_FILES=	bin/hf

MAN1=		hf.1

GNU_CONFIGURE=	yes

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.asc

# Only install hf
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hf.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
