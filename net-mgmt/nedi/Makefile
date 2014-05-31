# Created by: cristi <cristi@net.utcluj.ro>
# $FreeBSD$

PORTNAME=	nedi
DISTVERSION=	1.0.w
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/w

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network Discovery and Monitoring tool

RUN_DEPENDS=	p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
		p5-Net-Telnet-Cisco>=0:${PORTSDIR}/net-mgmt/p5-Telnet-Cisco \
		p5-Algorithm-Diff>=0:${PORTSDIR}/devel/p5-Algorithm-Diff \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		tar:tgz perl5 shebangfix
SHEBANG_FILES= *.pl
NO_BUILD=	yes

USE_PHP=	session snmp mysql
WANT_PHP_WEB=	yes

OPTIONS_DEFINE=	GD

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGD}
USE_PHP+=	gd
.endif

SUB_FILES=	pkg-message
PLIST_SUB+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

post-patch:
	@${REINPLACE_CMD} -e 's|/var/nedi|${WWWDIR}|' ${WRKSRC}/html/inc/libgraph.php
	@${REINPLACE_CMD} -e "s|'/etc|'${PREFIX}/etc|" ${WRKSRC}/html/inc/libmisc.php
	@${FIND} ${WRKSRC} \( -name *.bak -or -name *.orig \) -delete

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	${FIND} ${STAGEDIR}${WWWDIR} -name \*.pl | ${XARGS} ${CHMOD} 755
	${MV} ${STAGEDIR}${WWWDIR}/seedlist ${STAGEDIR}${PREFIX}/etc/nedi.seedlist.sample
	${MV} ${STAGEDIR}${WWWDIR}/nedi.conf ${STAGEDIR}${PREFIX}/etc/nedi.conf.sample

.include <bsd.port.mk>
