# New ports collection makefile for:	nedi
# Date created:				2007-02-04
# Whom:					cristi
#
# $FreeBSD$
#

PORTNAME=	nedi
DISTVERSION=	1.0.w
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/w
EXTRACT_SUFX=	.tgz

MAINTAINER=	cristi@net.utcluj.ro
COMMENT=	Network Discovery and Monitoring tool

RUN_DEPENDS=	${SITE_PERL}/Net/SNMP.pm:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
		${SITE_PERL}/Net/Telnet/Cisco.pm:${PORTSDIR}/net-mgmt/p5-Telnet-Cisco \
		${SITE_PERL}/Algorithm/Diff.pm:${PORTSDIR}/devel/p5-Algorithm-Diff \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
USE_PERL5=	yes

# The options part is copied from databases/phpmyadmin
# and looks this way, because we have to USE_PHP
# before pre.mk, however WITH_*, WITHOUT_* are set only
# after pre.mk. The solution is to set them by ourselves.
OPTIONS=	GD "Use GD" OFF

PORT_DBDIR?=	/var/db/ports
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
OPTIONSFILE?=	${PORT_DBDIR}/${LATEST_LINK}/options

.if exists(${OPTIONSFILE})
.include "${OPTIONSFILE}"
.endif

USE_PHP=	session snmp mysql
WANT_PHP_WEB=	yes

.if defined(WITH_GD) && !defined(WITHOUT_GD)
USE_PHP+=	gd
.endif

NEDIDIR=	${PREFIX}/www/nedi

SUB_FILES=	pkg-message
SUB_LIST=	NEDIDIR=${NEDIDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|/var/nedi|${NEDIDIR}|' ${WRKSRC}/html/inc/libgraph.php
	@${REINPLACE_CMD} -e "s|'/etc|'${PREFIX}/etc|" ${WRKSRC}/html/inc/libmisc.php
	@${FIND} ${WRKSRC} -name *.bak -or -name *.orig | ${XARGS} ${RM}

do-install:
	@ ${MKDIR} -m 755 ${NEDIDIR}
	@ ${CP} -r ${WRKSRC}/* ${NEDIDIR}
	@ ${MV} ${NEDIDIR}/seedlist ${PREFIX}/etc/nedi.seedlist.sample
	@ ${MV} ${NEDIDIR}/nedi.conf ${PREFIX}/etc/nedi.conf.sample
	@ ${CHOWN} www ${NEDIDIR}/rrd

post-install:
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
