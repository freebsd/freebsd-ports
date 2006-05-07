# New ports collection makefile for:	mod_domaintree
# Date created:				May 5th 2006
# Whom:					Daniel Gerzo <danger@rulez.sk>
#
# $FreeBSD$
#

PORTNAME=	mod_domaintree
PORTVERSION=	1.4
CATEGORIES=	www
MASTER_SITES=	http://dev.iworks.at/mod_domaintree/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	danger@rulez.sk
COMMENT=	Hostname to filesystem mapper for Apache 2

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_APACHE=	2.0+
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES

PORTDOCS=	LICENSE.txt ChangeLog

post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}

.include <bsd.port.mk>
