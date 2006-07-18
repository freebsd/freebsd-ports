# New ports collection makefile for:	mod_security
# Date created:				4 June 2003
# Whom:					Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	mod_security
PORTVERSION=	1.9.4
CATEGORIES=	www security
MASTER_SITES=	http://www.modsecurity.org/download/
DISTNAME=	${PORTNAME:S/_//}-apache_${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	An intrusion detection and prevention engine

USE_APACHE=	1.3+

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} > 13
APWRKSRC?=	${WRKSRC}/apache2
.else
APWRKSRC?=	${WRKSRC}/apache1
.endif

DOCS=		CHANGES INSTALL LICENSE README doc/modsecurity-manual.pdf
PORTDOCS=	*

do-build:
	@cd ${APWRKSRC} && ${APXS} -c ${MODULENAME}.c

do-install:
	${APXS} -i -a -n ${SHORTMODNAME} ${APWRKSRC}/${MODULENAME}.${AP_BUILDEXT}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/httpd.conf.example-* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
