# New ports collection makefile for:	mod_security
# Date created:				4 June 2003
# Whom:					Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	mod_security
PORTVERSION=	1.7.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/_/-/}

MAINTAINER=	sysadmin@alexdupre.com
COMMENT=	An intrusion detection and prevention engine

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/apache2/apr.h)
WITH_APACHE2=   yes
.endif

APXS?=          ${LOCALBASE}/sbin/apxs
.if defined(WITH_APACHE2)
APACHE_PORT?=   ${PORTSDIR}/www/apache2
APWRKSRC?=	${WRKSRC}/apache2
PLIST_SUB=	APACHE=apache2
SO=		la
.else
APACHE_PORT?=   ${PORTSDIR}/www/apache13
APWRKSRC?=	${WRKSRC}/apache1
PLIST_SUB=	APACHE=apache
SO=		so
.endif

BUILD_DEPENDS+= ${APXS}:${APACHE_PORT}
RUN_DEPENDS+=   ${APXS}:${APACHE_PORT}

DOCS=		CHANGES INSTALL LICENSE README modsecurity-manual-1.7.pdf
PLIST_SUB+=	VER=1.7

do-build:
	@cd ${APWRKSRC} && ${APXS} -c mod_security.c

do-install:
	${APXS} -i -a -n security ${APWRKSRC}/mod_security.${SO}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/httpd.conf.example-* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
