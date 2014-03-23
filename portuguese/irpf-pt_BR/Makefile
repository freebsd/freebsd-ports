# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	irpf
PORTVERSION=	2014.1.0
CATEGORIES=	portuguese finance java
MASTER_SITES=	http://www28.receita.fazenda.gov.br/publico/programas/IRPF/2014/PGDIRPF2014/Java/zip/
PKGNAMEPREFIX?=	pt_BR-
DISTNAME=	IRPF2014-1.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programa do Imposto de Renda Pessoa Fisica 2014 versao Java

LICENSE=	EULA
LICENSE_NAME=	End User License Agreement
LICENSE_FILE=	${WRKSRC}/IRPF-Licenses.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept
LICENSE_DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

USES=		zip
WRKSRC=		${WRKDIR}/${PORTNAME:U}2014

USE_JAVA=	yes
JAVA_RUN=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native

NO_BUILD=	yes
PLIST_SUB=	JAR_DIR=${JAR_DIR}

JAVAVM=		${LOCALBASE}/bin/java

JAR_DIR=	${JAVAJARDIR:S,^${PREFIX}/,,}/${PORTNAME}

DESKTOP_ENTRIES=	"Imposto de Renda Pessoa Fisica 2014" \
			"${COMMENT}" \
			"" \
			"${PORTNAME}" \
			"Office;Finance;" \
			true

#
## Files to install
#

# jar
JAR_FILES=	\
		irpf.jar \
		lib/commons-beanutils-1.7.jar \
		lib/commons-collections-3.2.1.jar \
		lib/commons-digester-1.8.jar \
		lib/commons-io-2.4.jar \
		lib/commons-logging-1.0.2.jar \
		lib/forms-1.0.3.jar \
		lib/foxtrot.jar \
		lib/freesans.jar \
		lib/iText-2.1.0.jar \
		lib/jasperreports-3.7.2.jar \
		lib/jdt-compiler-3.1.1.jar \
		lib/jhall.jar \
		lib/looks-1.3.1.jar \
		lib/ppgd-formatosext-4.1.8.jar \
		lib/ppgd-gui-beans-4.1.9.jar \
		lib/ppgd-gui-utils-4.0.jar \
		lib/ppgd-icones-4.0.jar \
		lib/ppgd-infra-4.0.jar \
		lib/ppgd-negocio-4.1.25.jar \
		lib/ppgd-persistencia-4.0.jar \
		lib/ppgd-pgd-utils-4.0.jar \
		lib/serpro.jar \
		lib/swing-layout-1.0.4.jar \
		lib/swingx-1.6.jar \
		lib/tinylaf.jar \
		lib/xalan.jar

#
## PLIST generation
#

# wrapper
PLIST_FILES+=	bin/${PORTNAME}

# jars
.for jar in ${JAR_FILES}
PLIST_FILES+=	%%JAR_DIR%%/${jar:C/^lib\///}
.endfor

# jar dir
PLIST_DIRS+=	\
		%%JAR_DIR%%

post-extract:
	@( cd ${WRKSRC} && ${JAR} xf ./irpf.jar IRPF-Licenses.txt )

post-patch:
	@${SED} -e  "s|%%JAR_DIR%%|${JAR_DIR}|; \
		s|%%JAR_FILE%%|${JAR_FILE}|; \
		s|%%JAR_FILES%%|${JAR_FILES:C/^lib\///}|; \
		s|%%JAVA_VERSION%%|${JAVA_VERSION}|; \
		s|%%JAVAVM%%|${JAVAVM}|;s|%%PREFIX%%|${PREFIX}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

do-install:
# jar dir
	@${MKDIR} ${STAGEDIR}${PREFIX}/${JAR_DIR}
	@${CHMOD} 755 ${STAGEDIR}/${PREFIX}/${JAR_DIR}
# jars
.for jar in ${JAR_FILES}
	${INSTALL_DATA} ${WRKSRC}/${jar} \
		${STAGEDIR}${PREFIX}/${JAR_DIR}
.endfor
# wrapper
	${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.pre.mk>

JAR_FILE=	${PORTNAME}.jar

.include <bsd.port.post.mk>
