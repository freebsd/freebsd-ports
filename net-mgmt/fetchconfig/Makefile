PORTNAME=	fetchconfig
DISTVERSION=	0.26
CATEGORIES=	net-mgmt

MAINTAINER=	salexanov@gmail.com
COMMENT=	Perl script for retrieving configuration of various network devices

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-Net-Telnet>=0:net/p5-Net-Telnet
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
SHEBANG_FILES=	${PORTNAME}.pl
USE_GITHUB=	yes
GH_TUPLE=	udhos:fetchconfig:e2c2c4a

NO_BUILD=	yes

MODULES=	model/3ComMSR.pm model/Abstract.pm model/Acme.pm \
	       	model/CiscoASA.pm model/CiscoCAT.pm model/CiscoIOS.pm \
		model/CiscoIOSXR.pm model/CiscoPIX.pm model/CiscoSG300.pm \
		model/Coriant8600.pm model/Dell.pm model/Detector.pm \
		model/DmSwitch.pm model/FortiGate.pm model/JunOS.pm \
		model/Mediant.pm model/MikroTik.pm model/NECUnivergeIX.pm \
	       	model/Parks.pm model/ProCurve.pm model/Riverstone.pm \
		model/TellabsMSR.pm model/Terayon.pm Constants.pm Logger.pm
PORTDOCS=	CHANGES README device_table.example

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}/model
.for f in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/${f} \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}/${f}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
