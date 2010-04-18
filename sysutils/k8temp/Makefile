# New ports collection makefile for:    k8temp
# Date created:        21 October 2007
# Whom:                Thomas Hurst <tom@hur.st>
#
# $FreeBSD$
#

PORTNAME=	k8temp
PORTVERSION=	0.4.0
CATEGORIES=	sysutils
MASTER_SITES=	http://hur.st/k8temp/

MAINTAINER=	tom@hur.st
COMMENT=	Athlon 64 and Opteron on-die temperature reader

ONLY_FOR_ARCHS=	i386 amd64

MAN8=	k8temp.8

PLIST_FILES=	sbin/k8temp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/k8temp ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/k8temp.8 ${PREFIX}/man/man8

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
