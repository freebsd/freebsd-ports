# New ports collection makefile for:	mod_auth_cookie_mysql2
# Date created:				Sun Aug 8 2004
# Whom:					clement
#
# $FreeBSD$

PORTNAME=	mod_auth_cookie_mysql2
PORTVERSION=	0.3
CATEGORIES=	www
MASTER_SITES=	http://home.digithi.de/digithi/dev/
DISTNAME=	${PORTNAME}_${PORTVERSION}
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows authentication against a MySQL database via a secure cookie

USE_MYSQL=	YES
# If someone can test it with MySQL 4.1 ;-)
BROKEN_WITH_MYSQL=	41

WANT_APACHE=	2

AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
AP_INC?=	${LOCALBASE}/include/mysql
AP_LIB?=	${LOCALBASE}/lib/mysql -lmysqlclient -lz
PORTDOCS=	mod_auth_cookie_mysql2.html

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache2/Makefile.modules.3rd"
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif
.include <bsd.port.post.mk>
