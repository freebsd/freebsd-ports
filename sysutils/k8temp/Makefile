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

post-patch:
	@${REINPLACE_CMD} -e 's|WARNS=.*[6-9]|WARNS=5|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/k8temp ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/k8temp.8 ${PREFIX}/man/man8

.include <bsd.port.mk>

WARNS= 6
