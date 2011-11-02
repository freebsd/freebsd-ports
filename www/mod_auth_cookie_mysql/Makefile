# New ports collection makefile for:	mod_auth_cookie_mysql
# Date created:				Tue Oct  7
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	mod_auth_cookie_mysql
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://sheepkiller.nerim.net/ports/${PORTNAME}/
# Original Location: http://www.qwk.net/opensource/mod_auth_cookie_mysql/mod_auth_cookie_mysql.tar.gz
DIST_SUBDIR=	apache

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows authentication against a MySQL database via a secure cookie

DEPRECATED=	apache13 is deprecated, migrate to 2.2.x+ now
EXPIRATION_DATE=	2012-01-01

MAKE_JOBS_SAFE=  yes

USE_MYSQL=	YES

# If someone can test it with MySQL 4.1 ;-)
IGNORE_WITH_MYSQL=	41

USE_APACHE=	13

AP_FAST_BUILD=	YES
AP_INC?=	${LOCALBASE}/include/mysql
AP_LIB?=	${LOCALBASE}/lib/mysql -lmysqlclient -lz

post-install:
	@(cd ${WRKSRC} && ${APXS} -A -i ${PORTNAME}.so)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/authform.tmpl ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/putcookie.cgi ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
