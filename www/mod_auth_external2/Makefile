# New ports collection makefile for:	mod_auth_external2
# Date created:				Fri Oct  10
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	mod_auth_external
PORTVERSION=	2.2.8
CATEGORIES=	www
MASTER_SITES=	http://www.unixpapa.com/software/
DIST_SUBDIR=	apache

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows users authentication based on external mechanisms

WANT_APACHE=	2
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
LATEST_LINK=	mod_auth_external2

PORTDOCS=	AUTHENTICATORS INSTALL README

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache2/Makefile.modules.3rd"
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.   for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.post.mk>
