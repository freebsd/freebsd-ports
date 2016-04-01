# Created by: Thomas Bartelmess <thomas@bartelmess.io>
# $FreeBSD$

PORTNAME=	graylog-web-interface
PORTVERSION=	1.3.3
CATEGORIES=	www java sysutils
MASTER_SITES=	https://packages.graylog2.org/releases/graylog2-web-interface/ \
		http://packages.graylog2.org/releases/graylog2-web-interface/

MAINTAINER=	thomas@bartelmess.io
COMMENT=	Web Interface for Graylog

LICENSE=	GPLv3+

RUN_DEPENDS=	bash:shells/bash

USES=		tar:tgz
USE_JAVA=	yes

JAVA_EXTRACT=	yes
JAVA_RUN=	yes
NO_BUILD=	yes
NO_ARCH=	yes

USE_RC_SUBR=	graylog_web_interface

GRAYLOGUSER?=	graylog
GRAYLOGGROUP?=	${GRAYLOGUSER}
USERS=		${GRAYLOGUSER}
GROUPS=		${GRAYLOGGROUP}

SUB_FILES=	pkg-message
SUB_LIST=	GRAYLOGUSER=${GRAYLOGUSER} \
		GRAYLOGGROUP=${GRAYLOGGROUP} \
		JAVA_HOME=${JAVA_HOME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/graylog-web-interface
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/graylog-web-interface/lib/ "-name *\.jar")
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/graylog-web-interface/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/graylog-web-interface ${STAGEDIR}${PREFIX}/lib/graylog-web-interface/bin/
	cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s ${PREFIX}/lib/graylog-web-interface/bin/graylog-web-interface graylog-web-interface
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/graylog-web-interface/conf
	${INSTALL_DATA} ${WRKSRC}/conf/application.conf ${STAGEDIR}${PREFIX}/lib/graylog-web-interface/conf
	${INSTALL_DATA} ${WRKSRC}/conf/play.plugins ${STAGEDIR}${PREFIX}/lib/graylog-web-interface/conf
	${INSTALL_DATA} ${WRKSRC}/conf/graylog-web-interface.conf ${STAGEDIR}${PREFIX}/etc/graylog-web-interface.conf.sample
	${INSTALL_DATA} ${FILESDIR}/graylog-web-interface-logging.xml ${STAGEDIR}${PREFIX}/etc/graylog-web-interface-logging.xml.sample
	cd ${STAGEDIR}${PREFIX}/lib/graylog-web-interface/conf && ${LN} -s ${PREFIX}/etc/graylog-web-interface.conf graylog-web-interface.conf

.include <bsd.port.mk>
