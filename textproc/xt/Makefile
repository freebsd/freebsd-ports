# New ports collection makefile for:	XT
# Version required:	19990822
# Date created:		23 June 1999
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	xt
PKGNAME=	xt-19990822
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/xml/
EXTRACT_SUFX=	.zip

MAINTAINER=	kuriyama@FreeBSD.org

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	${PREFIX}/${JAVASUBDIR}/bin/java:${PORTSDIR}/java/jdk

EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=	-a -q -L
EXTRACT_AFTER_ARGS=	# empty
NO_WRKSUBDIR=	YES
PLIST_SUB=	JAVASUBDIR=${JAVASUBDIR}

JAVASUBDIR=	jdk1.1.8
DIR=		${PREFIX}/share/java

do-build:
	${SED} -e s,%%PREFIX%%,${PREFIX},g ${FILESDIR}/xt-xml4j.sh > ${WRKSRC}/xt-xml4j

do-install:
	${MKDIR} ${DIR}/classes ${DIR}/xt
	(cd ${WRKSRC};\
	 ${INSTALL_DATA} xt.jar sax.jar ${DIR}/classes; \
	 ${CP} -R copying.txt demo xt.htm ${DIR}/xt; \
	 ${INSTALL_SCRIPT} ${WRKSRC}/xt-xml4j ${PREFIX}/bin)

.include <bsd.port.mk>
