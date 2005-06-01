# New ports collection makefile for:   sip_scenario
# Date created:        26 April 2005
# Whom:                dterry@digifonica.com
#
# $FreeBSD$
#

PORTNAME=	sip_scenario
PORTVERSION=	1.2.7
CATEGORIES=	net
MASTER_SITES=	http://www.iptel.org/~sipsc/index/
DISTNAME=	${PORTNAME}.v${PORTVERSION}

MAINTAINER=	dterry@digifonica.com
COMMENT=	SIP call flow creator (HTML format)

USE_ZIP=	yes
USE_PERL5_RUN=	yes

WRKSRC=		${WRKDIR}

PLIST_FILES=	bin/sip_scenario.pl
NO_BUILD=	yes

do-install:
	${SED} -i -e '1s/local\///' ${WRKSRC}/sip_scenario.pl
	${INSTALL_SCRIPT} ${WRKSRC}/sip_scenario.pl ${PREFIX}/bin

.include <bsd.port.mk>
