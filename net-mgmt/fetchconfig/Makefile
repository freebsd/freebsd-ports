# Created by: salexanov@gmail.com
# $FreeBSD$

PORTNAME=	fetchconfig
PORTVERSION=	0.22
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SAVANNAH

MAINTAINER=	salexanov@gmail.com
COMMENT=	Perl script for retrieving configuration of various network devices

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-Net-Telnet>=0:net/p5-Net-Telnet
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
NO_BUILD=	yes

MODULES=	model/Abstract.pm model/CiscoCAT.pm model/CiscoIOS.pm \
		model/Dell.pm model/Detector.pm model/FortiGate.pm \
		model/Parks.pm model/ProCurve.pm model/Riverstone.pm \
		model/DmSwitch.pm model/Terayon.pm Constants.pm Logger.pm \
		model/3ComMSR.pm model/CiscoASA.pm model/MikroTik.pm \
		model/CiscoPIX.pm model/JunOS.pm model/TellabsMSR.pm
PORTDOCS=	CHANGES README device_table.example

post-patch:
	@${REINPLACE_CMD} -e '1s|.*|#!${PERL} -w|' ${WRKSRC}/${PORTNAME}.pl

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
