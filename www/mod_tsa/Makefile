# New ports collection makefile for:   mod_tsa
# Date created:        22 November 2010
# Whom:                ubique
#
# $FreeBSD$
#

PORTNAME=	mod_tsa
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://am.nesiac.org/static/ \
  http://ubique.spb.ru/src/

MAINTAINER=	ubique@peterhost.ru
COMMENT=	Time stamping authority (RFC 3161) module for apache

OPTIONS=	MYSQL "Enable support for MySQL storage" Off \
		PGSQL "Enable support for PostgreSQL" Off \
		FIREBIRD "Enable support for Firebird storage" Off \
		DEBUG   "Build with debug" Off \
		DEBUG_MEMORY "Build with memory debug" Off

MAKE_JOBS_SAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl-incdir=${OPENSSLINC} \
				--with-openssl-libdir=${OPENSSLLIB} \
				--with-apxs=${APXS}
MAKE_ARGS+=	APXS=${APXS}

USE_OPENSSL=	yes
WITH_OPENSSL_PORT=	yes
USE_APACHE=	20+
AP_EXTRAS+=	-DMOD_TSA_VERSION=\\\"mod_tsa/${PORTVERSION}\\\"
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SRC_FILE=	mod_tsa.c tsa_util.c
AP_INC=	${LOCALBASE}/include
AP_LIB=	${LOCALBASE}/lib

PORTEXAMPLES=	*.sql tsa.conf

.include <bsd.port.options.mk>

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--enable-mysql=yes
SRC_FILE+=	db_mysql.c
AP_INC+=	-I${LOCALBASE}/include/mysql
AP_LIB+=	-L${LOCALBASE}/lib/mysql -lmysqlclient
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--enable-pgsql=yes
SRC_FILE+=	db_postgresql.c
AP_LIB+=	-lpq
.endif

.if defined(WITH_FIREBIRD)
USE_FIREBIRD=	yes
CONFIGURE_ARGS+=	--enable-firebird=yes
SRC_FILE+=	db_firebird.c	
AP_LIB+=	-lgds
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--with-debug=yes
.endif

.if defined(WITH_DEBUG_MEMORY)
CONFIGURE_ARGS+=	--with-debug-memory=yes
.endif

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/*.sql ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/tsa.conf ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
