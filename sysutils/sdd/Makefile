# New ports collection makefile for:	sdd
# Date created:		1999-05-05
# Whom:			Christian Weisgerber <naddy@mips.rhein-neckar.de>
#
# $FreeBSD$
#

PORTNAME=	sdd
PORTVERSION=	1.22
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/sdd/

MAINTAINER=	naddy@mips.inka.de

USE_GMAKE=	yes
MAKE_ENV=	MAKEPROG=gmake CCOM=${CC}
MAN1=		sdd.1

.include <bsd.port.pre.mk>

.if ${ARCH} != i386 || ${CC} != cc
do-configure:
	@${CP} -f ${WRKSRC}/RULES/i386-freebsd-cc.rul \
		${WRKSRC}/RULES/${ARCH}-freebsd-${CC}.rul
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdd/OBJ/${ARCH}-freebsd-${CC}/sdd \
		${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sdd/sdd.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
