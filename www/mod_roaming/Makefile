# New ports collection makefile for:	mod_roaming
# Date created:			11 Aug 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mod_roaming
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.klomp.org/mod_roaming/

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13

APXS=		${LOCALBASE}/sbin/apxs

DOCS=		CHANGES	INSTALL	LICENSE	README

do-build:
	@cd ${WRKSRC} && \
	${APXS} -c mod_roaming.c

do-install:
	${APXS} -i -n roaming ${WRKSRC}/mod_roaming.so
	${INSTALL_DATA} ${FILESDIR}/httpd.conf.${PORTNAME} ${PREFIX}/etc/apache/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/${PORTNAME}/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
