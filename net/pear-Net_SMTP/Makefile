# Ports collection makefile for:  pear-Net_SMTP
# Date created:			  26 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Net_SMTP
PORTVERSION=	1.1.1
CATEGORIES=	net mail www
MASTER_SITES=	http://pear.php.net/get/
PKGNAMEPREFIX=	pear-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PEAR

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR class that provides an implementation of the SMTP protocol

BUILD_DEPENDS=	${PEARDIR}/SASL.php:${PORTSDIR}/security/pear-Auth_SASL
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/php-config)
PHP_BASE!=	${LOCALBASE}/bin/php-config --prefix
.else
PHP_BASE=	${LOCALBASE}
.endif
PEAR=		${LOCALBASE}/bin/pear
LPHP_LIB=	lib/php
PEARDIR=	${LOCALBASE}/${LPHP_LIB}
PLIST_SUB=	PEARDIR=${LPHP_LIB}
MANIFEST=	Net/SMTP.php

do-install:
	@${MV} ${PEARDIR}/${MANIFEST} ${PEARDIR}/${MANIFEST}.dist
	@${CP} -p ${WRKSRC}/SMTP.php ${PEARDIR}/Net
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/${MANIFEST}

post-install:
# Register an upgraded package
	@${PEAR} upgrade -r -f ${WRKDIR}/package.xml

.include <bsd.port.post.mk>
