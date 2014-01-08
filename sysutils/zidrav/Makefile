# Created by: Cosmin Stroe <cstroe1@uic.edu>
# $FreeBSD$

PORTNAME=	zidrav
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}4unix/${PORTVERSION}
DISTNAME=	zidrav4unix-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A file corruption detection and repair program

LICENSE=	GPLv2

ALL_TARGET=	zidrav
PLIST_FILES=	bin/zidrav man/man1/zidrav.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zidrav ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/zidrav.1 ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
CFLAGS+=	-Dcrc32_type=long
.else
CFLAGS+=	-Dcrc32_type=int
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "arm" || ${ARCH} == "i386" || ${ARCH} == "ia64"
.else
# mips*eb, powerpc, powerpc64 and sparc
CFLAGS+=	-DCPU_BIGENDIAN
.endif

.include <bsd.port.mk>
