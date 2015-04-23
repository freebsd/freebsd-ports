# Created by: ddurieux <d.durieux@siprossii.com>
# $FreeBSD$

PORTNAME=	agent
DISTVERSION=	1.5.3
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	https://forge.indepnet.net/attachments/download/512/ \
		http://glpi.siprossii.com/distfiles/
PKGNAMEPREFIX=	glpi-plugins-tracker-
DISTNAME=	glpi-tracker_agent-1.5.3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Agent get informations of networking devices by SNMP for GLPI

RUN_DEPENDS=	p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
		p5-AppConfig>=0:${PORTSDIR}/devel/p5-AppConfig \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-Parallel-ForkManager>=0:${PORTSDIR}/devel/p5-Parallel-ForkManager

DEPRECATED=	superceded by net-mgmt/glpi-plugins-fusioninventory-server
EXPIRATION_DATE=	2015-05-22

USES=		perl5
WRKSRC=		${WRKDIR}/agent_tracker
NO_BUILD=	yes
SUB_FILES=	pkg-message
#PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_LIST=	TRACKERAGENTDIR="${TRACKERAGENTDIR}"
CPIOARGS=	--quiet -pdum

TRACKERAGENTDIR?=	share/tracker_agent

do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${PREFIX}/${TRACKERAGENTDIR}
	@cd ${WRKSRC} && ${FIND} * -print | ${CPIO} ${CPIOARGS} ${STAGEDIR}${PREFIX}/${TRACKERAGENTDIR}

.include <bsd.port.mk>
