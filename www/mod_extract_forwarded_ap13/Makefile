# New ports collection makefile for:	mod_extract_forwarded
# Date created:		9 June 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	mod_extract_forwarded
PORTVERSION=	2.0.2
CATEGORIES=	www
MASTER_SITES=	http://www.openinfo.co.uk/apache/
DISTNAME=	extract_forwarded-${DISTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	An Apache module that can make proxied requests appear with client IP

USE_APACHE=	20+
WRKSRC=		${WRKDIR}/extract_forwarded
PORTDOCS=	INSTALL README
MAKE_JOBS_SAFE=  yes

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
