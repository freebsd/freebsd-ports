# New ports collection makefile for:	whereintheworld
# Date created:		13 august 2003
# Whom:			anarcat
#
# $FreeBSD$
#

PORTNAME=	worldtools
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://anarcat.ath.cx/software/distfiles/

MAINTAINER=	anarcat@anarcat.ath.cx
COMMENT=	Handy tools for living with make world

USE_PERL5_RUN=	yes

NO_BUILD=	yes

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/whereintheworld ${PREFIX}/sbin
		${INSTALL_SCRIPT} ${WRKSRC}/upgrade ${PREFIX}/sbin
		${INSTALL_SCRIPT} ${WRKSRC}/buildit ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
		@${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
