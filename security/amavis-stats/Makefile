# Created by: Mantas Kaulakys <stone@tainet.lt>
# $FreeBSD$

PORTNAME=	amavis-stats
PORTVERSION=	0.1.12
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	feld

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Simple AMaViS statistics generator based on rrdtool

RUN_DEPENDS=	rrdtool>=0:${PORTSDIR}/databases/rrdtool

USES=		perl5
USE_PERL5=	run
USE_PHP=	pcre

NO_BUILD=	yes

PORTDOCS=	README

AMAVISUSER?=	amavis
AMAVISGROUP?=	amavis
USERS=	${AMAVISUSER}
GROUPS=	${AMAVISGROUP}
PLIST_SUB+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP} USERS=${USERS} GROUPS=${GROUPS}

PKGMESSAGE=	${WRKDIR}/pkg-message

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/amavis-stats ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/amavis-stats.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/www/amavis-stats
	${MKDIR} ${STAGEDIR}${PREFIX}/www/amavis-stats/img
	${TOUCH} ${STAGEDIR}${PREFIX}/www/amavis-stats/img/.keep
	${INSTALL_DATA} ${WRKSRC}/amavis-stats.php ${STAGEDIR}${PREFIX}/www/amavis-stats
	cd ${STAGEDIR}${PREFIX}/www/amavis-stats && ${LN} -s amavis-stats.php index.php

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
