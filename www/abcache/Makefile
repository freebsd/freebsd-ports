# New ports collection makefile for:	abcache
# Date created:         Sat Feb 23 14:27:35 CET 2002
# Whom:                 Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	abcache
PORTVERSION=	0.14
CATEGORIES=	www
MASTER_SITES=	http://afterburner.bware.it/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sysadmin@alexdupre.com

BUILD_DEPENDS=	aclocal:${PORTSDIR}/devel/automake \
		autoconf:${PORTSDIR}/devel/autoconf \
		phpize:${PORTSDIR}/www/mod_php4
RUN_DEPENDS=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13 \
		${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4

USE_LIBTOOL=	yes
LIBTOOLFILES=	aclocal.m4

WRKSRC=		${WRKDIR}/bware_cache-${PORTVERSION}

CONFIGURE_ARGS+=--enable-bware_cache=shared \
		--with-php-config=${PREFIX}/bin/php-config

post-extract:
	@${ECHO_MSG} "===>  PHPizing for ${DISTNAME}"
	@cd ${WRKSRC} && ${LOCALBASE}/bin/phpize

do-install:
	@${INSTALL} ${WRKSRC}/modules/bware_cache.so \
		${LOCALBASE}/lib/php/20010901

post-install:
	@${SED} s!%%LOCALBASE%%!${LOCALBASE}!g ${PKGMESSAGE}

.include <bsd.port.mk>
