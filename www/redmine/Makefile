# New ports collection makefile for:	redmine
# Date created:		2009-02-24
# Whom:			Bernhard Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	redmine
PORTVERSION=	0.8.5
CATEGORIES=	www
MASTER_SITES=	RF

MAINTAINER=	decke@bluelife.at
COMMENT=	A flexible project management web application

USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv
USE_RAKE=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${WWWDIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "*" ${WWWDIR} "! -name *.orig")

	${MKDIR} ${WWWDIR}/public/plugin_assets
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

.for f in files log tmp public/plugin_assets
	${CHMOD} -R 755 ${WWWDIR}/${f}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
