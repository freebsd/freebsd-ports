# Ports collection makefile for:  pear-Crypt_CBC
# Date created:			  28 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Crypt_CBC
PORTVERSION=	0.4
CATEGORIES=	security www
MASTER_SITES=	http://pear.php.net/get/
PKGNAMEPREFIX=	pear-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PEAR

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR class to emulate Perl's Crypt::CBC module

BUILD_DEPENDS=	${PEARDIR}/PEAR.php.dist:${PORTSDIR}/devel/pear-PEAR
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
PEARDIR=	${PHP_BASE}/${LPHP_LIB}
PLIST_SUB=	PEARDIR=${LPHP_LIB}

do-install:
	@${MKDIR} ${PEARDIR}/Crypt
	@${CP} -Rp ${WRKSRC}/CBC.php ${PEARDIR}/Crypt
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Crypt

post-install:
# Register a new package
	@${PEAR} install -r -f ${WRKDIR}/package.xml

.include <bsd.port.post.mk>
