# New ports collection makefile for:	add
# Version required:			1.0
# Date created:				20 August 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	add
PKGNAME=	add-1.0
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.clark.net/pub/dickey/add/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/add-970526

GNU_CONFIGURE=	yes
MAKEFILE=	makefile
MAN1=		add.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/add ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/add.1 ${PREFIX}/man/man1
	@ ${MKDIR} ${PREFIX}/share/add
	@ ${INSTALL_DATA} ${WRKSRC}/add.hlp ${PREFIX}/share/add
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/add
.for file in CHANGES COPYING README
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/add
.endfor
.endif

.include <bsd.port.mk>
