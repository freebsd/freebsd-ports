# New ports collection makefile for:	mod_auth_cookie_mysql
# Date created:				Tue Oct  7
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	mod_auth_cookie_mysql
PORTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	http://sheepkiller.nerim.net/ports/${PORTNAME}/ \
		http://www.cultdeadsheep.org/FreeBSD/ports/download/distfiles/
# Original Location: http://www.qwk.net/opensource/mod_auth_cookie_mysql/mod_auth_cookie_mysql.tar.gz
DIST_SUBDIR=	apache

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	Allows authentication against a MySQL database via a secure cookie

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_MYSQL=	YES
# If someone can test it with MySQL 4.1 ;-)
BROKEN_WITH_MYSQL=	41

APXS?=		${LOCALBASE}/sbin/apxs
MYSQL_INC?=	${LOCALBASE}/include/mysql
MYSQL_LIBS?=	${LOCALBASE}/lib/mysql -lmysqlclient -lz

do-build:
	@(cd ${WRKSRC} && ${APXS} -I ${MYSQL_INC} -L ${MYSQL_LIBS} -c ${PORTNAME}.c)

do-install:
	@(cd ${WRKSRC} && ${APXS} -A -i ${PORTNAME}.so)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/authform.tmpl ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/putcookie.cgi ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
