# New ports collection makefile for:   lft
# Date created:                19 Feb 2003
# Whom:                        Marco P. Rodrigues <drkangel@drkangel.org>
#
# $FreeBSD$
#

PORTNAME=	lft
PORTVERSION=	2.31
CATEGORIES=	net
MASTER_SITES=	http://www.mainnerve.com/lft/ \
		http://www.drkangel.org/sw/ \
		${MASTER_SITE_GENTOO:S/%SUBDIR%/distfiles/}

MAINTAINER=	drkangel@drkangel.org
COMMENT=	Layer 4 Traceroute program

GNU_CONFIGURE=	yes
MAN8=		lft.8
PLIST_FILES=	sbin/lft

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lft ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/lft.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
