PORTNAME=	k8temp
PORTVERSION=	0.4.1
CATEGORIES=	sysutils
MASTER_SITES=	http://hur.st/k8temp/

MAINTAINER=	tom@hur.st
COMMENT=	Athlon 64 and Opteron on-die temperature reader

LICENSE=	MIT

ONLY_FOR_ARCHS=	amd64 i386

USES=		tar:xz

PLIST_FILES=	sbin/k8temp man/man8/k8temp.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/k8temp ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/k8temp.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
