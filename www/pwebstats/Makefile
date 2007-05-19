# New ports collection makefile for:    pwebstats
# Date created:         13.07.2003
# Whom:                 HSIN-HSIUNG CHANG <sexbear@tmu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	pwebstats
PORTVERSION=	1.3.8
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.psg.com/pub/pwebstats/

MAINTAINER=	sexbear@tmu.edu.tw
COMMENT=	Analyse a web server log

RUN_DEPENDS=	fly:${PORTSDIR}/graphics/fly

USE_PERL5=	yes

NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/etc/pwebstats/
	${CP} -R ${WRKSRC}/* ${PREFIX}/etc/pwebstats/
	${MV} "${PREFIX}/etc/pwebstats/templates/images/'.gif" ${PREFIX}/etc/pwebstats/templates/images/10.gif
	${MV} "${PREFIX}/etc/pwebstats/templates/images/dates/'.gif" ${PREFIX}/etc/pwebstats/templates/images/dates/10.gif
	${RM} ${PREFIX}/etc/pwebstats/pwebstats.orig
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
