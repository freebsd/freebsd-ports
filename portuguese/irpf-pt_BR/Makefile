# New ports collection makefile for:	irpf
# Date created:		Ter  6 Mar 2007 01:50:17 UTC
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	irpf
PORTVERSION=	2007.1.0
PORTREVISION=	2
CATEGORIES=	portuguese finance java
MASTER_SITES=	http://www.receita.fazenda.gov.br/publico/programas/irpf/2007/PGDIrpf2007/Java/ZIP/
PKGNAMEPREFIX?=	pt_BR-
DISTNAME=	irpf2007v1.0

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Programa do Imposto de Renda Pessoa Fisica 2007 versao Java

USE_ZIP=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
SUB_FILES=	pkg-message
PLIST_SUB=	JAR_DIR=${JAR_DIR}
PKGMESSAGE=	${WRKDIR}/pkg-message

JAVAVM=		${LOCALBASE}/bin/java

JAR_DIR=	${JAVAJARDIR:S,^${PREFIX}/,,}/${PORTNAME}

JAR_FILES=	\
		irpf.jar \
		jhall.jar

PLIST_FILES+=	bin/${PORTNAME}

.for jar in ${JAR_FILES}
PLIST_FILES+=	%%JAR_DIR%%/${jar}
.endfor

PLIST_DIRS+=	\
		%%JAR_DIR%%

post-patch:
	@${SED} -e  "s|%%JAR_DIR%%|${JAR_DIR}|; \
		s|%%JAR_FILE%%|${JAR_FILE}|; \
		s|%%JAR_FILES%%|${JAR_FILES}|; \
		s|%%JAVA_VERSION%%|${JAVA_VERSION}|; \
		s|%%JAVAVM%%|${JAVAVM}|;s|%%PREFIX%%|${PREFIX}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

do-install:
	@${MKDIR} ${PREFIX}/${JAR_DIR}
# jars
.for jar in ${JAR_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${jar} \
		${PREFIX}/${JAR_DIR}
.endfor
# wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh \
		${PREFIX}/bin/${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

JAR_FILE=	${PORTNAME}.jar

.include <bsd.port.post.mk>
