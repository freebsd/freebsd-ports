# New ports collection makefile for:	tcb
# Date created:				1 December 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		tcb
PORTVERSION=		1.4a
PORTREVISION=	1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/file

MAINTAINER=		ports@FreeBSD.org
COMMENT=	File viewer for terminal

USE_GMAKE=		yes

MAN1=			tcb.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/tcb ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/tcb
	@ ${INSTALL_DATA} ${WRKSRC}/tcbrc ${PREFIX}/share/tcb
	@ ${INSTALL_DATA} ${WRKSRC}/doc/HELP ${PREFIX}/share/tcb
	@ ${INSTALL_MAN} ${WRKSRC}/doc/tcb.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/tcb
	@ ${INSTALL_DATA} ${WRKSRC}/doc/CHANGES ${PREFIX}/share/doc/tcb
	@ ${INSTALL_DATA} ${WRKSRC}/doc/COPYING ${PREFIX}/share/doc/tcb
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tcb
.endif

.include <bsd.port.mk>
