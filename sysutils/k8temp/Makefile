# Created by: Thomas Hurst <tom@hur.st>
# $FreeBSD$

PORTNAME=	k8temp
PORTVERSION=	0.4.1
CATEGORIES=	sysutils
MASTER_SITES=	http://hur.st/k8temp/

MAINTAINER=	tom@hur.st
COMMENT=	Athlon 64 and Opteron on-die temperature reader

LICENSE=	MIT

USES=		tar:xz

ONLY_FOR_ARCHS=	i386 amd64

PLIST_FILES=	sbin/k8temp man/man8/k8temp.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/k8temp ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/k8temp.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
