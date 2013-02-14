# New ports collection makefile for:    newrelic-php5
# Date created:                         2 February 2012
# Whom:					mitsuruy@reallyenglish.com
#
# $FreeBSD$
#

PORTNAME=	newrelic-php5
PORTVERSION=	2.6.5.57
DISTVERSIONSUFFIX=	-freebsd
PORTREVISION=	3
CATEGORIES=	www
# XXX when the version is the latest one, /php_agent/release/${PKGNAME}
# MASTER_SITES=	http://download.newrelic.com/php_agent/release/
# but when it's not, /php_agent/archive/${PORTVERSION}/${PKGNAME}
MASTER_SITES=	http://download.newrelic.com/php_agent/archive/${PORTVERSION}/

MAINTAINER=	mitsuruy@reallyenglish.com
COMMENT=	PHP Agent for The New Relic Server Monitor

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

ONLY_FOR_ARCHS=	i386 amd64

USE_PHP=	yes

NO_BUILD=	yes

SUB_FILES=	pkg-message

pre-install:
	${REINPLACE_CMD} -e 's@%%PREFIX%%@${PREFIX}@g' ${WRKSRC}/newrelic-install ${WRKSRC}/scripts/init.freebsd

do-install:
	@${MKDIR} ${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${MKDIR} ${PREFIX}/etc/php
	@cd ${WRKSRC} ; ${SETENV} "NR_INSTALL_SILENT=y" "NR_INSTALL_KEY=Put_your_license_key_here" "NR_INSTALL_INITFILE=${PREFIX}/etc/rc.d/newrelic-daemon" "NR_INSTALL_DAEMONPATH=${PREFIX}/bin/newrelic-daemon" "NR_INSTALL_USE_CP_NOT_LN=y" ./newrelic-install install

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
