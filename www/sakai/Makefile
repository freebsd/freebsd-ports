# Created by: wenheping@gmail.com
# $FreeBSD$

PORTNAME=	sakai
PORTVERSION=	2.7.1
PORTREVISION=	1
CATEGORIES=	www java
MASTER_SITES=	http://source.sakaiproject.org/release/${PORTVERSION}/artifacts/
DISTFILES=	${PORTNAME}-bin-${PORTVERSION}.tgz

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Online Collaboration and Learning Environment

RUN_DEPENDS=	${LOCALBASE}/apache-tomcat-6.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6

USE_JAVA=	yes
JAVA_VERSION=	1.6+

NO_BUILD=	yes
WRKSRC=		${WRKDIR}
SYSTEM_DIR=	common components licenses server shared webapps
TOMCAT_DIR=	${PREFIX}/apache-tomcat-6.0
PLIST_SUB+=	TOMCAT_DIR=${TOMCAT_DIR:S|^${PREFIX}/||} \
	SAKAI_VER="${PORTVERSION}" 

NO_STAGE=	yes
post-extract:
	@cd ${WRKSRC}/webapps && `${LS} -1 |${SED} 's/.war//' >> ${WRKSRC}/list`
	@cd ${WRKSRC}/webapps && ${MKDIR} `${CAT} ${WRKSRC}/list`
	@cd ${WRKSRC}/webapps && for i in `${CAT} ${WRKSRC}/list` ; do ${TAR} xf $$i.war -C $$i ; done
	@${RM} ${WRKSRC}/webapps/*.war

do-install:
.for i in ${SYSTEM_DIR}
	cd ${WRKSRC}/${i} && ${FIND} . -type d \
		-exec ${INSTALL} -d ${TOMCAT_DIR}/${i}/{} \;
	cd ${WRKSRC}/${i} && ${FIND} . -type f \
		-exec ${INSTALL} -m 644 {} ${TOMCAT_DIR}/${i}/{} \;
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
