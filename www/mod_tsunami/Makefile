# New ports collection makefile for:	mod_tsunami
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_tsunami
PORTVERSION=	3.0
CATEGORIES=	www
MASTER_SITES=	http://bertrand.demiddelaer.org/mod_tsunami/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Apache module which dynamically limits a site's slot usage

USE_APACHE=	yes
DOCS=		AUTHORS Changelog

do-build:
	@cd ${WRKSRC} && ${APXS} -c mod_tsunami.c

do-install:
	${APXS} -i -A -n tsunami ${WRKSRC}/mod_tsunami.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
	@${CP} -R ${WRKSRC}/docs/* ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
