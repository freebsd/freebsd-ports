# Created by: Mikolaj Golub <trociny@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vmtouch
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Virtual Memory Toucher

USE_GITHUB=	yes
GH_ACCOUNT=	hoytech
LICENSE=	BSD3CLAUSE

USES=		perl5 uidfix
USE_PERL5=	build # pod2man

PLIST_FILES=	bin/vmtouch \
		man/man8/vmtouch.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vmtouch ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/vmtouch.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
