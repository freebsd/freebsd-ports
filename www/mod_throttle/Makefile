# New ports collection makefile for:	mod_throttle
# Date created:			11 February 2001
# Whom:				Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	mod_throttle
PORTVERSION=	3.1.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.snert.com/Software/mod_throttle/ \
		http://atreides.freenix.no/~anders/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@FreeBSD.org
COMMENT=	An Apache module that provides bandwidth & request throttling

USE_APACHE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

DOCS=		CHANGES.txt LICENSE.txt index.shtml

do-build:
	@cd ${WRKSRC} && \
	${APXS} -c mod_throttle.c

do-install:
	${APXS} -i -A -n throttle ${WRKSRC}/mod_throttle.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mod_throttle
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/mod_throttle/
.endfor
.endif
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
