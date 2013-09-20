# Created by: Mantas Kaulakys <stone@tainet.lt>
# $FreeBSD$

PORTNAME=	amavis-stats
PORTVERSION=	0.1.12
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://downloads.topicdesk.com/amavis_stats/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple AMaViS statistics generator based on rrdtool

RUN_DEPENDS=	rrdtool>=0:${PORTSDIR}/databases/rrdtool

USES=		perl5
USE_PERL5=	run
USE_PHP=	pcre

MAN1=		amavis-stats.1

NO_BUILD=	yes

PORTDOCS=	README

WEBOWN?=	www
WEBGRP?=	www

AMAVISUSER?=	amavis
AMAVISGROUP?=	amavis

PKGINSTALL=	${WRKDIR}/INSTALL
PKGDEINSTALL=	${WRKDIR}/DEINSTALL
PKGMESSAGE=	${WRKDIR}/pkg-message

SUB_FILES=	INSTALL DEINSTALL pkg-message
SUB_LIST+=	AMAVISUSER=${AMAVISUSER} AMAVISGROUP=${AMAVISGROUP}

pre-install: apply-slist
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/amavis-stats ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/amavis-stats.1 ${MAN1PREFIX}/man/man1
	${MKDIR} ${PREFIX}/www/amavis-stats
	${MKDIR} ${PREFIX}/www/amavis-stats/img
	${TOUCH} ${PREFIX}/www/amavis-stats/img/.keep
	${INSTALL_DATA} ${WRKSRC}/amavis-stats.php ${PREFIX}/www/amavis-stats
	cd ${PREFIX}/www/amavis-stats && ${LN} -s amavis-stats.php index.php
	${CHOWN} -R ${AMAVISUSER}:${AMAVISGROUP} ${PREFIX}/www/amavis-stats
	${CHOWN} ${WEBOWN}:${WEBGRP} ${PREFIX}/www/amavis-stats/img

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
