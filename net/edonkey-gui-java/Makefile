# New ports collection makefile for:	eDonkey2000 Java GUI for 'core' client
# Date created:				Fri Jan 4 23:59:44 BRST 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	1.1.2
PORTREVISION=	3
CATEGORIES=	net java
MASTER_SITES=	http://www.edonkey2000.com/files/
PKGNAMESUFFIX=	-gui-java
DISTNAME=	ed2k_${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java GUI to eDonkey2000 'core' command line client

RUN_DEPENDS=	donkey:${PORTSDIR}/net/linux-edonkey-core

BROKEN=		Unfetchable

USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes

JAVAVM=		${LOCALBASE}/bin/java

PLIST_FILES=	\
		bin/${PORTNAME}${PKGNAMESUFFIX} \
		%%JAVAJARDIR%%/${PORTNAME}${PKGNAMESUFFIX}.jar

post-patch:
	@${SED} -e "s|%%JAVAJARDIR%%|${JAVAJARDIR:S,^${PREFIX}/,,}|; \
		s|%%JAR_FILE%%|${PORTNAME}${PKGNAMESUFFIX}.jar|; \
		s|%%JAVA_VERSION%%|${JAVA_VERSION}|; \
		s|%%JAVAVM%%|${JAVAVM}|;s|%%PREFIX%%|${PREFIX}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

do-install:
	@${INSTALL_DATA} ${DISTDIR}/${JAR_FILE} \
		${JAVAJARDIR}/${PORTNAME}${PKGNAMESUFFIX}.jar
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.pre.mk>

JAR_FILE=	${DISTNAME}.jar

.include <bsd.port.post.mk>
