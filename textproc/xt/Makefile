# New ports collection makefile for:	XT
# Date created:		23 June 1999
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xt
PORTVERSION=	19991105
PORTREVISION=	1
CATEGORIES=	textproc java
MASTER_SITES=	ftp://ftp.jclark.com/pub/xml/
DISTNAME=	${PORTNAME}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	XSL Transformations (XSLT) implementation in Java

USE_JAVA=	1.1+
USE_ZIP=	YES
NO_BUILD_DEPENDS_JAVA=	YES
NO_WRKSUBDIR=	YES
ONLY_FOR_ARCHS=	i386

DIR=		${PREFIX}/share/java

do-build:
	${SED} -e s,%%PREFIX%%,${PREFIX},g ${FILESDIR}/xt-xml4j.sh > ${WRKSRC}/xt-xml4j
	${SED} -e s,%%PREFIX%%,${PREFIX},g ${FILESDIR}/xt-xp.sh > ${WRKSRC}/xt-xp

do-install:
	${MKDIR} ${DIR}/classes ${DIR}/xt
	(cd ${WRKSRC};\
	 ${INSTALL_DATA} xt.jar sax.jar ${DIR}/classes; \
	 ${CP} -R copying.txt demo xt.htm ${DIR}/xt; \
	 ${INSTALL_SCRIPT} ${WRKSRC}/xt-xml4j ${PREFIX}/bin; \
	 ${INSTALL_SCRIPT} ${WRKSRC}/xt-xp ${PREFIX}/bin)

.include <bsd.port.mk>
