# New ports collection makefile for:	mod_extract_forwarded
# Date created:		9 June 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	mod_extract_forwarded
PORTVERSION=	1.2
CATEGORIES=	www
MASTER_SITES=	http://web.systhug.com/mod_extract_forwarded/ \
		http://atreides.freenix.no/~anders/

MAINTAINER=	anders@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13

WRKSRC=		${WRKDIR}/${PORTNAME}

APXS?=		${LOCALBASE}/sbin/apxs
DOCS=		mod_extract_forwarded.html README

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
