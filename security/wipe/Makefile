# New ports collection makefile for:	wipe
# Date created:				04 February 2005
# Whom:					Edson Brandi <ebrandi@fugspbr.org>
#
# $FreeBSD$
#

PORTNAME=	wipe
PORTVERSION=	2.3.0
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	File and block device wiping utility

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

MAN1=		wipe.1
PORTDOCS=	CHANGES INSTALL LICENSE README TESTING TODO copyright

post-install:
	${INSTALL_MAN} ${WRKSRC}/wipe.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/wipe
	for i in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>
