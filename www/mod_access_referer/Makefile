# New ports collection makefile for:	mod_access_referer
# Date created:			18 Oct 2000
# Whom:				Alex Kapranoff <kapr@crosswinds.net>
#
# $FreeBSD$
#

PORTNAME=	mod_access_referer
PORTVERSION=	1.0.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	accessreferer

MAINTAINER=	ports@freebsd.org

PORTCOMMENT=	An Apache module that provides access control based on Referer HTTP header

BUILD_DEPENDS=	${APXS}:${APACHE_PORT}
RUN_DEPENDS=	${APXS}:${APACHE_PORT}

APXS?=		${LOCALBASE}/sbin/apxs
APACHE_PORT?=	${PORTSDIR}/www/apache13

DOCS=		HACKING LICENSE.txt ChangeLog README TODO mod_access_referer.html

do-build:
	@cd ${WRKSRC} && \
	${APXS} -c mod_access_referer.c

do-install:
	${APXS} -i -A -n access_referer ${WRKSRC}/mod_access_referer.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mod_access_referer
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/mod_access_referer/
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
