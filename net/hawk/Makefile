# New ports collection makefile for:	hawk
# Date created:				12 February 2003
# Whom:					dougb
#
# $FreeBSD$
#

PORTNAME=	hawk
PORTVERSION=	0.6
CATEGORIES=	net
MASTER_SITES=	http://umn.dl.sourceforge.net/sourceforge/iphawk/ \
		http://unc.dl.sourceforge.net/sourceforge/iphawk/

MAINTAINER=	DougB@FreeBSD.org
COMMENT=	Track uptime and DNS status for machines on your networks

RUN_DEPENDS=	php-config:${PORTSDIR}/www/mod_php4 \
		safe_mysqld:${PORTSDIR}/databases/mysql323-server \
		${SITE_PERL}/Net/Netmask.pm:${PORTSDIR}/net/p5-Net-Netmask

do-patch:
	@${SED} -e 's#dirname.*"/hawk#"${PREFIX}/etc/hawk/daemon#' \
		${WRKSRC}/daemon/hawk > ${WRKSRC}/daemon/hawk.sed
	@${MV} ${WRKSRC}/daemon/hawk.sed ${WRKSRC}/daemon/hawk
	@${SED} -e 's#hawk.conf#daemon.conf#' \
		${WRKSRC}/php/hawk.conf.inc > ${WRKSRC}/php/hawk.conf.inc.sed
	@${MV} ${WRKSRC}/php/hawk.conf.inc.sed ${WRKSRC}/php/hawk.conf.inc
	@${SED} -e 's#hawk.conf.inc#${PREFIX}/etc/hawk/php.conf#' \
		${WRKSRC}/php/hawk.php > ${WRKSRC}/php/hawk.php.sed
	@${MV} ${WRKSRC}/php/hawk.php.sed ${WRKSRC}/php/hawk.php

do-build:
# Empty target, nothing to build

do-install:
	${MKDIR} ${PREFIX}/etc/hawk
	${INSTALL_DATA} ${WRKSRC}/daemon/hawk.conf ${PREFIX}/etc/hawk/daemon.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/daemon/hawk ${PREFIX}/sbin
	${MKDIR} ${PREFIX}/www/data-dist/hawk/images
	(for file in ${WRKSRC}/php/images/*; do \
		${INSTALL_DATA} $$file ${PREFIX}/www/data-dist/hawk/images; \
	done)
	${INSTALL_DATA} ${WRKSRC}/php/hawk.php ${PREFIX}/www/data-dist/hawk
	${INSTALL_DATA} ${WRKSRC}/php/hawk.css ${PREFIX}/www/data-dist/hawk
	${INSTALL_DATA} ${WRKSRC}/php/hawk.conf.inc \
		${PREFIX}/etc/hawk/php.conf.sample
	${SED} -e 's#%%PREFIX%%#${PREFIX}#' ${FILESDIR}/hawk.sh > \
		${WRKDIR}/hawk.sh.sample
	${INSTALL_SCRIPT} ${WRKDIR}/hawk.sh.sample ${PREFIX}/etc/rc.d
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/create_hawk_db.sql ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/create_hawk_user.sql ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
