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

USE_APACHE=	1.3
AP_FAST_BUILD=	yes

DOCS=		AUTHORS Changelog

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
	@${CP} -R ${WRKSRC}/docs/* ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
