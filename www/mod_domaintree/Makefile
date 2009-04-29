# New ports collection makefile for:	mod_domaintree
# Date created:				May 5th 2006
# Whom:					Daniel Gerzo <danger@rulez.sk>
#
# $FreeBSD$
#

PORTNAME=	mod_domaintree
PORTVERSION=	1.6
CATEGORIES=	www
MASTER_SITES=	http://dev.iworks.at/mod_domaintree/
EXTRACT_SUFX=	.tgz

MAINTAINER=	danger@FreeBSD.org
COMMENT=	Hostname to filesystem mapper for Apache 2

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_APACHE=	2.0+
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES

PORTDOCS=	LICENSE.txt ChangeLog

PLIST_FILES=	share/doc/mod_domaintree/LICENSE.txt \
		share/doc/mod_domaintree/ChangeLog
PLIST_DIRS=	share/doc/mod_domaintree

post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}

.include <bsd.port.mk>
