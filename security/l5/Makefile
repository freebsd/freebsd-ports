# New ports collection makefile for:		l6
# Date created:					Sat, 23 Jun 2002
# Whom:						andrew@scoop.co.nz
#
# $FreeBSD$
#

PORTNAME=	l5
PORTVERSION=	1.2
CATEGORIES=	security sysutils
MASTER_SITES=	http://ftp.cerias.purdue.edu/pub/tools/unix/sysutils/l5/
DISTNAME=	L5
EXTRACT_SUFX=	.tgz

MAINTAINER=	andrew@scoop.co.nz
COMMENT=	File Integrity Assessment Tool

NO_WRKSUBDIR=	true
ALL_TARGET=	freebsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PORTNAME}

.include <bsd.port.mk>
