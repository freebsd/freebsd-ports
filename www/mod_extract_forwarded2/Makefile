# New ports collection makefile for:	mod_extract_forwarded2
# Date created:				Sun Nov  9
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_extract_forwarded2
PORTVERSION=	0.1
CATEGORIES=	www
MASTER_SITES=	http://www.cotds.org/${PORTNAME}/
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	An Apache module that can make proxied requests appear with client IP

USE_APACHE=	yes
WITH_APACHE2=	yes
PORTDOCS=	doc.html README

do-build:
	cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c

do-install:
	cd ${WRKSRC} && ${APXS} -A -i -n extract_forwarded ${PORTNAME}.la
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
