# New ports collection makefile for:    apache mod_frontpage
# Date created:		2001/07/24
# Whom:			mb@imp.ch
#
# $FreeBSD$

PORTNAME=	mod_frontpage
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://people.freebsd.org/~mbr/distfiles/

MAINTAINER=	mbr@FreeBSD.org

AP_PORT?=	apache13

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/${AP_PORT}
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/${AP_PORT}

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS= i386

INSTALL_FILE=	${INSTALL} -c -m 555 -o bin -g bin
PKG_PREFIX=	${PREFIX}

APXS=		${LOCALBASE}/sbin/apxs

.if exists(${APXS})
APXS_WORKS!=	${APXS} -q TARGET 2>/dev/null || ${ECHO} no
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

PERL_CONFIGURE= yes

.include <bsd.port.post.mk>
