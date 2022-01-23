# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>

PORTNAME=	percona-monitoring-plugins
PORTVERSION=	1.1.8
PORTREVISION=	0
CATEGORIES=	net-mgmt
MASTER_SITES=	https://www.percona.com/downloads/percona-monitoring-plugins/${PORTNAME}-${PORTVERSION}/source/tarball/ \
		ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cacti templates for MySQL, Apache, Memcached, and more by Percona

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Upstream EOL reached on 2020-08-01
EXPIRATION_DATE=	2022-02-22

RUN_DEPENDS=	bash:shells/bash \
		cacti>=0:net-mgmt/cacti \
		p5-DBD-mysql>=0:databases/p5-DBD-mysql \
		wget:ftp/wget

USES=		mysql perl5 php:cli python:run shebangfix
USE_PERL5=	run
SHEBANG_FILES=	cacti/bin/pmp-cacti-* nagios/bin/pmp-check-aws-rds.py \
		nagios/bin/pmp-check-pt-table-checksum

REINPLACE_ARGS=	-i ''
NO_ARCH=	yes

NO_BUILD=	yes
PORTDOCS=	Changelog

OPTIONS_DEFINE=	DOCS

CACTIDIR?=	share/cacti

post-patch:
	@${REINPLACE_CMD} 's|/etc/cacti/|${PREFIX}/etc/cacti/|g' ${WRKSRC}/cacti/scripts/ss_get_mysql_stats.php ${WRKSRC}/cacti/scripts/ss_get_by_ssh.php
	@${REINPLACE_CMD} 's|/etc/nagios/mysql.cnf|${PREFIX}/etc/nagios/mysql.cnf|g' ${WRKSRC}/nagios/bin/pmp-check-mysql-*
	@${REINPLACE_CMD} 's|/usr/bin/php|${PREFIX}/bin/php|g' ${WRKSRC}/zabbix/scripts/get_mysql_stats_wrapper.sh
	@${REINPLACE_CMD} 's|wget|${PREFIX}/bin/wget|g' ${WRKSRC}/cacti/scripts/ss_get_by_ssh.php

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cacti/scripts
	${MKDIR} ${STAGEDIR}${PREFIX}/share/percona-monitoring-plugins
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios

.for dir in definitions misc
	cd ${WRKSRC} && ${PAX} -r -w cacti/${dir} \
		${STAGEDIR}${PREFIX}/share/percona-monitoring-plugins
.endfor

.for script in ss_get_by_ssh.php ss_get_mysql_stats.php
	${INSTALL_DATA} ${WRKSRC}/cacti/scripts/${script} \
		${STAGEDIR}${PREFIX}/share/cacti/scripts/${script}
.endfor

	${INSTALL_SCRIPT} ${WRKSRC}/cacti/bin/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/nagios/bin/* ${STAGEDIR}${PREFIX}/libexec/nagios

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}/${doc}
.endfor

.include <bsd.port.mk>
