# New ports collection makefile for:	xsm
# Date created:		2006-07-30
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	extsm
PORTVERSION=	1.1
CATEGORIES=	www java
MASTER_SITES=	SF/rxsm/rxsm/${PORTVERSION}
DISTNAME=	xsm-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Extensible Site Manager (XSM)

RUN_DEPENDS=	maven:${PORTSDIR}/devel/maven

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/xsm

OPTIONS=	TOMCAT6		"Use Tomcat 6"			on	\
		TOMCAT55	"Use Tomcat 5.5"		off	\
		RESIN3		"Use Resin 3"			off

.if !defined(NOPORTDOCS)
PORTDOCS=	README INSTALL
.endif
.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	xsm-demo-config.zip
.endif

.include <bsd.port.pre.mk>

WEBAPP_DIRS=	#empty

.if defined(WITH_TOMCAT6)
WEBAPP_DIRS+=	apache-tomcat-6.0
RUN_DEPENDS+=	${LOCALBASE}/apache-tomcat-6.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
.endif

.if defined(WITH_TOMCAT55)
WEBAPP_DIRS+=	tomcat5.5
RUN_DEPENDS+=	${LOCALBASE}/tomcat5.5/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55
.endif

.if defined(WITH_RESIN3)
WEBAPP_DIRS+=	resin3
RUN_DEPENDS+=	${LOCALBASE}/resin3/lib/resin.jar:${PORTSDIR}/www/resin3
.endif

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
	@${ECHO_CMD} "@dirrm ${DIR}/webapps" >> ${TMPPLIST}
.endif
	${INSTALL_DATA} ${WRKSRC}/xsm.war ${PREFIX}/${DIR}/webapps
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/,} ${EXAMPLESDIR}/
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
