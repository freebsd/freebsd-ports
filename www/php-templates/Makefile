# New ports collection makefile for:	php_templates
# Date created:				Feb 28 2002
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	php-templates
PORTVERSION=	0.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	php_templates-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	aclocal:${PORTSDIR}/devel/automake \
		autoconf:${PORTSDIR}/devel/autoconf \
		phpize:${PORTSDIR}/www/mod_php4
RUN_DEPENDS=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13 \
		${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4

USE_LIBTOOL=	yes
LIBTOOLFILES=	aclocal.m4

WRKSRC=		${WRKDIR}/templates

CONFIGURE_ARGS+=--enable-templates=shared \
		--with-php-config=${PREFIX}/bin/php-config

post-extract:
	@${ECHO_MSG} "===>  PHPizing for ${DISTNAME}"
	@cd ${WRKSRC} && ${LOCALBASE}/bin/phpize

do-install:
	@${INSTALL} ${WRKSRC}/modules/templates.so \
		${LOCALBASE}/lib/php/20010901

post-install:
	@${SED} s!%%LOCALBASE%%!${LOCALBASE}!g ${PKGMESSAGE}

.include <bsd.port.mk>
