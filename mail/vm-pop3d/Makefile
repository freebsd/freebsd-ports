# New ports collection makefile for:	gslin
# Date created:			24 August 2001
# Whom:				Gea-Suan Lin (gslin.am88@nctu.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	vm-pop3d
PORTVERSION=	1.1.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/mail/pop

MAINTAINER=	gslin.am88@nctu.edu.tw

GNU_CONFIGURE=	yes
MAN8=		vm-pop3d.8

post-install:
	${INSTALL_MAN} ${WRKSRC}/vm-pop3d.8 ${MAN8PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/CHANGES ${WRKSRC}/COPYING ${WRKSRC}/FAQ ${WRKSRC}/INSTALL ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
