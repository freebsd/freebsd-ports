# Ports collection makefile for:  pear-Auth_SASL
# Date created:			  2 February 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Auth_SASL
PORTVERSION=	1.0.0
CATEGORIES=	security www
MASTER_SITES=	http://pear.php.net/get/
PKGNAMEPREFIX=	pear-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PEAR

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR abstraction of various SASL mechanism responses

BUILD_DEPENDS=	${PEARDIR}/PEAR.php.dist:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/php-config)
PHP_BASE!=	${LOCALBASE}/bin/php-config --prefix
.else
PHP_BASE!=	${LOCALBASE}
.endif
PEAR=		${LOCALBASE}/bin/pear
LPHP_LIB=	lib/php
PEARDIR=	${PHP_BASE}/${LPHP_LIB}
PLIST_SUB=	PEARDIR=${LPHP_LIB}

MANIFEST=	SASL.php SASL

do-install:
.for FILE in ${MANIFEST}
	@${CP} -Rp ${WRKSRC}/${FILE} ${PEARDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/${FILE}
.endfor
	@${CHMOD} a-x ${PEARDIR}/SASL/*
	@${CHMOD} a-x ${PEARDIR}/SASL.php

post-install:
# Register a new package
	@${PEAR} install -r -f ${WRKDIR}/package.xml

.include <bsd.port.post.mk>
