# New ports collection makefile for:   glpi-plugins-tracker-agent
# Date created:        01 November 2009
# Whom:                ddurieux <d.durieux@siprossii.com>
#
# $FreeBSD$
#

PORTNAME=	agent
DISTVERSION=	1.5.3
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	https://forge.indepnet.net/attachments/download/512/ \
		http://glpi.siprossii.com/distfiles/
PKGNAMEPREFIX=	glpi-plugins-tracker-
DISTNAME=	glpi-tracker_agent-1.5.3

MAINTAINER=	d.durieux@siprossii.com
COMMENT=	Agent get informations of networking devices by SNMP for GLPI

RUN_DEPENDS=	${SITE_PERL}/Net/SNMP.pm:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
		${SITE_PERL}/AppConfig.pm:${PORTSDIR}/devel/p5-AppConfig \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/Parallel/ForkManager.pm:${PORTSDIR}/devel/p5-Parallel-ForkManager

USE_PERL5=	yes
WRKSRC=		${WRKDIR}/agent_tracker
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
CPIOARGS=	--quiet -pdum

TRACKERAGENTDIR?=	share/tracker_agent

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

post-configure:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
	  -e 's,%%TRACKERAGENTDIR%%,${TRACKERAGENTDIR},g' pkg-message > ${PKGMESSAGE}

do-install:
	@${MKDIR} -m 0755 ${PREFIX}/${TRACKERAGENTDIR}
	@cd ${WRKSRC} && ${FIND} * -print | ${CPIO} ${CPIOARGS} ${PREFIX}/${TRACKERAGENTDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
