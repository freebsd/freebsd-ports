# New ports collection makefile for:	amavis-stats
# Date created:				12 July 2004
# Whom:					Mantas Kaulakys <stone@tainet.lt>
#
# $FreeBSD$
#

PORTNAME=	amavis-stats
PORTVERSION=	0.1.12
CATEGORIES=	security
MASTER_SITES=	http://rekudos.net/download/

MAINTAINER=	stone@tainet.lt
COMMENT=	A simple AMaViS statistics generator based on rrdtool

RUN_DEPENDS=	${SITE_PERL}/mach/RRDs.pm:${PORTSDIR}/net/rrdtool

USE_PERL5_RUN=	yes
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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		Need at least perl 5.6.1 to build
.endif

pre-install: apply-slist
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

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

.include <bsd.port.post.mk>
