# Created by: dterry@digifonica.com
# $FreeBSD$

PORTNAME=	sip_scenario
PORTVERSION=	1.2.7
CATEGORIES=	net
MASTER_SITES=	http://www.abptech.com/support/resources/SIP_scen_generator_v1.2.7/index/
DISTNAME=	${PORTNAME}.v${PORTVERSION}

MAINTAINER=	pi@FreeBSD.org
COMMENT=	SIP call flow creator (HTML format)

BROKEN=		unfetchable

LICENSE=	APACHE20

USES=		perl5 zip shebangfix
USE_PERL5=	run

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

# TODO: there are two documents available at
# http://www.abptech.com/support/resources/SIP_scen_generator_v1.2.7/index/SipScenario.pdf
# and
# http://www.abptech.com/support/resources/SIP_scen_generator_v1.2.7/index/SipScenarioPart2.pdf
# download them and install them in /usr/local/share/doc/sip_scenario/

SHEBANG_FILES=	sip_scenario.pl
PLIST_FILES=	bin/sip_scenario.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sip_scenario.pl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
