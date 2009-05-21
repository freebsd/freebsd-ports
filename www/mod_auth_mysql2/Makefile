# New ports collection makefile for:	mod_auth_mysql2
# Date created:				Sep 10 2005
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_mysql
PORTVERSION=	1.10
CATEGORIES=	www
MASTER_SITES=	http://www.heuer.org/mod_auth_mysql/old/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	apache22

MAINTAINER=	mm@FreeBSD.org
COMMENT=	MySQL-based authentication module with VirtualHost support

MAKE_JOBS_SAFE=  yes

LATEST_LINK=	mod_auth_mysql2

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_MYSQL=	YES
USE_APACHE=	2.0+
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
AP_INC+=	${LOCALBASE}/include/mysql
AP_LIB+=	${LOCALBASE}/lib/mysql -lmysqlclient

.if defined(WITH_OPENSSL)
USE_OPENSSL=	yes
AP_EXTRAS+=	-DMYSQL_USE_SSL
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	INSTALL example_data.html htpasswd.sql
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
