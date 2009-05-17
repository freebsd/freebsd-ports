# ex:ts=8
# Ports collection makefile for:	mod_macro
# Date created:			Nov 20, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mod_macro
PORTVERSION=	1.1.2b
CATEGORIES=	www
MASTER_SITES=	http://www.cri.ensmp.fr/~coelho/mod_macro/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for use macros in config files

MAKE_JOBS_SAFE=  yes

USE_APACHE=	13
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
PORTDOCS=	${PORTNAME}.html

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
