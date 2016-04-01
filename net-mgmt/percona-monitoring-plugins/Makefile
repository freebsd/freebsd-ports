# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	percona-monitoring-plugins
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.percona.com/downloads/percona-monitoring-plugins/${PORTVERSION}/ \
		ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Cacti templates for MySQL, Apache, Memcached, and more by Percona

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	cacti>=0:net-mgmt/cacti \
		p5-DBD-mysql>=0:databases/p5-DBD-mysql \
		p5-Data-Dumper>=0:devel/p5-Data-Dumper \
		p5-Digest-MD5>=0:security/p5-Digest-MD5 \
		p5-Getopt-Long>=0:devel/p5-Getopt-Long \
		p5-Time-HiRes>=0:devel/p5-Time-HiRes \
		bash:shells/bash

USES=		shebangfix perl5
USE_PERL5=	run
SHEBANG_FILES=	nagios/bin/pmp-check-pt-table-checksum \
		cacti/bin/pmp-cacti-*
USE_MYSQL=	yes
USE_PHP=	yes
WANT_PHP_CLI=	yes

NO_BUILD=	yes
NO_ARCH=	yes
PORTDOCS=	Changelog

CACTIDIR?=	share/cacti

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cacti/scripts
	${MKDIR} ${STAGEDIR}${PREFIX}/share/percona-monitoring-plugins

.for dir in definitions misc templates
	cd ${WRKSRC} && ${PAX} -r -w cacti/${dir} \
		${STAGEDIR}${PREFIX}/share/percona-monitoring-plugins
.endfor

.for script in ss_get_by_ssh.php ss_get_mysql_stats.php
	${INSTALL_DATA} ${WRKSRC}/cacti/scripts/${script} \
		${STAGEDIR}${PREFIX}/share/cacti/scripts/${script}
.endfor

	${INSTALL_SCRIPT} ${WRKSRC}/cacti/bin/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/nagios/bin/* ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}/${doc}
.endfor

.include <bsd.port.mk>
