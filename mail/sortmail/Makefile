# Ports collection makefile for:  sortmail
# Date created:                   Thu August 21, 2003
# Whom:                           Lasse L. Johnsen (lasse@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	sortmail
PORTVERSION=	1.20
CATEGORIES=	mail
MASTER_SITES=	http://www.freebsdcluster.org/~lasse/software/  \
		${MASTER_SITE_LOCAL}

MAINTAINER=	lasse@freebsdcluster.org
COMMENT=	Useful tool for sorting mbox style mailboxes after date

NO_WRKSUBDIR=	yes
MAN1=		recomposemail.1 decomposemail.1 sortmail.1
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/recomposemail ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/decomposemail ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/sortmail ${PREFIX}/bin

	${INSTALL_MAN} ${WRKSRC}/recomposemail.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/decomposemail.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/sortmail.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
