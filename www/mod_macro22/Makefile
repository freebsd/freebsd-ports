# Ports collection makefile for:	mod_macro22
# Date created:				31 May 2008
# Whom:					Lukasz Wasikowski <lukasz@wasikowski.net>
#
# $FreeBSD$
#

PORTNAME=	mod_macro
PORTVERSION=	1.1.10
CATEGORIES=	www
MASTER_SITES=	http://www.cri.ensmp.fr/~coelho/mod_macro/

MAINTAINER=	lukasz@wasikowski.net
COMMENT=	Apache 2.2.x module for use macros in config files

MAKE_JOBS_SAFE=  yes

USE_APACHE=	22
LATEST_LINK=	mod_macro22
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
PORTDOCS=	${PORTNAME}.html

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
