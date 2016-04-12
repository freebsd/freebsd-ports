# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	devmon
DISTVERSION=	0.3.1-beta1
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Device monitoring addition to Xymon/Hobbit/BigBrother

LICENSE=	GPLv2

RUN_DEPENDS=	p5-SNMP_Session>0:net-mgmt/p5-SNMP_Session

USES=	perl5 shebangfix
SHEBANG_FILES=	devmon
NO_BUILD=	yes
USE_RC_SUBR=	devmon

USERS=	devmon
GROUPS=	devmon

SUB_LIST=	USERS=${USERS} \
		GROUPS=${GROUPS}

OPTIONS_DEFINE=	MYSQL DOCS

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
	${INSTALL} -d ${STAGEDIR}/${PREFIX}/devmon
	${INSTALL} -d ${STAGEDIR}/${PREFIX}/devmon/modules
	${INSTALL_SCRIPT} ${WRKSRC}/devmon ${STAGEDIR}/${PREFIX}/devmon/
	${INSTALL_DATA} ${WRKSRC}/devmon.cfg.dist ${STAGEDIR}/${PREFIX}/devmon/
	(cd ${WRKSRC}/modules && ${COPYTREE_SHARE} \* ${STAGEDIR}/${PREFIX}/devmon/modules/)

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${STAGEDIR}/${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}/${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}/${DOCSDIR}/
	${INSTALL} -d ${STAGEDIR}/${DOCSDIR}/docs
	${INSTALL} -d ${STAGEDIR}/${DOCSDIR}/extras
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DOCSDIR}/docs/)
	(cd ${WRKSRC}/extras && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DOCSDIR}/extras/)
.endif

.include <bsd.port.mk>
