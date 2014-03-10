# Created by: dterry@digifonica.com
# $FreeBSD$

PORTNAME=	sip_scenario
PORTVERSION=	1.2.7
CATEGORIES=	net
MASTER_SITES=	http://www.abptech.com/support/resources/SIP_scen_generator_v1.2.7/index/
DISTNAME=	${PORTNAME}.v${PORTVERSION}

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	SIP call flow creator (HTML format)

LICENSE=	APACHE20

USES=		perl5 zip
USE_PERL5=	run

WRKSRC=		${WRKDIR}

# TODO: there are two documents available at
# http://www.abptech.com/support/resources/SIP_scen_generator_v1.2.7/index/SipScenario.pdf
# and
# http://www.abptech.com/support/resources/SIP_scen_generator_v1.2.7/index/SipScenarioPart2.pdf
# download them and install them in /usr/local/share/doc/sip_scenario/

PLIST_FILES=	bin/sip_scenario.pl
NO_BUILD=	yes

NO_STAGE=	yes
do-install:
	${SED} -i -e '1s/local\///' ${WRKSRC}/sip_scenario.pl
	${INSTALL_SCRIPT} ${WRKSRC}/sip_scenario.pl ${PREFIX}/bin

.include <bsd.port.mk>
