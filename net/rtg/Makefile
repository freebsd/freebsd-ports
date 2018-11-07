# Created by: Brad Davis <so14k@so14k.com>
# $FreeBSD$

PORTNAME=	rtg
PORTVERSION=	0.7.4
PORTREVISION=	15
CATEGORIES=	net
MASTER_SITES=	SF \
		ftp://ftpmirror.uk/freebsd-ports/rtg/

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Flexible, high-performance SNMP statistics monitoring system

LICENSE=	GPLv2

LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-DBD-mysql>=0:databases/p5-DBD-mysql

FLAVORS=	web noweb
noweb_PKGNAMESUFFIX=	poller
web_PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

USES=		shebangfix perl5 mysql:client ssl
USE_RC_SUBR=	rtgpoll

SHEBANG_FILES=	etc/95.pl etc/report.pl etc/rtgtargmkr.pl.in
SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/${PORTNAME} \
			--with-mysql=${LOCALBASE} \
			--with-snmp=${LOCALBASE}

USERS=		rtg
GROUPS=		rtg

.if ${FLAVOR:U} == web
USES+=		php:web,flavors
USE_PHP=	mysqli spl
.endif

OPTIONS_DEFINE=	MYSQL
MYSQL_DESC=	Pull MySQL server in as a dependancy for local setups

MYSQL_USES=	mysql:server

CFLAGS+=	-fstack-protector
LDFLAGS+=	-fstack-protector

pre-configure:
	${REINPLACE_CMD} -e 's/my_thread_init/mysql_thread_init/' ${WRKSRC}/configure

post-patch:
	@${MV} ${WRKSRC}/etc/rtg.conf ${WRKSRC}/etc/rtg.conf.sample
	@${MV} ${WRKSRC}/etc/routers ${WRKSRC}/etc/routers.sample
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/etc/95.pl
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/etc/report.pl
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/etc/common.php.in

.include <bsd.port.mk>
