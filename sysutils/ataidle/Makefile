# New ports collection makefile for:	ataidle
# Date created:		2004-01-11
# Whom:			Bruce Cran <bruce@cran.org.uk>
#
# $FreeBSD$
#

PORTNAME=	ataidle
PORTVERSION=	0.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cran.org.uk/bruce/software/

MAINTAINER=	bruce@cran.org.uk
COMMENT=	Utility to set spindown timeout for ATA drives

MAN8=		ataidle.8
DOCS=		COPYING ChangeLog README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ataidle ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ataidle.8 ${MAN8PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 501105
IGNORE=		"requires ATAng, available in 5.1-CURRENT or newer"
.endif

.include <bsd.port.post.mk>
