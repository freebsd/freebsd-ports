# New ports collection makefile for:   dejasearch
# Version required:    1.1
# Date created:        15 March 1999
# Whom:                Kris Kennaway <kris@FreeBSD.ORG>
#
# $Id: Makefile,v 1.2 1999/03/14 12:33:56 kris Exp $
#

DISTNAME=	dejasearch11
PKGNAME=	dejasearch-1.1
CATEGORIES=	news
MASTER_SITES=	http://homemade.hypermart.net/dejasearch/

MAINTAINER=	kris@FreeBSD.ORG

RUN_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww

WRKSRC=		${WRKDIR}/dejasearch/

USE_PERL5=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dejasearch ${PREFIX}/bin/

.ifndef NOPORTDOCS
	${MKDIR} ${PREFIX}/share/doc/dejasearch/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dejasearch/
.endif

.include <bsd.port.mk>
