# Ports collection makefile for:	mod_macro2
# Date created:				Sun Aug 8 2004
# Whom:					clement
#
# $FreeBSD$
#

PORTNAME=	mod_macro
PORTVERSION=	1.1.6
CATEGORIES=	www
MASTER_SITES=	http://www.cri.ensmp.fr/~coelho/mod_macro/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache 2.0.x module for use macros in config files

MAKE_JOBS_SAFE=  yes

USE_APACHE=	20
LATEST_LINK=	mod_macro2
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
PORTDOCS=	${PORTNAME}.html

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
