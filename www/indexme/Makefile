# New ports collection makefile for:	indexme
# Date created:		30 Jan 2000
# Version required:	0.1
# Whom:			Carl Johan Madestrand
#
# $FreeBSD$
#

DISTNAME=	indexme
PKGNAME=	indexme-0.1
CATEGORIES=	www
MASTER_SITES=	ftp://ukug.uk.freebsd.org/pub/lord_cj/	\
		http://kyb.homepage.com/perl/

MAINTAINER=	calle.madestrand@norrgarden.se

USE_PERL5=	yes

WRKSRC=		${WRKDIR}/indexme
NO_BUILD=	yes

do-install:
		@ ${MKDIR} ${PREFIX}/share/doc/indexme
		@ ${INSTALL_SCRIPT} ${WRKSRC}/indexme ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/indexme
.endif

.include <bsd.port.mk>
