# New ports collection makefile for:	Coccon
# Date created:		27 June 1999
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cocoon
PORTVERSION= 	1.5
CATEGORIES=	textproc www java
MASTER_SITES=	http://java.apache.org/cocoon/dist/
DISTNAME=	Cocoon_${PORTVERSION}
EXTRACT_SUFX=	.jar

MAINTAINER=	kuriyama@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/libexec/apache/mod_jserv.so:${PORTSDIR}/www/apache-jserv
#		${LOCALBASE}/share/java/classes/lotusxsl.jar:${PORTSDIR}/textproc/lotusxsl
#		${LOCALBASE}/share/java/classes/xml4j.jar:${PORTSDIR}/textproc/xml4j

EXTRACT_CMD=	${PREFIX}/${JAVASUBDIR}/bin/jar
EXTRACT_BEFORE_ARGS=	xf
EXTRACT_AFTER_ARGS=
NO_WRKSUBDIR=	YES
NO_BUILD=	YES

JAVASUBDIR=	jdk1.1.8

do-install:
	@${MKDIR} ${PREFIX}/share/java/classes ${PREFIX}/share/java/cocoon
	@(cd ${WRKSRC}/bin; \
	  ${INSTALL_DATA} Cocoon.jar fop.0110.jar openxml.106-fix.jar xslp.19991017-fix.jar \
		${PREFIX}/share/java/classes)
	@(cd ${WRKSRC}; \
	 ${CP} -R [LRd-i]* ${PREFIX}/share/java/cocoon)
	@${INSTALL_DATA} ${WRKSRC}/bin/cocoon.properties \
		${PREFIX}/etc/apache/cocoon.properties.default

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
