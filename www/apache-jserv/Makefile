# New ports collection makefile for:	apache mod_jserv
# Date created:         1999/05/29
# Whom:			Kensaku Masuda <greg@greg.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	apache-jserv
PORTVERSION=	1.1.2
CATEGORIES=	www java
MASTER_SITES=	http://java.apache.org/jserv/dist/
DISTNAME=	ApacheJServ-${PORTVERSION}

MAINTAINER=	greg@greg.rim.or.jp

BUILD_DEPENDS=	${LOCALBASE}/jdk1.1.8/bin/javac:${PORTSDIR}/java/jdk\
		${LOCALBASE}/sbin/apachectl:${PORTSDIR}/www/apache13\
		${LOCALBASE}/share/java/classes/jsdk.jar:${PORTSDIR}/java/jsdk
RUN_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/javavmwrapper\
		${LOCALBASE}/sbin/apachectl:${PORTSDIR}/www/apache13\
		${LOCALBASE}/share/java/classes/jsdk.jar:${PORTSDIR}/java/jsdk

USE_GMAKE=	yes
GMAKE=		${LOCALBASE}/bin/gmake # Must have the full path.
USE_LIBTOOL=	yes
USE_PERL5=	yes
JAVAVM?=	${LOCALBASE}/bin/javavm
CONFIGURE_ENV=	PERL=${PERL}
CONFIGURE_ARGS=	--prefix=${PREFIX}\
		--libexecdir=${LOCALBASE}/libexec/apache\
		--libdir=${LOCALBASE}/libexec/apache\
		--with-logdir=/var/log\
		--sysconfdir=${PREFIX}/etc/apache\
		--with-apxs=${LOCALBASE}/sbin/apxs\
		--with-jdk-home=${LOCALBASE}/jdk1.1.8\
		--with-JSDK=${LOCALBASE}/share/java/classes/jsdk.jar\
		--with-java=${LOCALBASE}/jdk1.1.8/bin/java\
		--with-javac=${LOCALBASE}/jdk1.1.8/bin/javac\
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
