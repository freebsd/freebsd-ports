# New ports collection makefile for:	mod_auth_imap
# Date created:				Jun 5 2004
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_imap
PORTVERSION=	2.0.2
CATEGORIES=	www
# real location is http://ben.brillat.net/files/projects/mod_auth_imap2/mod_auth_imap2-current.tar.gz
MASTER_SITES=	http://sheepkiller.nerim.net/ports/${PORTNAME}/
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	An Apache 2 module to provide authentication via an IMAP mail server

WRKSRC=		${WRKDIR}/${PORTNAME}2-${PORTVERSION}
WANT_APACHE=	2
LATEST_LINK=	mod_auth_imap2
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES

PORTDOCS=	htaccess-example httpd.conf-append-example
.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache20/Makefile.modules.3rd"

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/examples && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
