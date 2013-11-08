# Created by: Anton Lysenok <bart@tapolsky.net.ua>
# $FreeBSD$

PORTNAME=	clonehdd
PORTVERSION=	2.0.3
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for clone HDD on FreeBSD

USES=		perl5
USE_PERL5=	run
PLIST_FILES=	sbin/clonehdd man/man8/${PORTNAME}.8.gz
NO_BUILD=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/clonehdd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/clonehdd.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
