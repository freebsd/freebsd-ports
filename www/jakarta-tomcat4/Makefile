# New ports collection makefile for:	jakarta-tomcat
# Date created:		20 Oct 2000
# Whom:			des
#
# $FreeBSD$
#

PORTNAME=	jakarta-tomcat
PORTVERSION=	3.2.3
CATEGORIES=	www
MASTER_SITES=	http://jakarta.apache.org/builds/jakarta-tomcat/release/v${PORTVERSION}/bin/
DIST_SUBDIR=	jakarta/tomcat/${PORTVERSION}

MAINTAINER=	dirk@FreeBSD.org

BUILD_DEPENDS=	pinstall:${PORTSDIR}/devel/pinstall
RUN_DEPENDS=	${LOCALBASE}/jdk1.1.8/bin/javac:${PORTSDIR}/java/jdk

NO_BUILD=	yes

do-install:
	@/usr/bin/perl -i -pe "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/conf/workers.properties
	@${LN} -fs ${WRKSRC} ${WRKDIR}/tomcat
	@pinstall -v -d ${WRKDIR}
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/tomcat.sh > ${WRKDIR}/tomcat.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/tomcat.sh /usr/local/etc/rc.d

post-install:
	@${ECHO} "etc/rc.d/tomcat.sh" >> ${TMPPLIST}

.include <bsd.port.mk>
