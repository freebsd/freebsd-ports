# New ports collection makefile for:	mod_filter
# Date created:				1 Jan 2002
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=		mod_filter
PORTVERSION=		1.4.1
CATEGORIES=		www
MASTER_SITES=		http://software.tangent.org/download/

MAINTAINER=		svenasse@polaris.ca

BUILD_DEPENDS=		${APXS}:${PORTSDIR}/www/apache13
RUN_DEPENDS=		${BUILD_DEPENDS}

APXS=			${LOCALBASE}/sbin/apxs
DOCS=			README
CONTRIB_DOCS=		contrib/README contrib/echo.cgi contrib/eecummings.cgi contrib/head.cgi

do-build:
	@cd ${WRKSRC} && \
	${APXS} -c mod_filter.c

do-install:
	${APXS} -i -A -n filter ${WRKSRC}/mod_filter.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mod_filter
	${MKDIR} ${PREFIX}/share/doc/mod_filter/contrib
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/mod_filter/
.endfor
.for f in ${CONTRIB_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/mod_filter/contrib
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
