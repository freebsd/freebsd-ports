# Ports collection makefile for:  pear-Crypt_CBC
# Date created:			  28 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Crypt_CBC
PORTVERSION=	0.3
CATEGORIES=	security www
MASTER_SITES=	http://pear.php.net/get/
PKGNAMEPREFIX=	pear-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PEAR

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${PEARDIR}.DIST_PHP:${PORTSDIR}/devel/pear-install
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_BUILD=	yes

LPHP_LIB=	lib/php
PEARDIR=	${LOCALBASE}/${LPHP_LIB}
PLIST_SUB=	PEARDIR=${LPHP_LIB}

do-install:
	@${MKDIR} ${PEARDIR}/Crypt
	@${CP} -Rp ${WRKSRC}/CBC.php ${PEARDIR}/Crypt
#Note: HCEMD5.php is still needed for IMP 3.1,
#	but should be removed with the next releases.
	@${CP} -p ${FILESDIR}/Crypt_HCEMD5.php ${PEARDIR}/Crypt/HCEMD5.php
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Crypt

.include <bsd.port.mk>
