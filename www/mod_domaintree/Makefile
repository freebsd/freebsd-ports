# Created by: Daniel Gerzo <danger@rulez.sk>
# $FreeBSD$

PORTNAME=	mod_domaintree
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://dev.iworks.at/mod_domaintree/
EXTRACT_SUFX=	.tgz

MAINTAINER=	danger@FreeBSD.org
COMMENT=	Hostname to filesystem mapper for Apache 2

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_APACHE=	22+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

PORTDOCS=	LICENSE.txt ChangeLog

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
