# New ports collection makefile for:	mod_extract_forwarded
# Date created:		9 June 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	mod_extract_forwarded
PORTVERSION=	1.4
CATEGORIES=	www
MASTER_SITES=	http://web.warhound.org/mod_extract_forwarded/ \
		http://atreides.freenix.no/~anders/

MAINTAINER=	anders@FreeBSD.org
COMMENT=	An Apache module that can make proxied requests appear with client IP

USE_APACHE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
DOCS=		doc.html README

do-build:
	cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c

do-install:
	cd ${WRKSRC} && ${APXS} -A -i ${PORTNAME}.so
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/share/doc/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/${PORTNAME}
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
