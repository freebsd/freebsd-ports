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

MAINTAINER=	apache@FreeBSD.org
COMMENT=	An Apache module that works as a Netscape Roaming Access server

MAKE_JOBS_SAFE=  yes

CONFLICTS=	apache-contrib-1.*
PORTSCOUT=	limit:^1

USE_APACHE=	1.3
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
PLIST_FILES=	${APACHEETCDIR}/httpd.conf.${PORTNAME}

PORTDOCS=		CHANGES	INSTALL	LICENSE	README

post-install:
	${INSTALL_DATA} ${FILESDIR}/httpd.conf.${PORTNAME} ${LOCALBASE}/${APACHEETCDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
