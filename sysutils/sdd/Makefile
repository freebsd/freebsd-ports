# New ports collection makefile for:	sdd
# Date created:		1999-05-05
# Whom:			Christian Weisgerber <naddy@mips.rhein-neckar.de>
#
# $FreeBSD$

PORTNAME=	sdd
PORTVERSION=	1.31
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.berlios.de/pub/sdd/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Faster and improved version of dd

USE_GMAKE=	yes
MAKE_ENV=	MAKEPROG="${GMAKE}" CCOM="${CC}" COPTX="${CFLAGS}"
MAN1=		sdd.1

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} != "i386" || ${CC} != "cc"
post-extract:
	@${LN} -sf i386-freebsd-cc.rul \
		${WRKSRC}/RULES/${MACHINE_ARCH}-freebsd-${CC}.rul
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdd/OBJ/${MACHINE_ARCH}-freebsd-${CC}/sdd \
		${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sdd/sdd.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
