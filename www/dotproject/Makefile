# $FreeBSD$

PORTNAME=	dotproject
PORTVERSION=	2.1.7
PORTREVISION=	1
CATEGORIES=	www devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/dotProject%20Version%20${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Open Source Project Management tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	Does not build

USES=		cpe shebangfix
SHEBANG_FILES=	misc/cvs2cl/cvs2cl.pl
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
USE_PHP=	gd mysql session zlib
WANT_PHP_WEB=	yes
USE_APACHE_RUN=	22+

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	LDAP
OPTIONS_DEFAULT=LDAP
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

LDAP_USE=	PHP=ldap PHP=xml

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -R ${WRKSRC}/* ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
