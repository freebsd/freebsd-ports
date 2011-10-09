# New ports collection makefile for:    JBoss Mail Services
# Date created:		Thu Jan  6 13:39:18 EET 2005
# Whom:			Anton Yudin <toha@toha.org.ua>
#
# $FreeBSD$
#

PORTNAME=	jboss-mailservices
PORTVERSION=	m1
PORTREVISION=	2
CATEGORIES=	mail java
MASTER_SITES=	http://www.jboss.org/wiki/attach?page=MailServicesMilestoneReleases/
DISTNAME=	${PORTNAME}-${PORTVERSION}-final

MAINTAINER=	toha@toha.org.ua
COMMENT=	JBoss Mail Services

DEPRECATED=	Depends on java/jboss4, which is DEPRECATED
EXPIRATION_DATE=	2011-10-31

RUN_DEPENDS=	${LOCALBASE}/jboss4/server/default/conf/jboss-service.xml:${PORTSDIR}/java/jboss4

USE_JAVA=	YES
JAVA_VERSION=	1.5+
NO_BUILD=	YES
USE_ZIP=	YES

DEPLOY_PATH=	${LOCALBASE}/jboss4/server/default/deploy
WRKSRC=		${WRKDIR}/deploy

.include <bsd.port.pre.mk>

do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${INSTALL} -d ${DEPLOY_PATH}/'{}' \; && \
	${FIND} . -type f -exec ${INSTALL_DATA} '{}' ${DEPLOY_PATH}/'{}' \;

post-install:
	@${FIND} -s ${WRKSRC}/mail.ear -not -type d 2>/dev/null | \
		${SED} -ne 's,^${WRKSRC},${DEPLOY_PATH:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${WRKSRC}/mail.ear -type d 2>/dev/null | \
		${SED} -ne 's,^${WRKSRC},@dirrm ${DEPLOY_PATH:S,^${PREFIX}/,,},p' >> ${TMPPLIST}

.include <bsd.port.post.mk>
