PORTNAME=	rtg
PORTVERSION=	0.7.5
CATEGORIES=	net
MASTER_SITES=	ftp://ftpmirror.uk/freebsd-ports/rtg/

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Flexible, high-performance SNMP statistics monitoring system

LICENSE=	GPLv2

LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp \
		libgd.so:graphics/gd
RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-DBD-mysql>=0:databases/p5-DBD-mysql

USES=		mysql:client perl5 shebangfix ssl
USE_RC_SUBR=	rtgpoll

SHEBANG_FILES=	etc/95.pl etc/report.pl etc/rtgtargmkr.pl.in
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/${PORTNAME} \
			--htmldir=${PREFIX}/www/data \
			--with-mysql=${LOCALBASE} \
			--with-gd=${LOCALBASE} \
			--with-snmp=${LOCALBASE}

CFLAGS+=	-fstack-protector
LDFLAGS+=	-fstack-protector

USERS=		rtg
GROUPS=		rtg

OPTIONS_DEFINE=	WEB MYSQL
MYSQL_DESC=	Pull MySQL server in as a dependancy for local setups
WEB_DESC=	Include PHP-based web client interface pre-requisites

MYSQL_USES=	mysql:server

WEB_USES=		php
WEB_USE=		PHP=mysqli,spl
WEB_SUB_FILES=		pkg-message

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/etc/95.pl
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/etc/report.pl
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/etc/common.php.in

.include <bsd.port.mk>
