# Created by: Brad Davis <so14k@so14k.com>
# $FreeBSD$

PORTNAME=	rtg
PORTVERSION=	0.7.4
PORTREVISION=	11
CATEGORIES=	net
MASTER_SITES=	SF \
		ftp://ftpmirror.uk/freebsd-ports/rtg/

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Flexible, high-performance SNMP statistics monitoring system

LICENSE=	GPLv2

LIB_DEPENDS=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp
RUN_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql

USE_RC_SUBR=	rtgpoll
USE_MYSQL=	client
WANT_PERL=	yes
USES=		shebangfix
SHEBANG_FILES=	etc/95.pl etc/report.pl
SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/${PORTNAME} \
			--with-mysql=${LOCALBASE} \
			--with-snmp=${LOCALBASE}
OPTIONS_DEFINE=	WEB MYSQL
OPTIONS_DEFAULT=WEB
MYSQL_DESC=	Pull MySQL server in as a dependancy for local setups
WEB_DESC=	Include PHP-based web client interface pre-requisites

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
.endif

.if ${PORT_OPTIONS:MWEB}
WANT_PHP_WEB=	yes
USE_PHP=	mysqli spl
.endif

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} >= 800040 )
CFLAGS+=	-fstack-protector
LDFLAGS+=	-fstack-protector
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's,-pthread,${PTHREAD_LIBS},g' ${WRKSRC}/configure

post-patch:
	@${MV} ${WRKSRC}/etc/rtg.conf ${WRKSRC}/etc/rtg.conf.sample
	@${MV} ${WRKSRC}/etc/routers ${WRKSRC}/etc/routers.sample

.include <bsd.port.post.mk>
