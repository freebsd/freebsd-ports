# ex:ts=8
# New ports collection makefile for:	moreutils-parallel
# Date created:		2010-12-09
# Whom:			Charlie Kester <corky1951@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	moreutils-parallel
PORTVERSION=	0.43
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	moreutils_${PORTVERSION}

MAINTAINER=	corky1951@comcast.net
COMMENT=	Run programs in parallel

CONFLICTS=	parallel-[0-9]*

ALL_TARGET=	bins
WRKSRC=		${WRKDIR}/moreutils

MAN1=		parallel.1
MANCOMPRESSED=	no
PLIST_FILES=	bin/parallel

post-patch:
	cd ${FILESDIR} && ${CP} ${MAN1} ${WRKSRC}/

post-install:
	cd ${WRKSRC} && ${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
