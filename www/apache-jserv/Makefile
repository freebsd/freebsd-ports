# New ports collection makefile for:	apache mod_jserv
# Date created:         1999/05/29
# Whom:			Kensaku Masuda <greg@greg.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	apache-jserv
PORTVERSION=	1.1.2
PORTREVISION=	2
CATEGORIES=	www java
MASTER_SITES=	http://archive.apache.org/dist/java/jserv/
DISTNAME=	ApacheJServ-${PORTVERSION}

MAINTAINER=	greg@greg.rim.or.jp
COMMENT=	Loadable servlet module for apache

USE_JAVA=	1.1+
NEED_JAVAC=	yes

BUILD_DEPENDS=	${LOCALBASE}/sbin/apachectl:${PORTSDIR}/${APACHE_PORT}\
		${LOCALBASE}/share/java/classes/jsdk.jar:${PORTSDIR}/java/jsdk
RUN_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/javavmwrapper\
		${LOCALBASE}/sbin/apachectl:${PORTSDIR}/${APACHE_PORT}\
		${LOCALBASE}/share/java/classes/jsdk.jar:${PORTSDIR}/java/jsdk

USE_GMAKE=	yes
GMAKE=		${LOCALBASE}/bin/gmake # Must have the full path.
USE_LIBTOOL_VER=13
USE_PERL5=	yes
JAVAVM?=	${LOCALBASE}/bin/javavm
CONFIGURE_ENV=	PERL=${PERL}
CONFIGURE_ARGS=	--prefix=${PREFIX}\
		--libexecdir=${LOCALBASE}/libexec/apache\
		--libdir=${LOCALBASE}/libexec/apache\
		--with-logdir=/var/log\
		--sysconfdir=${PREFIX}/etc/apache\
		--with-apxs=${APXS}\
		--with-jdk-home=${JAVA_HOME}\
		--with-JSDK=${LOCALBASE}/share/java/classes/jsdk.jar\
		--with-java=${JAVA}\
		--with-javac=${JAVAC}\
		--with-servlets=${PREFIX}/share/java/servlets\
		--with-gnu-ld\
		--enable-compressed-jar\
		--enable-EAPI
.if defined (WITH_JIKES)
CONFIGURE_ARGS+=--with-javac=${LOCALBASE}/bin/jikes
.endif

pre-install:
	${MKDIR} ${PREFIX}/share/java/classes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
