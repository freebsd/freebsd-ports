# New ports collection makefile for:	mod_tsunami
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_tsunami
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://bertrand.demiddelaer.org/mod_tsunami/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Apache module which dynamically limits a site's slot usage

DEPRECATED=	apache13 is deprecated, migrate to 2.2.x+ now
EXPIRATION_DATE=	2012-01-01

MAKE_JOBS_SAFE=  yes

USE_APACHE=	13
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
