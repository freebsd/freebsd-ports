# New ports collection makefile for:	mod_auth_mysql2
# Date created:				Sep 10 2005
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_mysql
PORTVERSION=	1.5
CATEGORIES=	www
MASTER_SITES=	http://www.heuer.org/mod_auth_mysql/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	MySQL-based authentication module with VirtualHost support

LATEST_LINK=	mod_auth_mysql2

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_MYSQL=	YES
WANT_APACHE=	2
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
AP_INC+=	${LOCALBASE}/include/mysql
AP_LIB+=	${LOCALBASE}/lib/mysql -lmysqlclient

PORTDOCS=	INSTALL example_data.html htpasswd.sql

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache2/Makefile.modules.3rd"
post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}

.include <bsd.port.post.mk>
