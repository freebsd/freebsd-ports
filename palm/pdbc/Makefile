# New ports collection makefile for:	pdbc
# Date created:		28 Jul 2004
# Whom:			Eric P. Scott
#
# $FreeBSD$
#

PORTNAME=	pdbc
PORTVERSION=	0.9.5
CATEGORIES=	palm
MASTER_SITES=	http://trials.palmgear.com/dl2.php/29490.zip/
DISTFILES=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Palm DataBase Compiler/Decompiler

USE_ZIP=	YES
EXTRACT_BEFORE_ARGS=	-q -a
BUILD_WRKSRC=	${WRKSRC}/src
USE_BISON=	YES
USE_GMAKE=	YES
MAKEFILE=	Makefile.unix
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

MAN1=		pdbc.1 pdbdec.1
MAN5=		pdbc.5
PLIST_FILES=	bin/pdbc bin/pdbdec

post-extract:
	${CHMOD} -R u+rw,go-w ${WRKSRC}
	${MV} ${WRKSRC}/man/man4/pdbc.4 ${WRKSRC}/man/man4/pdbc.5
	${MV} ${WRKSRC}/man/man4 ${WRKSRC}/man/man5
	${CHMOD} a-x ${WRKSRC}/src/* ${WRKSRC}/man/man?/*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/pdbc ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/pdbdec ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/pdbc.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/man1/pdbdec.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/man5/pdbc.5 ${MANPREFIX}/man/man5

.include <bsd.port.mk>
