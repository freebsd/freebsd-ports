# Created by: Thomas Hurst <tom@hur.st>
# $FreeBSD$

PORTNAME=	dupd
PORTVERSION=	1.6
CATEGORIES=	sysutils

MAINTAINER=	tom@hur.st
COMMENT=	File duplicate detection CLI utility

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=	arm armv6 armv7 i386 mips powerpc
NOT_FOR_ARCHS_REASON=	test fails on large files on 32-bit

USES=	gmake perl5 ssl sqlite:3
USE_PERL5=	test

TEST_DEPENDS+=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	jvirkki

ALL_TARGET=	dupd
TEST_TARGET=	test

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
