# New ports collection makefile for:	mod_security
# Date created:				4 June 2003
# Whom:					Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	mod_security
PORTVERSION=	1.8.4
CATEGORIES=	www security
MASTER_SITES=	http://www.modsecurity.org/download/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/_/-/}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	An intrusion detection and prevention engine

USE_APACHE=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/apache2/httpd.h)
WITH_APACHE2=	yes
.endif

.if defined(WITH_APACHE2)
APWRKSRC?=	${WRKSRC}/apache2
PLIST_SUB=	APACHE=apache2
SO=		la
.else
APWRKSRC?=	${WRKSRC}/apache1
PLIST_SUB=	APACHE=apache
SO=		so
.endif

DOCS=		CHANGES INSTALL LICENSE README modsecurity-manual.pdf

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
