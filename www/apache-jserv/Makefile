# New ports collection makefile for:	apache mod_jserv
# Date created:         1999/05/29
# Whom:			Kensaku Masuda <greg@greg.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	apache-jserv
PORTVERSION=	1.1.2
PORTREVISION=	4
CATEGORIES=	www java
MASTER_SITES=	http://archive.apache.org/dist/java/jserv/
DISTNAME=	ApacheJServ-${PORTVERSION}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Loadable servlet module for apache

DEPRECATED=	superceeded by tomcat
EXPIRATION_DATE=	2009-06-09

USE_JAVA=	yes

BUILD_DEPENDS=	${LOCALBASE}/sbin/apachectl:${PORTSDIR}/${APACHE_PORT}\
		${JAVALIBDIR}/jsdk.jar:${PORTSDIR}/java/jsdk
RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper\
		${LOCALBASE}/sbin/apachectl:${PORTSDIR}/${APACHE_PORT}\
		${JAVALIBDIR}/jsdk.jar:${PORTSDIR}/java/jsdk

USE_GMAKE=	yes
GMAKE=		${LOCALBASE}/bin/gmake # Must have the full path.
GNU_CONFIGURE=	yes
USE_PERL5=	yes
APACHE_COMPAT=	yes
CONFIGURE_ENV=	PERL=${PERL}
CONFIGURE_ARGS=	--prefix=${PREFIX}\
		--libexecdir=${LOCALBASE}/libexec/apache\
		--libdir=${LOCALBASE}/libexec/apache\
		--with-logdir=/var/log\
		--sysconfdir=${PREFIX}/etc/apache\
		--with-apxs=${APXS}\
		--with-jdk-home=${JAVA_HOME}\
		--with-JSDK=${JAVALIBDIR}/jsdk.jar\
		--with-java=${JAVA}\
		--with-javac=${JAVAC}\
		--with-servlets=${JAVASHAREDIR}/servlets\
		--with-gnu-ld\
		--enable-compressed-jar\
		--enable-EAPI
.if defined (HAVE_JIKES)
CONFIGURE_ARGS+=--with-javac=${LOCALBASE}/bin/jikes
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
