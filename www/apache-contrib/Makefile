# New ports collection makefile for:	apache-contrib
# Date created:				September 10 2000
# Whom:	      				Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	apache-contrib
PORTVERSION=	1.0.8
CATEGORIES=	www
MASTER_SITES=	http://www.apache.org/dist/%SUBDIR%/ \
		ftp://ftp.ccs.neu.edu/net/mirrors/ftp.apache.org/apache/dist/%SUBDIR%/ \
		ftp://ftp.rge.com/pub/infosystems/apache/dist/%SUBDIR%/ \
		ftp://apache.compuex.com/pub/apache/dist/%SUBDIR%/ \
		ftp://apache.arctic.org/pub/apache/dist/%SUBDIR%/ \
		ftp://ftp.epix.net/pub/apache/dist/%SUBDIR%/ \
		ftp://ftp.ameth.org/pub/mirrors/ftp.apache.org/apache/dist/%SUBDIR%/ \
		ftp://ftp.connectnet.com/pub/www/apache/%SUBDIR%/ \
		ftp://apache.technomancer.com/mirrors/apache/dist/%SUBDIR%/ \
		ftp://ftp.raver.net/pub/ftp.apache.org/%SUBDIR%/ \
		ftp://www3.service.digital.com/apache/dist/%SUBDIR%/ \
		ftp://galileo.galilei.com/pub/apache/%SUBDIR%/ \
		ftp://ftp.mtnranch.net/pub/apache/dist/%SUBDIR%/ \
		ftp://ftp.iodynamics.com/pub/mirror/apache/dist/%SUBDIR%/ \
		ftp://apache.nextpath.com/pub/apache/dist/%SUBDIR%/
MASTER_SITE_SUBDIR=	contrib/modules/1.3

MAINTAINER=	anders@fix.no

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13

APXS=		${LOCALBASE}/sbin/apxs

AP_PORT?=       apache13
.if exists(${APXS})
APXS_WORKS!=	${APXS} -q TARGET 2>/dev/null || echo no
.endif
.if exists(${APXS}) && ${APXS_WORKS} != no
AP_TARGET!=	${APXS} -q TARGET
AP_SYSCONF!=	${APXS} -q SYSCONFDIR
AP_INCLUDE!=	${APXS} -q INCLUDEDIR
AP_LIBEXEC!=	${APXS} -q LIBEXECDIR
.else
AP_TARGET?=     httpd
AP_SYSCONF?=    ${PREFIX}/etc/apache
AP_INCLUDE?=    ${PREFIX}/include/apache
AP_LIBEXEC?=    ${PREFIX}/libexec/apache
.endif

ALL_TARGET=	APXS=${APXS}/sbin/apxs all

.include <bsd.port.mk>
