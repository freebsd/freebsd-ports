# New ports collection makefile for:	mod_roaming
# Date created:			11 Aug 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mod_roaming
PORTVERSION=	1.0.2
CATEGORIES=	www
MASTER_SITES=	http://www.klomp.org/mod_roaming/

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13

APXS=		${LOCALBASE}/sbin/apxs

DOCS=		CHANGES	INSTALL	LICENSE	README

do-build:
	@cd ${WRKSRC} && \
	${APXS} -c mod_roaming.c

do-install:
	${APXS} -i -A -n roaming ${WRKSRC}/mod_roaming.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mod_roaming
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/mod_roaming/
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
