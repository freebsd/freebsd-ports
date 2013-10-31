# $FreeBSD$

PORTNAME=	dotproject
PORTVERSION=	2.1.7
CATEGORIES=	www devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/dotProject%20Version%20${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Open Source Project Management tool

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
USE_PHP=	gd mysql session zlib
WANT_PHP_WEB=	yes
USE_APACHE_RUN=	22+
NEED_ROOT=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	LDAP
OPTIONS_DEFAULT=LDAP

LDAP_USE=	PHP=ldap PHP=xml

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -R ${WRKSRC}/* ${STAGEDIR}${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
