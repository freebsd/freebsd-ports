# New ports collection makefile for:	apache-contrib
# Date created:				September 10 2000
# Whom:	      				Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	apache-contrib
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://archive.apache.org/dist/httpd/%SUBDIR%/
MASTER_SITE_SUBDIR=	contrib/modules/1.3

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Third-party modules contributed to the Apache HTTP server project

USE_APACHE=	yes

.if defined(WITH_MODULES_PORTS)
PLIST_SUB+=	PORTS="@comment "
MODS_DIR=	${LOCALBASE}/libexec/apache
RUN_DEPENDS+=	${MODS_DIR}/mod_auth_external.so:${PORTSDIR}/www/mod_auth_external \
		${MODS_DIR}/mod_bandwidth.so:${PORTSDIR}/www/mod_bandwidth \
		${MODS_DIR}/mod_put.so:${PORTSDIR}/www/mod_put \
		${MODS_DIR}/mod_ticket.so:${PORTSDIR}/www/mod_ticket \
		${MODS_DIR}/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi \
		${MODS_DIR}/mod_cvs.so:${PORTSDIR}/www/mod_cvs \
		${MODS_DIR}/mod_roaming.so:${PORTSDIR}/www/mod_roaming
		${MODS_DIR}/mod_layout.so:${PORTSDIR}/www/mod_layout
PKGNAMESUFFIX+=	-lite
.else
MAKE_ENV+=	NO_PORTS=YES
PLIST_SUB+=	PORTS=""
CONFLICTS=	mod_auth_external-2.* mod_bandwidth-2.* mod_put-1.* \
		mod_ticket-1.* mod_fastcgi-2.* mod_cvs-0.* mod_roaming-1.* \
		mod_layout-3.* mod_macro-1.*
.endif

.if exists(${APXS})
APXS_WORKS!=	${APXS} -q TARGET 2>/dev/null || echo no
.endif
.if exists(${APXS}) && ${APXS_WORKS} != no
AP_TARGET!=	${APXS} -q TARGET
AP_SYSCONF!=	${APXS} -q SYSCONFDIR
AP_INCLUDE!=	${APXS} -q INCLUDEDIR
AP_LIBEXEC!=	${APXS} -q LIBEXECDIR
.else
AP_TARGET?=	httpd
AP_SYSCONF?=	${PREFIX}/etc/apache
AP_INCLUDE?=	${PREFIX}/include/apache
AP_LIBEXEC?=	${PREFIX}/libexec/apache
.endif

ALL_TARGET=	APXS=${APXS} all
INSTALL_TARGET=	APXS=${APXS} install

pre-everything::
	@${ECHO_MSG} " ${PORTNAME} contains obsolete modules."
	@${ECHO_MSG} " If you want to install their latest version from ports"
	@${ECHO_MSG} " just define WITH_MODULES_PORTS."

.include <bsd.port.mk>
