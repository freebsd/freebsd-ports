# New ports collection makefile for:	snort
# Date created:		Mon Aug  2 12:04:08 CEST 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	snort
PORTVERSION=	1.7
CATEGORIES=	security
MASTER_SITES=	http://www.snort.org/Files/ \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/

MAINTAINER=	dirk@FreeBSD.org

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
LIB_DEPENDS+=	pq.2:${PORTSDIR}/databases/postgresql7
CONFIGURE_ARGS+=--with-postgresql=${LOCALBASE}/pgsql
.if exists(/usr/lib/libssl.a) && exists(/usr/lib/libcrypto.a)
LDFLAGS+=	-lssl -lcrypto
.endif
.endif

CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"

pre-configure:
	@${ECHO} ""
	@${ECHO} "Set WITH_FLEXRESP, WITH_MYSQL, WITH_ODBC or WITH_POSTGRES"
	@${ECHO} "to get additional support."
	@${ECHO} ""

post-install:
	${MKDIR} ${PREFIX}/share/snort
.for i in CREDITS RULES.SAMPLE USAGE backdoor-lib ddos-lib finger-lib ftp-lib \
	  misc-lib netbios-lib overflow-lib ping-lib rpc-lib scan-lib smtp-lib \
	  telnet-lib web-lib webcf-lib webcgi-lib webfp-lib webiis-lib webmisc-lib
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/snort
.endfor

.include <bsd.port.mk>
