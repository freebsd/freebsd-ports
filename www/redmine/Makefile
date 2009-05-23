# New ports collection makefile for:	redmine
# Date created:		2009-02-24
# Whom:			Bernahrd Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	redmine
PORTVERSION=	0.8.4
CATEGORIES=	www
MASTER_SITES=	RF

MAINTAINER=	decke@bluelife.at
COMMENT=	A flexible project management web application

RUN_DEPENDS=	${LOCALBASE}/bin/rails:${PORTSDIR}/www/rubygem-rails

USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv
USE_RAKE=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${WWWDIR}
	${CP} -pR ${WRKSRC}/ ${WWWDIR}
	${MKDIR} ${WWWDIR}/public/plugin_assets
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

	for f in files log tmp public/plugin_assets; do \
		${CHMOD} -R 755 ${WWWDIR}/$$f; \
	done

.include <bsd.port.mk>
