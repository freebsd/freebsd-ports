# New ports collection makefile for:	mod_auth_imap
# Date created:				Jun 5 2004
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_imap
PORTVERSION=	2.0
CATEGORIES=	www
MASTER_SITES=	http://www.zhen.org/software/mod_auth_imap/
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	An Apache 2 module to provide authentication via an IMAP mail server

WANT_APACHE=	2
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES

PORTDOCS=	htaccess-example httpd.conf-append-example
.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache2/Makefile.modules.3rd"

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/examples && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
