# New ports collection makefile for:	mod_accounting
# Date created:				15 November 2002
# Whom:					Clément Laforêt <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_accounting
PORTVERSION=	0.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mod-acct

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	An Apache module that records traffic statistics into a database

BUILD_DEPENDS+=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13

MAKE_ARGS+=	APXS="${APXS}"
APXS?=		${LOCALBASE}/sbin/apxs

# MySQL deps hack
MYSQL323_LIBVER=10
MYSQL40_LIBVER=	12
MYSQL41_LIBVER=	14

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL_VER)
MYSQL_VER=	${WITH_MYSQL_VER}
.elif exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.${MYSQL_323_LIBVER})
MYSQL_VER=	323
.elif exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.${MYSQL40_LIBVER})
MYSQL_VER=	40
.elif exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.${MYSQL41_LIBVER})
MYSQL_VER=	41
.else
MYSQL_VER=	323
.endif


.if defined(WITHOUT_PGSQL)
MAKE_ARGS+=	WITHOUT_PGSQL=YES
.else
LIB_DEPENDS+=	pq.3:${PORTSDIR}/databases/postgresql7
.endif

.if defined(WITHOUT_MYSQL)
MAKE_ARGS+=	WITHOUT_MYSQL=YES
.else
LIB_DEPENDS+=	mysqlclient.${MYSQL${MYSQL_VER}_LIBVER}:${PORTSDIR}/databases/mysql${MYSQL_VER}-client
.endif

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      WITH_MYSQL_VER=323   Enable MySQL 3.23 support (default)"
	@${ECHO} "      WITH_MYSQL_VER=40    Enable MySQL 4.0 support"
	@${ECHO} "      WITH_MYSQL_VER=41    Enable MySQL 4.1 support"
	@${ECHO} ""
	@${ECHO} "      WITHOUT_MYSQL        Disable MySQL support"
	@${ECHO} "      WITHOUT_PGSQL        Disable PostgreSQL support"
	@${ECHO} ""

post-install:
	@${MKDIR} ${PREFIX}/share/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/schema.sql ${PREFIX}/share/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/FAQ.txt
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/LICENSE
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
