# New ports collection makefile for:	apache mod_jserv
# Version required:	1.0
# Date created:         1999/05/29
# Whom:			Kensaku Masuda <greg@greg.rim.or.jp>
#
# $FreeBSD$

DISTNAME=	Apache_JServ_1.0
PKGNAME=	apache-jserv-1.0
CATEGORIES=	www java
MASTER_SITES=	http://java.apache.org/jserv/dist/

MAINTAINER=	greg@greg.rim.or.jp

BUILD_DEPENDS=	${PREFIX}/jdk1.1.8/bin/javac:${PORTSDIR}/java/jdk\
		${PREFIX}/sbin/apachectl:${PORTSDIR}/www/apache13\
		${PREFIX}/share/java/classes/jsdk.jar:${PORTSDIR}/java/jsdk
RUN_DEPENDS=	${PREFIX}/jdk1.1.8/bin/java:${PORTSDIR}/java/jdk\
		${PREFIX}/sbin/apachectl:${PORTSDIR}/www/apache13\
		${PREFIX}/share/java/classes/jsdk.jar:${PORTSDIR}/java/jsdk

WRKSRC=		${WRKDIR}/ApacheJServ-1.0
USE_LIBTOOL=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS=	--prefix=${PREFIX}\
		--libexecdir=${PREFIX}/libexec/apache\
		--libdir=${PREFIX}/libexec/apache\
		--sysconfdir=${PREFIX}/etc/apache\
		--with-jdk-home=${PREFIX}/jdk1.1.8\
		--with-jsdk=${PREFIX}/share/java/classes/jsdk.jar\
		--with-apache-install=${PREFIX}\
		--with-java=${PREFIX}/jdk1.1.8/bin/java\
		--with-javac=${PREFIX}/jdk1.1.8/bin/javac\
		--with-gnu-ld\
		--enable-compressed-jar

post-install:
	@(cd ${WRKSRC}/conf;\
	 ${INSTALL_DATA} httpd.conf \
		${PREFIX}/etc/apache/jserv.conf.default;\
	 ${INSTALL_DATA} jserv.properties \
		${PREFIX}/etc/apache/jserv.properties.default; \
	 ${INSTALL_DATA} zone.properties \
		${PREFIX}/etc/apache/zone.properties.default)
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
