# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_auth_imap
PORTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://ben.brillat.net/files/projects/mod_auth_imap2/
PKGNAMESUFFIX=	2
DISTNAME=	mod_auth_imap2-${PORTVERSION}
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache 2 module to provide authentication via an IMAP mail server

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}2-${PORTVERSION}
USE_APACHE=	22
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

PORTDOCS=	htaccess-example httpd.conf-append-example

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/examples/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
