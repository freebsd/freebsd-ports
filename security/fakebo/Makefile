# New ports collection makefile for:   fakebo
# Date created:        16 March 1999
# Whom:                Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fakebo
PORTVERSION=	0.4.1
CATEGORIES=	security
MASTER_SITES=	ftp://the.ausmac.net/wd2a/security/port-loggers/ \
		ftp://ftp.mayn.de/pub/unix/security/network/ \
		ftp://ftp.cps.unizar.es/pub/unix/security/ \
		ftp://ftp.linux.hr/pub/fakebo/

MAINTAINER=	kris@FreeBSD.org

GNU_CONFIGURE=	yes

MAN1=		fakebo.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fakebo ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/fakebo.conf.dist ${PREFIX}/etc/fakebo.conf.sample
	${INSTALL_MAN} ${WRKSRC}/fakebo.1 ${PREFIX}/man/man1/

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/fakebo/
	${INSTALL_MAN} ${WRKSRC}/custom.replies ${PREFIX}/share/doc/fakebo/
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/fakebo/
.endif

.include <bsd.port.mk>
