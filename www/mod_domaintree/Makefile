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

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-05-05

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		apache:2.2+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

PORTDOCS=	LICENSE.txt ChangeLog

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
