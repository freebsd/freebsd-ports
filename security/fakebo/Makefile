# New ports collection makefile for:   fakebo
# Version required:    0.3.3
# Date created:        16 March 1999
# Whom:                Kris Kennaway <kris@FreeBSD.ORG>
#
# $FreeBSD$
#

DISTNAME=	fakebo
PKGNAME=	fakebo-0.3.3
CATEGORIES=	security
MASTER_SITES=	http://yi.com/home/KosturjakVlatko/ \
		ftp://ftp.c-com.net/pub/.10/LinuxBerg/files/console/ \
		ftp://ftp.bitcon.no/.10/linux/linuxberg/files/console/ \
		ftp://ftp.ist.utl.pt/pub/linuxberg/files/console/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kris@FreeBSD.ORG

WRKSRC=		${WRKDIR}/${PKGNAME}

MAN1=		fakebo.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fakebo ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/fakebo.conf ${PREFIX}/etc/
	${INSTALL_MAN} ${WRKSRC}/fakebo.1 ${PREFIX}/man/man1/

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/fakebo/
	${INSTALL_MAN} ${WRKSRC}/custom.replies ${PREFIX}/share/doc/fakebo/
.endif

.include <bsd.port.mk>
