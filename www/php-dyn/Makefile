# New ports collection makefile for:	php-dyn
# Date created:         Wed May 22 14:27:22 CET 2002
# Whom:                 Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	php-dyn
PORTVERSION=	1.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	php_dyn-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sysadmin@alexdupre.com

BUILD_DEPENDS=	aclocal:${PORTSDIR}/devel/automake \
		autoconf:${PORTSDIR}/devel/autoconf \
		phpize:${PORTSDIR}/www/mod_php4
RUN_DEPENDS=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13 \
		${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-php_dyn=shared \
		--with-php-config=${LOCALBASE}/bin/php-config

PKGMESSAGE=	${WRKDIR}/pkg-message

post-extract:
	@${ECHO_MSG} "===>    PHPizing for ${PORTNAME}-${PORTVERSION}"
	@(cd ${WRKSRC}; ${LOCALBASE}/bin/phpize)

post-build:
	@${SED} "s|%%LOCALBASE%%|${LOCALBASE}|g;s|%%PREFIX%%|${PREFIX}|g" \
		${FILESDIR}/pkg-message.in > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${PREFIX}/lib/php/extensions
	@${INSTALL_DATA} ${WRKSRC}/modules/php_dyn.so \
		${PREFIX}/lib/php/extensions
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.en ${DOCSDIR}/README
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
