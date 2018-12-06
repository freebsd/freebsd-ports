# Created by: Cristian KLEIN <cristi@net.utcluj.ro>
# $FreeBSD$

PORTNAME=	nedi
DISTVERSION=	1.0.w
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/w

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network discovery and monitoring tool

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	GPLv2

IGNORE_WITH_PHP=	71 72 73

RUN_DEPENDS=	p5-Net-SNMP>=0:net-mgmt/p5-Net-SNMP \
		p5-Net-Telnet-Cisco>=0:net-mgmt/p5-Telnet-Cisco \
		p5-Algorithm-Diff>=0:devel/p5-Algorithm-Diff \
		p5-DBI>=0:databases/p5-DBI

USES=		php:web perl5 shebangfix tar:tgz
SHEBANG_FILES=	*.pl html/inc/Devsend.pl
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

USE_PHP=	session snmp mysql

SUB_FILES=	pkg-message
PLIST_SUB+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

OPTIONS_DEFINE=	GD
GD_USE=		PHP=gd

post-patch:
	@${REINPLACE_CMD} -e 's|/var/nedi|${WWWDIR}|' \
		${WRKSRC}/html/inc/libgraph.php
	@${REINPLACE_CMD} -e "s|'/etc|'${PREFIX}/etc|" \
		${WRKSRC}/html/inc/libmisc.php
	@${FIND} ${WRKSRC} \( -name *.bak -or -name *.orig \) -delete

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	${FIND} ${STAGEDIR}${WWWDIR} -name \*.pl | ${XARGS} ${CHMOD} 755
	${MV} ${STAGEDIR}${WWWDIR}/seedlist \
		${STAGEDIR}${PREFIX}/etc/nedi.seedlist.sample
	${MV} ${STAGEDIR}${WWWDIR}/nedi.conf \
		${STAGEDIR}${PREFIX}/etc/nedi.conf.sample

.include <bsd.port.mk>
