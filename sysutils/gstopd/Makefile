# New ports collection makefile for:	gstopd
# Date created:				18 Oct 2003
# Whom:					Michael Reifenberger
#
# $FreeBSD$
#

PORTNAME=	gstopd
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mr

MAINTAINER=	mr@freebsd.org
COMMENT=	GEOM stop daemon

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=         Needs GEOM(4)
.endif

MAN8=		gstopd.8
PLIST_FILES=	sbin/gstopd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gstopd ${LOCALBASE}/sbin
	${INSTALL_MAN} ${WRKSRC}/gstopd.8 ${LOCALBASE}/man/man8

.include <bsd.port.post.mk>
