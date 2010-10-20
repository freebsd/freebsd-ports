# New ports collection makefile for:	mod_extract_forwarded
# Date created:		9 June 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	mod_extract_forwarded
PORTVERSION=	1.4
CATEGORIES=	www
MASTER_SITES=	http://www.warhound.org/mod_extract_forwarded/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	An Apache module that can make proxied requests appear with client IP

MAKE_JOBS_SAFE=  yes

USE_APACHE=	1.3
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
CONFLICTS=	mod_extract_forwarded-2.* mod_extract_forwarded2-0.*
NO_LATEST_LINK=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=		doc.html README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
