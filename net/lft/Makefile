# New ports collection makefile for:   lft
# Date created:                19 Feb 2003
# Whom:                        Marco P. Rodrigues <drkangel@drkangel.org>
#
# $FreeBSD$
#

PORTNAME=	lft
PORTVERSION=	2.0
CATEGORIES=	net
MASTER_SITES=	http://www.mainnerve.com/lft/ \
		http://www.drkangel.org/sw/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	drkangel@drkangel.org
COMMENT=	Layer 4 Traceroute program

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	Makefile.bsd
MAN8=		lft.8

do-install:
	${INSTALL} -c -s -m 4755 -o root -g wheel ${WRKSRC}/lft ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/lft.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
