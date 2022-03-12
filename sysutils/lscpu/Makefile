# Created by: Ryan Steinmetz <zi@FreeBSD.org>

PORTNAME=	lscpu
PORTVERSION=	1.2.0
CATEGORIES=	sysutils

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Display information about the CPU architecture

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=	amd64 i386 powerpc64le powerpc64 powerpc riscv64

USE_GITHUB=	yes
GH_ACCOUNT=	NanXiao

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
