# New ports collection makefile for:	mod_jk
# Date created:				Sun May 20 12:58:02 CEST 2001
# Whom:					Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_jk
PORTVERSION=	3.2.3
CATEGORIES=	www
MASTER_SITES=	http://jakarta.apache.org/builds/jakarta-tomcat/release/v${PORTVERSION}/src/
DISTNAME=	jakarta-tomcat-${PORTVERSION}-src

MAINTAINER=	dirk@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13 \
		${LOCALBASE}/jdk1.1.8/bin/javac:${PORTSDIR}/java/jdk
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13 \
		${LOCALBASE}/tomcat/lib/webserver.jar:${PORTSDIR}/www/jakarta-tomcat

USE_GMAKE=	yes
MAKEFILE=	Makefile.freebsd
WRKSRC=		${WRKDIR}/jakarta-tomcat-${PORTVERSION}-src/src/native/apache1.3

APXS?=		${LOCALBASE}/sbin/apxs

do-install:
	${APXS} -i -A -n jk ${WRKSRC}/mod_jk.so
	${SED} -e "s#%%PREFIX%%#${PREFIX}#g" ${FILESDIR}/mod_jk.conf > ${WRKDIR}/mod_jk.conf
	${INSTALL_DATA} ${WRKDIR}/mod_jk.conf ${PREFIX}/etc/apache

	@${SED} -e 's#/usr/local#${PREFIX}#g' ${PKGMESSAGE}

.include <bsd.port.mk>
