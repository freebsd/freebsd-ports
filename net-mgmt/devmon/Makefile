# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	devmon
DISTVERSION=	0.3.1-beta1
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Device monitoring addition to Xymon/Hobbit/BigBrother

LICENSE=	GPLv2

RUN_DEPENDS=	p5-SNMP_Session>0:${PORTSDIR}/net-mgmt/p5-SNMP_Session

USE_PERL5=	yes
NO_BUILD=	yes
USE_RC_SUBR=	devmon

USERS=	devmon
GROUPS=	devmon

SUB_LIST=	USERS=${USERS} \
		GROUPS=${GROUPS}

OPTIONS_DEFINE=	MYSQL

REINPLACE_ARGS=	-i ''

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/var/run/devmon.pid|/var/run/devmon/devmon.pid|g' ${WRKSRC}/devmon.cfg ${WRKSRC}/modules/dm_config.pm

pre-install:
	(cd ${WRKSRC} && ${MV} devmon.cfg devmon.cfg.dist)

do-install:
	${INSTALL} -d ${PREFIX}/devmon
	${INSTALL} -d ${PREFIX}/devmon/modules
	${INSTALL_SCRIPT} ${WRKSRC}/devmon ${PREFIX}/devmon/
	${INSTALL_DATA} ${WRKSRC}/devmon.cfg.dist ${PREFIX}/devmon/
	(cd ${WRKSRC}/modules && ${COPYTREE_SHARE} \* ${PREFIX}/devmon/modules/)

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	${INSTALL} -d ${DOCSDIR}/docs
	${INSTALL} -d ${DOCSDIR}/extras
	${INSTALL} -d -o ${USERS} -g ${GROUPS} /var/run/devmon
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* ${DOCSDIR}/docs/)
	(cd ${WRKSRC}/extras && ${COPYTREE_SHARE} \* ${DOCSDIR}/extras/)
.endif

.include <bsd.port.mk>
