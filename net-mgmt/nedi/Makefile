# Created by: cristi <cristi@net.utcluj.ro>
# $FreeBSD$

PORTNAME=	nedi
DISTVERSION=	1.0.w
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/w
EXTRACT_SUFX=	.tgz

MAINTAINER=	cristi@net.utcluj.ro
COMMENT=	Network Discovery and Monitoring tool

RUN_DEPENDS=	p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
		p5-Net-Telnet-Cisco>=0:${PORTSDIR}/net-mgmt/p5-Telnet-Cisco \
		p5-Algorithm-Diff>=0:${PORTSDIR}/devel/p5-Algorithm-Diff \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		perl5
NO_BUILD=	yes

OPTIONS_DEFINE=	GD
GD_DESC=	Use GD

LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.options.mk>

USE_PHP=	session snmp mysql
WANT_PHP_WEB=	yes

.if ${PORT_OPTIONS:MGD}
USE_PHP+=	gd
.endif

NEDIDIR=	${PREFIX}/www/nedi

SUB_FILES=	pkg-message
SUB_LIST=	NEDIDIR=${NEDIDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|/var/nedi|${NEDIDIR}|' ${WRKSRC}/html/inc/libgraph.php
	@${REINPLACE_CMD} -e "s|'/etc|'${PREFIX}/etc|" ${WRKSRC}/html/inc/libmisc.php
	@${FIND} ${WRKSRC} \( -name *.bak -or -name *.orig \) -delete

do-install:
	@ ${MKDIR} -m 755 ${NEDIDIR}
	@ ${CP} -r ${WRKSRC}/* ${NEDIDIR}
	@ ${MV} ${NEDIDIR}/seedlist ${PREFIX}/etc/nedi.seedlist.sample
	@ ${MV} ${NEDIDIR}/nedi.conf ${PREFIX}/etc/nedi.conf.sample
	@ ${CHOWN} www ${NEDIDIR}/rrd

post-install:
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
