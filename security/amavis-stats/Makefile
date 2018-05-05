# Created by: Mantas Kaulakys <stone@tainet.lt>
# $FreeBSD$

PORTNAME=	amavis-stats
PORTVERSION=	0.1.12
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	LOCAL/feld

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Simple AMaViS statistics generator based on rrdtool

RUN_DEPENDS=	rrdtool>=0:databases/rrdtool

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	amavis-stats
perl_CMD=	${PERL} -w
USE_PHP=	pcre

NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	README

AMAVISUSER?=	amavis
AMAVISGROUP?=	amavis
USERS=		${AMAVISUSER}
GROUPS=		${AMAVISGROUP}
PLIST_SUB+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP} USERS=${USERS} GROUPS=${GROUPS}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/amavis-stats ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/amavis-stats.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/www/amavis-stats
	${MKDIR} ${STAGEDIR}${PREFIX}/www/amavis-stats/img
	${TOUCH} ${STAGEDIR}${PREFIX}/www/amavis-stats/img/.keep
	${INSTALL_DATA} ${WRKSRC}/amavis-stats.php ${STAGEDIR}${PREFIX}/www/amavis-stats
	cd ${STAGEDIR}${PREFIX}/www/amavis-stats && ${LN} -s amavis-stats.php index.php

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
