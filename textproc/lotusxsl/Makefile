# New ports collection makefile for:	LotusXSL
# Version required:	0.17.4
# Date created:		23 June 1999
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.ORG>
#
# $FreeBSD$
#

DISTNAME=	lotusxsl_0_17_4
PKGNAME=	lotusxsl-0.17.4
CATEGORIES=	textproc
MASTER_SITES=	http://www.alphaworks.ibm.com/formula/lotusxsl/
#MASTER_SITES=	http://apps.alphaworks.ibm.com/technologies/lotusxsl/
EXTRACT_SUFX=	.zip

MAINTAINER=	kuriyama@FreeBSD.ORG

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	${PREFIX}/share/java/classes/xml4j.jar:${PORTSDIR}/textproc/xml4j

EXTRACT_CMD=		unzip
EXTRACT_BEFORE_ARGS=	-a -q -L
EXTRACT_AFTER_ARGS=	# empty
RESTRICTED=		"License prohibites to distribute."

DIR=		${PREFIX}/share/java

do-build:
	${SED} -e s,%%PREFIX%%,${PREFIX},g ${FILESDIR}/lotusxsl.sh > ${WRKSRC}/lotusxsl

do-install:
	${MKDIR} ${DIR}/classes ${DIR}/LotusXSL
	(cd ${WRKSRC};\
	 ${INSTALL_DATA} js.jar lotusxsl.jar ${DIR}/classes;\
	 ${CP} -R apidocs examples images readme_production samples testsuite *.htm? run* xsl-html40s.dtd ${DIR}/LotusXSL;\
	 ${INSTALL_SCRIPT} ${WRKSRC}/lotusxsl ${PREFIX}/bin)

.include <bsd.port.mk>
