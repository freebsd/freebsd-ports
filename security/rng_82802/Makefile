# New ports collection makefile for:	rng_82802
# Date created:	   15 November 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	rng_82802
PORTVERSION=	0.0.0
CATEGORIES=	security
MASTER_SITES=	http://www.millions.ca/~stacy/
DISTNAME=	rng0-0-0
EXTRACT_SUFX=	.tgz

MAINTAINER=	skv@FreeBSD.org
COMMENT=	RNG driver for the Intel 82802

ONLY_FOR_ARCHS=	i386
NO_PACKAGE=	"Depends on kernel"
PLIST_SUB=	KMODDIR=${KMODDIR}

WRKSRC=		${WRKDIR}/rng/modules/rng

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

post-deinstall:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-DEINSTALL

.include <bsd.port.pre.mk>

PKGDEINSTALL=	${PKGINSTALL}

.include <bsd.port.post.mk>
