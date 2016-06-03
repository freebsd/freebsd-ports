# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Auth_OpenID
PORTVERSION=	2.1.3
CATEGORIES=	security www pear
MASTER_SITES=	http://openidenabled.com/files/php-openid/packages/
DISTNAME=	php-openid-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP OpenID library v2 for PEAR

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

CONFLICTS=	php-Auth_OpenID-1.*

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING


USES=	tar:bzip2 pear python:build

WRKSRC=		${WRKDIR}/php-openid-${PORTVERSION}

OPTIONS_DEFINE=	BCMATH PEAR_DB
BCMATH_DESC=	Use bcmath instead of libgmp
PEAR_DB_DESC=	Support SQL stores

USE_PHP=	curl dom

PEAR_DB_BUILD_DEPENDS=	${PEARDIR}/DB.php:databases/pear-DB
PEAR_DB_RUN_DEPENDS=	${PEARDIR}/DB.php:databases/pear-DB

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBCMATH}
USE_PHP+=	bcmath
.else
USE_PHP+=	gmp
.endif


post-configure:
	@cd ${WRKSRC}/admin && ${PYTHON_CMD} packagexml.py ${PORTVERSION} package2.xml ../CHANGELOG > ${WRKDIR}/package.xml

.include <bsd.port.mk>
