# Created by: Brad Davis <so14k@so14k.com>
# $FreeBSD$

PORTNAME=	rtg
PORTVERSION=	0.7.4
PORTREVISION=	13
CATEGORIES=	net
MASTER_SITES=	SF \
		ftp://ftpmirror.uk/freebsd-ports/rtg/

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Flexible, high-performance SNMP statistics monitoring system

LICENSE=	GPLv2

LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-DBD-mysql>=0:databases/p5-DBD-mysql

USE_RC_SUBR=	rtgpoll
WANT_PERL=	yes
USES=		shebangfix mysql:client
SHEBANG_FILES=	etc/95.pl etc/report.pl etc/rtgtargmkr.pl.in
SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/${PORTNAME} \
			--with-mysql=${LOCALBASE} \
			--with-snmp=${LOCALBASE}

USERS=		rtg
GROUPS=		rtg

OPTIONS_DEFINE=	WEB MYSQL
OPTIONS_DEFAULT=WEB
MYSQL_DESC=	Pull MySQL server in as a dependancy for local setups
WEB_DESC=	Include PHP-based web client interface pre-requisites

MYSQL_USES=	mysql:server

WEB_USES=	php
USE_PHP=	mysqli spl

CFLAGS+=	-fstack-protector
LDFLAGS+=	-fstack-protector

post-patch:
	@${MV} ${WRKSRC}/etc/rtg.conf ${WRKSRC}/etc/rtg.conf.sample
	@${MV} ${WRKSRC}/etc/routers ${WRKSRC}/etc/routers.sample

.include <bsd.port.mk>
