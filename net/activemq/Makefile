# New ports collection makefile for:	activemq
# Date created:		2010-02-07
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	activemq
PORTVERSION=	5.3.2
PORTREVISION=	1
CATEGORIES=	net java
MASTER_SITES=	http://www.sai.msu.su/apache/${MASTER_SITE_SUBDIR}/ \
		${MASTER_SITE_APACHE}/${MASTER_SITE_SUBDIR}/
MASTER_SITE_SUBDIR=${PORTNAME}/apache-${PORTNAME}/${PORTVERSION}
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Messaging and Integration Patterns provider

NO_BUILD=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.5+
MQDATA=		${PREFIX}/lib/${PORTNAME}
MQDB=		${PREFIX}/${PORTNAME}
DATADIR=	${MQDATA}
MQUSER=		activemq
MQGROUP=	${MQUSER}

ALL_TARGET=	${PORTNAME}
USE_RC_SUBR=	${PORTNAME}

PORTDOCS=	LICENSE NOTICE README.txt WebConsole-README.txt user-guide.html

WRKSRC=		${WRKDIR}/apache-${PORTNAME}-${PORTVERSION}

do-install:
.for f in linux-x86-32 linux-x86-64 macosx
	@${RM} -fr ${WRKSRC}/bin/${f}
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${DOCSDIR}/
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

post-install:
	@${MKDIR} ${MQDATA} ${MQDB} ${MQDATA}/bin ${ETCDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} example ${EXAMPLESDIR}/
	@cd ${WRKSRC}/conf && ${INSTALL_DATA} * ${ETCDIR}/

.for f in ${PORTNAME} ${PORTNAME}-admin
	@cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} ${f} ${MQDATA}/bin
.endfor
.for f in run.jar wrapper.jar
	@cd ${WRKSRC}/bin && ${INSTALL_DATA} ${f} ${MQDATA}/bin
.endfor
.for f in webapps lib
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${MQDATA}
.endfor

	@${LN} -sf ${MQDB} ${MQDATA}/data
	@${LN} -sf ${ETCDIR} ${MQDATA}/conf
	@${LN} -sf ${EXAMPLESDIR}/example ${MQDATA}/example
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CHOWN} -Rh ${MQUSER}:${MQGROUP} ${MQDB} ${ETCDIR} ${EXAMPLES} ${MQDATA}

.include <bsd.port.mk>
