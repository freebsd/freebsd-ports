# Ports collection makefile for:  pear-File
# Date created:			  24 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	File
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	sysutils www
MASTER_SITES=	http://pear.php.net/get/
PKGNAMEPREFIX=	pear-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PEAR

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR common file and directory routines

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

do-install:
	@${CP} -Rp ${WRKSRC}/* ${PEARDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/${PORTNAME}*
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/tests

post-install:
# Register a new package
	@${PEAR} install -r -f ${WRKDIR}/package.xml

.include <bsd.port.post.mk>
