# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	irpf
PORTVERSION=	2010.1.0
PORTREVISION=	1
CATEGORIES=	portuguese finance java
MASTER_SITES=	http://www.receita.fazenda.gov.br/publico/programas/IRPF/2010/PGDIrpf2010/Java/zip/
PKGNAMEPREFIX?=	pt_BR-
DISTNAME=	irpf2010-v1.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programa do Imposto de Renda Pessoa Fisica 2010 versao Java

USES=		zip
WRKSRC=		${WRKDIR}/${PORTNAME}2010

USE_JAVA=	yes
JAVA_RUN=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native

NO_BUILD=	yes
PLIST_SUB=	JAR_DIR=${JAR_DIR}

JAVAVM=		${LOCALBASE}/bin/java

JAR_DIR=	${JAVAJARDIR:S,^${PREFIX}/,,}/${PORTNAME}

DESKTOP_ENTRIES=	"Imposto de Renda Pessoa Fisica 2010" \
			"${COMMENT}" \
			"" \
			"${PORTNAME}" \
			"Office;Finance;" \
			"true"

#
## Files to install
#

# images
IMAGE_FILES=	\
		offline.png \
		online.png
# jar
JAR_FILES=	\
		irpf.jar \
		lib/commons-beanutils-1.7.jar \
		lib/commons-collections-2.1.jar \
		lib/commons-digester-1.8.jar \
		lib/commons-logging-1.0.2.jar \
		lib/forms-1.0.3.jar \
		lib/foxtrot.jar \
		lib/itext-1.02b.jar \
		lib/jasperreports-2.0.3.jar \
		lib/jdt-compiler-3.1.1.jar \
		lib/jhall.jar \
		lib/looks-1.3.1.jar \
		lib/ppgd-forms-compat-0.2.jar \
		lib/ppgd-gui-4.0.jar \
		lib/ppgd-gui-beans-4.0.jar \
		lib/ppgd-gui-utils-4.0.jar \
		lib/ppgd-infra-4.0.jar \
		lib/ppgd-negocio-4.0.jar \
		lib/ppgd-persistencia-4.0.jar \
		lib/ppgd-pgd-utils-4.0.jar \
		lib/swing-layout-0.7.jar \
		lib/xalan.jar

#
## PLIST generation
#

# wrapper
PLIST_FILES+=	bin/${PORTNAME}

# images
.for image in ${IMAGE_FILES}
PLIST_FILES+=	%%DATADIR%%/${image}
.endfor

# jars
.for jar in ${JAR_FILES}
PLIST_FILES+=	%%JAR_DIR%%/${jar:C/^lib\///}
.endfor

# data dir
PLIST_DIRS+=	\
		%%DATADIR%%
# jar dir
PLIST_DIRS+=	\
		%%JAR_DIR%%

NO_STAGE=	yes
post-patch:
	@${SED} -e  "s|%%DATADIR%%|${DATADIR}|; \
		s|%%DATA_FILES%%|${IMAGE_FILES}|; \
		s|%%JAR_DIR%%|${JAR_DIR}|; \
		s|%%JAR_FILE%%|${JAR_FILE}|; \
		s|%%JAR_FILES%%|${JAR_FILES:C/^lib\///}|; \
		s|%%JAVA_VERSION%%|${JAVA_VERSION}|; \
		s|%%JAVAVM%%|${JAVAVM}|;s|%%PREFIX%%|${PREFIX}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

do-install:
# jar dir
	@${MKDIR} ${PREFIX}/${JAR_DIR}
# data dir
	@${MKDIR} ${DATADIR}
# images
.for file in ${IMAGE_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} \
		${DATADIR}
.endfor
# jars
.for jar in ${JAR_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${jar} \
		${PREFIX}/${JAR_DIR}
.endfor
# wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh \
		${PREFIX}/bin/${PORTNAME}

.include <bsd.port.pre.mk>

JAR_FILE=	${PORTNAME}.jar

.include <bsd.port.post.mk>
