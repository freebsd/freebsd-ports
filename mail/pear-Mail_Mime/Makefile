# Ports collection makefile for:  pear-Mail_Mime
# Date created:			  24 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Mail_Mime
PORTVERSION=	1.2.1
CATEGORIES=	mail www
MASTER_SITES=	http://pear.php.net/get/
PKGNAMEPREFIX=	pear-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PEAR

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${PEARDIR}.DIST_PHP:${PORTSDIR}/devel/pear-install
RUN_DEPENDS=	${PEARDIR}.DIST_PHP:${PORTSDIR}/devel/pear-install

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/php-config)
PHP_BASE!=	${LOCALBASE}/bin/php-config --prefix
.endif
LPHP_LIB=	lib/php
PEARDIR=	${PHP_BASE}/${LPHP_LIB}
PLIST_SUB=	PEARDIR=${LPHP_LIB}

do-install:
	@${CP} -Rp ${WRKSRC}/* ${PEARDIR}/Mail
	@${CHOWN} -R root:wheel ${PEARDIR}/Mail/*
.for BUGMODE in mimeDecode.php mimePart.php xmail.dtd xmail.xsl
	@${CHMOD} a-x ${PEARDIR}/Mail/${BUGMODE}
.endfor

.include <bsd.port.post.mk>
