# New ports collection makefile for:   fakebo
# Date created:        16 March 1999
# Whom:                Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fakebo
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://the.ausmac.net/wd2a/security/port-loggers/ \
		ftp://ftp.mayn.de/pub/unix/security/network/ \
		ftp://webdiis.unizar.es/pub/unix/security/ \
		ftp://ftp.linux.hr/pub/fakebo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fake BackOrifice client emulator

GNU_CONFIGURE=	yes

MAN1=		fakebo.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fakebo ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/fakebo.conf.dist ${PREFIX}/etc/fakebo.conf.sample
	${INSTALL_MAN} ${WRKSRC}/fakebo.1 ${PREFIX}/man/man1/

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/custom.replies ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
