# Created by: ubique
# $FreeBSD$

PORTNAME=	mod_tsa
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://am.nesiac.org/static/ \
		http://ubique.spb.ru/src/

MAINTAINER=	ubique@peterhost.ru
COMMENT=	Time stamping authority (RFC 3161) module for apache

OPTIONS_DEFINE=	MYSQL PGSQL FIREBIRD DEBUG DEBUG_MEMORY
DEBUG_MEMORY_DESC=	Memory debug


GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl-incdir=${OPENSSLINC} \
				--with-openssl-libdir=${OPENSSLLIB} \
				--with-apxs=${APXS}
MAKE_ARGS+=	APXS=${APXS}

USE_OPENSSL=	yes
WITH_OPENSSL_PORT=	yes
USE_APACHE=	22+
AP_EXTRAS+=	-DMOD_TSA_VERSION=\\\"mod_tsa/${PORTVERSION}\\\"
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SRC_FILE=	mod_tsa.c tsa_util.c
AP_INC=	${LOCALBASE}/include
AP_LIB=	${LOCALBASE}/lib

PORTEXAMPLES=	*.sql tsa.conf

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--enable-mysql=yes
SRC_FILE+=	db_mysql.c
AP_INC+=	-I${LOCALBASE}/include/mysql
AP_LIB+=	-L${LOCALBASE}/lib/mysql -lmysqlclient
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--enable-pgsql=yes
SRC_FILE+=	db_postgresql.c
AP_LIB+=	-lpq
.endif

.if ${PORT_OPTIONS:MFIREBIRD}
USE_FIREBIRD=	yes
CONFIGURE_ARGS+=	--enable-firebird=yes
SRC_FILE+=	db_firebird.c	
AP_LIB+=	-lgds
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--with-debug=yes
.endif

.if ${PORT_OPTIONS:MDEBUG_MEMORY}
CONFIGURE_ARGS+=	--with-debug-memory=yes
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/*.sql ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/tsa.conf ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
