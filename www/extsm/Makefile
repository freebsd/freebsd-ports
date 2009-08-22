# New ports collection makefile for:	xsm
# Date created:		2006-07-30
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	extsm
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	www java
MASTER_SITES=	SF/rxsm/rxsm/xsm%20${PORTVERSION}
DISTNAME=	xsm_${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Extensible Site Manager (XSM)

RUN_DEPENDS=	${LOCALBASE}/bin/ant:${PORTSDIR}/devel/apache-ant

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

OPTIONS=	TOMCAT4		"Use Jakarta Tomcat 4"		off	\
		TOMCAT41	"Use Jakarta Tomcat 4.1"	off	\
		TOMCAT5		"Use Jakarta Tomcat 5"		on	\
		TOMCAT55	"Use Jakarta Tomcat 5.55"	off	\
		RESIN2		"Use Resin 2"			off	\
		RESIN3		"Use Resin 3"			off

.include <bsd.port.pre.mk>

WEBAPP_DIRS=	#empty
.if defined(WITH_TOMCAT4)
WEBAPP_DIRS+=	jakarta-tomcat4.0
RUN_DEPENDS+=	${PREFIX}/jakarta-tomcat4.0/bin/bootstrap.jar:${PORTSDIR}/www/jakarta-tomcat4
.endif

.if defined(WITH_TOMCAT41)
WEBAPP_DIRS+=	tomcat4.1
RUN_DEPENDS+=	${PREFIX}/tomcat4.1/bin/bootstrap.jar:${PORTSDIR}/www/tomcat41
.endif

.if defined(WITH_TOMCAT5)
WEBAPP_DIRS+=	jakarta-tomcat5.0
RUN_DEPENDS+=	${PREFIX}/jakarta-tomcat5.0/bin/bootstrap.jar:${PORTSDIR}/www/jakarta-tomcat5
.endif

.if defined(WITH_TOMCAT55)
WEBAPP_DIRS+=	tomcat5.5
RUN_DEPENDS+=	${PREFIX}/tomcat5.5/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55
.endif

.if defined(WITH_RESIN2)
WEBAPP_DIRS+=	resin2
RUN_DEPENDS+=	${PREFIX}/resin2/lib/resin.jar:${PORTSDIR}/www/resin2
.endif

.if defined(WITH_RESIN3)
WEBAPP_DIRS+=	resin3
RUN_DEPENDS+=	${PREFIX}/resin3/lib/resin.jar:${PORTSDIR}/www/resin3
.endif

do-install:
.if ${PREFIX}!=${LOCALBASE}
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

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
