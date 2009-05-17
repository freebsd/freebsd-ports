# New ports collection makefile for:	mod_filter
# Date created:				1 Jan 2002
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=		mod_filter
PORTVERSION=		1.4.1
PORTREVISION=	1
CATEGORIES=		www
MASTER_SITES=		http://download.tangent.org/

MAINTAINER=		apache@FreeBSD.org
COMMENT=	Filter output from other modules inside of Apache

MAKE_JOBS_SAFE=  yes

USE_APACHE=		1.3
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

PORTDOCS=			README contrib

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	${MKDIR} ${DOCSDIR}/contrib/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	${COPYTREE_SHARE ${WRKSRC}/contrib/ ${DOCSDIR}/contrib/
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
