# New ports collection makefile for:	php_templates
# Date created:				Feb 28 2002
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	php-templates
PORTVERSION=	1.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	php_templates-${PORTVERSION}

MAINTAINER=	sysadmin@alexdupre.com

BUILD_DEPENDS=	aclocal:${PORTSDIR}/devel/automake \
		autoconf:${PORTSDIR}/devel/autoconf \
		phpize:${PORTSDIR}/www/mod_php4
RUN_DEPENDS=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13 \
		${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4

USE_LIBTOOL=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/templates

CONFIGURE_ARGS=	--enable-templates=shared \
		--with-php-config=${PREFIX}/bin/php-config

PKGMESSAGE=	${WRKDIR}/pkg-message

post-extract:
	@${REINPLACE_CMD} -e 's/[[:cntrl:]]$$//' ${WRKSRC}/php_templates.h \
		${WRKSRC}/templates.c ${WRKSRC}/tmpl_lib.c
	@${ECHO_MSG} "===>  PHPizing for ${DISTNAME}"
	@cd ${WRKSRC} && ${LOCALBASE}/bin/phpize

post-build:
	@${SED} "s|%%LOCALBASE%%|${LOCALBASE}|g;s|%%PREFIX%%|${PREFIX}|g" \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${PREFIX}/lib/php/extensions
	@${INSTALL_DATA} ${WRKSRC}/modules/templates.so \
		${PREFIX}/lib/php/extensions

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
