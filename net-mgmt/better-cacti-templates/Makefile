# New ports collection makefile for:	better-cacti-templates
# Date created:				Sat Aug 27 2011
# Whom:					Alexey V. Degtyarev <alexey@renatasystems.org>
#
# $FreeBSD$

PORTNAME=	better-cacti-templates
PORTVERSION=	1.1.8
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE:S/better/mysql/}

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Better Cacti templates for MySQL, Apache, Memcached, and more

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

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

CACTIDIR?=	share/cacti

.if !defined(NOPORTDOCS)
PORTDOCS=	README Changelog
.endif

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}/${doc}
.endfor
.endif
	${MKDIR} ${PREFIX}/share/cacti/scripts
	${MKDIR} ${PREFIX}/share/better-cacti-templates
	cd ${WRKSRC}
.for dir in definitions misc templates tools
	cd ${WRKSRC} && ${PAX} -r -w ${dir} \
		${PREFIX}/share/better-cacti-templates
.endfor
.for script in ss_get_by_ssh.php ss_get_mysql_stats.php
	${INSTALL_DATA} ${WRKSRC}/scripts/${script} \
		${PREFIX}/share/cacti/scripts/${script}
.endfor

.include <bsd.port.mk>
