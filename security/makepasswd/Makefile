# New ports collection makefile for:	makepasswd
# Date created:				7 March 2003
# Whom:					Toni Viemerö <toni.viemero@iki.fi>
#
# $FreeBSD$
#

PORTNAME=	makepasswd
PORTVERSION=	1.10
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	dists/potato/main/source/admin/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	toni.viemero@iki.fi
COMMENT=	Random password generator

NO_BUILD=	yes
USE_PERL5_RUN=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		makepasswd.1
DOCS=		CHANGES README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/makepasswd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
