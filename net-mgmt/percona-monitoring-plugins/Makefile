# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	percona-monitoring-plugins
PORTVERSION=	1.0.2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.percona.com/downloads/percona-monitoring-plugins/ \
		ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Cacti templates for MySQL, Apache, Memcached, and more by Percona

LICENSE=	GPLv2

RUN_DEPENDS=	cacti>=0:${PORTSDIR}/net-mgmt/cacti \
		p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql \
		p5-Data-Dumper>=0:${PORTSDIR}/devel/p5-Data-Dumper \
		p5-Digest-MD5>=0:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-Getopt-Long>=0:${PORTSDIR}/devel/p5-Getopt-Long \
		p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes

USE_MYSQL=	yes
USE_PHP=	yes
WANT_PHP_CLI=	yes

NO_BUILD=	yes
PORTDOCS=	Changelog

CACTIDIR?=	share/cacti

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}/${doc}
.endfor
.endif

	${MKDIR} ${PREFIX}/share/cacti/scripts
	${MKDIR} ${PREFIX}/share/percona-monitoring-plugins

.for dir in definitions misc templates
	cd ${WRKSRC} && ${PAX} -r -w cacti/${dir} \
		${PREFIX}/share/percona-monitoring-plugins
.endfor

.for script in ss_get_by_ssh.php ss_get_mysql_stats.php
	${INSTALL_DATA} ${WRKSRC}/cacti/scripts/${script} \
		${PREFIX}/share/cacti/scripts/${script}
.endfor

	${INSTALL_SCRIPT} ${WRKSRC}/cacti/bin/* ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/nagios/bin/* ${PREFIX}/bin

.include <bsd.port.mk>
