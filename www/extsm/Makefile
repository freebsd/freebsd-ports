# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	extsm
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	www java
MASTER_SITES=	SF/rxsm/rxsm/${PORTVERSION}
DISTNAME=	xsm-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible Site Manager (XSM)

RUN_DEPENDS=	mvn:${PORTSDIR}/devel/maven2

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/xsm

OPTIONS_DEFINE=	TOMCAT6 RESIN3 DOCS EXAMPLES
OPTIONS_DEFAULT=	TOMCAT6

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	README INSTALL
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	xsm-demo-config.zip
.endif

WEBAPP_DIRS=	#empty

.if ${PORT_OPTIONS:MTOMCAT6}
WEBAPP_DIRS+=	apache-tomcat-6.0
RUN_DEPENDS+=	${LOCALBASE}/apache-tomcat-6.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
.endif

.if ${PORT_OPTIONS:MRESIN3}
WEBAPP_DIRS+=	resin3
RUN_DEPENDS+=	${LOCALBASE}/resin3/lib/resin.jar:${PORTSDIR}/www/resin3
.endif

.include <bsd.port.pre.mk>
do-install:
.if ${PREFIX} != ${LOCALBASE}
	@${ECHO_CMD} "Warning: you changed prefix to ${PREFIX}"
	@${ECHO_CMD} "Default installation will not work if you installed"
	@${ECHO_CMD} "application server in different prefix"
.endif
.for DIR in ${WEBAPP_DIRS}
	@${ECHO_CMD} "${DIR}/webapps/xsm.war" >> ${TMPPLIST}
.if !exists(${PREFIX}/${DIR}/webapps)
	${MKDIR} ${PREFIX}/${DIR}/webapps
	@${ECHO_CMD} "@unexec rmdir %D/${DIR}/webapps 2>/dev/null || true" >> ${TMPPLIST}
.endif
	${INSTALL_DATA} ${WRKSRC}/xsm.war ${PREFIX}/${DIR}/webapps
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/,} ${EXAMPLESDIR}/
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
