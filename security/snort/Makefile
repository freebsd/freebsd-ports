# New ports collection makefile for:	snort
# Date created:		Mon Aug  2 12:04:08 CEST 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	snort
PORTVERSION=	1.9.0
CATEGORIES=	security
MASTER_SITES=	http://www.snort.org/dl/

MAINTAINER=	kris@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mysql=no --with-odbc=no --with-postgresql=no
MAN8=		snort.8

.if defined(WITH_FLEXRESP)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet
CONFIGURE_ARGS+=--enable-flexresp
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"
LDFLAGS+=	"-L${LOCALBASE}/lib"
.endif

.if defined(WITH_MYSQL)
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ARGS+=--with-mysql=${LOCALBASE}
.endif

.if defined(WITH_ODBC)
LIB_DEPENDS+=	odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=--with-odbc=${LOCALBASE}
LDFLAGS+=	${PTHREAD_LIBS}
.endif

.if defined(WITH_POSTGRES)
POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS+=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
CONFIGURE_ARGS+=--with-postgresql=${LOCALBASE}/pgsql
.if exists(/usr/lib/libssl.a) && exists(/usr/lib/libcrypto.a)
LDFLAGS+=	-lssl -lcrypto
.endif
.endif

CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/src/snort.c

pre-configure:
	@${ECHO} ""
	@${ECHO} "Set WITH_FLEXRESP, WITH_MYSQL, WITH_ODBC or WITH_POSTGRES"
	@${ECHO} "to get additional support."
	@${ECHO} ""

DOCS=	AUTHORS NEWS README.csv BUGS README README.database \
	CREDITS README.SNMP README.xml README.FLEXRESP RULES.todo FAQ \
	SnortUsersManual.pdf README.PLUGINS USAGE

post-install:
	${MKDIR} ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif
	@${INSTALL_DATA} ${WRKSRC}/rules/*.rules ${DATADIR}; \
	${INSTALL_DATA} ${WRKSRC}/etc/classification.config ${DATADIR}/classification.config-sample; \
	if [ ! -f ${DATADIR}/classification.config ]; then \
	    ${CP} ${DATADIR}/classification.config-sample \
		${DATADIR}/classification.config; \
	fi; \
	${INSTALL_DATA} ${WRKSRC}/etc/reference.config \
		${DATADIR}/reference.config-sample; \
	if [ ! -f ${DATADIR}/reference.config ]; then \
	    ${CP} ${DATADIR}/reference.config-sample \
		${DATADIR}/reference.config; \
	fi; \
	${INSTALL_DATA} ${WRKSRC}/etc/snort.conf \
		${PREFIX}/etc/snort.conf-sample; \
	if [ ! -f ${PREFIX}/etc/snort.conf ]; then \
	    ${CP} ${PREFIX}/etc/snort.conf-sample \
		${PREFIX}/etc/snort.conf; \
	fi

.include <bsd.port.mk>
