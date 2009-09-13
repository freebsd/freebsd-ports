# New ports collection makefile for:	fetchconfig
# Date created:				21 December 2008
# Whom:					salexanov@gmail.com
#
# $FreeBSD$
#

PORTNAME=	fetchconfig
PORTVERSION=	0.17
CATEGORIES=	net-mgmt
MASTER_SITES=	SAVANNAH

MAINTAINER=	salexanov@gmail.com
COMMENT=	Perl script for retrieving configuration of various network devices

BUILD_DEPENDS=	${SITE_PERL}/Net/Telnet.pm:${PORTSDIR}/net/p5-Net-Telnet
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
NO_BUILD=	yes

MODULES=	model/Abstract.pm model/CiscoCAT.pm model/CiscoIOS.pm \
		model/Dell.pm model/Detector.pm model/FortiGate.pm \
		model/Parks.pm model/ProCurve.pm model/Riverstone.pm \
		model/DmSwitch.pm model/Terayon.pm Constants.pm Logger.pm
PORTDOCS=	CHANGES README device_table.example

post-patch:
	@${REINPLACE_CMD} -e '1s|.*|#!${PERL} -w|' ${WRKSRC}/${PORTNAME}.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${SITE_PERL}/${PORTNAME}/model
.for f in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/${f} ${SITE_PERL}/${PORTNAME}/${f}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
