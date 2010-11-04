# New ports collection makefile for:	ataidle
# Date created:		2004-01-11
# Whom:			Bruce Cran <bruce@cran.org.uk>
#
# $FreeBSD$
#

PORTNAME=	ataidle
PORTVERSION=	2.5.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cran.org.uk/bruce/software/

MAINTAINER=	bruce@cran.org.uk
COMMENT=	Utility to spin down ATA drives

USE_RC_SUBR=	${PORTNAME}
MAN8=		ataidle.8
PORTDOCS=	COPYING Changelog README
PLIST_FILES=	sbin/ataidle

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ataidle ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ataidle.8 ${MAN8PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
