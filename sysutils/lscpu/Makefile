# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lscpu
PORTVERSION=	1.0.0
CATEGORIES=	sysutils

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Display information about the CPU architecture

LICENSE=	BSD3CLAUSE

BROKEN_aarch64=		fails to compile: lib/clang/3.8.0/include/cpuid.h:25:2: error: this header is for x86 only
BROKEN_armv6=		fails to compile: lib/clang/5.0.0/include/cpuid.h:25:2: error: this header is for x86 only
BROKEN_armv7=		fails to compile: lib/clang/5.0.0/include/cpuid.h:25:2: error: this header is for x86 only
BROKEN_mips=		fails to compile: lscpu.c:10:19: error: cpuid.h: No such file or directory
BROKEN_mips64=		fails to compile: lscpu.c:10:19: error: cpuid.h: No such file or directory
BROKEN_powerpc=		fails to compile: lscpu.c:10:19: error: cpuid.h: No such file or directory
BROKEN_powerpc64=	fails to compile: lscpu.c:10:19: error: cpuid.h: No such file or directory

USE_GITHUB=	yes
GH_ACCOUNT=	NanXiao

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
