# New ports collection makefile for:	snort
# Date created:		Mon Aug  2 12:04:08 CEST 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	snort
PORTVERSION=	2.1.0
CATEGORIES=	security
MASTER_SITES=	http://www.snort.org/dl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight network intrusion detection system

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

.if defined(WITH_FLEXRESP)
BUILD_DEPENDS=		${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet
CONFIGURE_ARGS=		--enable-flexresp
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="${LDFLAGS}"
LDFLAGS+=		"-L${LOCALBASE}/lib"
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--with-mysql=no
.endif

.if defined(WITH_ODBC)
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc=${LOCALBASE}
LDFLAGS+=		${PTHREAD_LIBS}
.else
CONFIGURE_ARGS+=	--with-odbc=no
.endif

.if defined(WITH_POSTGRES)
POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS+=		pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
CONFIGURE_ARGS+=	--with-postgresql=${LOCALBASE}
.if exists(/usr/lib/libssl.a) && exists(/usr/lib/libcrypto.a)
LDFLAGS+=		-lssl -lcrypto
.endif
.else
CONFIGURE_ARGS+=	--with-postgresql=no
.endif

MAN8=	snort.8
DOCS=	AUTHORS NEWS README.csv BUGS README README.database \
	CREDITS README.FLEXRESP FAQ snort_manual.pdf \
	README.PLUGINS USAGE README.thresholding README.flow \
	README.flow-portscan README.http_inspect README.wireless

post-patch:
	${REINPLACE_CMD} "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/src/snort.c

pre-configure:
	@${ECHO} ""
	@${ECHO} "Set WITH_FLEXRESP, WITH_MYSQL, WITH_ODBC or WITH_POSTGRES"
	@${ECHO} "to get additional support."
	@${ECHO} ""

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/rules/*.rules ${DATADIR}; \
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
	${INSTALL_DATA} ${FILESDIR}/snort.sh.sample \
		${PREFIX}/etc/rc.d/snort.sh.sample; \
	${INSTALL_DATA} ${WRKSRC}/etc/snort.conf \
		${PREFIX}/etc/snort.conf-sample; \
	if [ ! -f ${PREFIX}/etc/snort.conf ]; then \
	    ${CP} ${PREFIX}/etc/snort.conf-sample \
		${PREFIX}/etc/snort.conf; \
	fi

.include <bsd.port.mk>
