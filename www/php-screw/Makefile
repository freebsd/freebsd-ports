# New ports collection makefile for:	php-screw
# Date created:         Wed May 22 12:21:01 CET 2002
# Whom:                 Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	php-screw
PORTVERSION=	1.2.1
CATEGORIES=	www security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	php_screw-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sysadmin@alexdupre.com

BUILD_DEPENDS=	aclocal:${PORTSDIR}/devel/automake \
		autoconf:${PORTSDIR}/devel/autoconf \
		phpize:${PORTSDIR}/www/mod_php4
RUN_DEPENDS=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13 \
		${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4

PKGMESSAGE=	${WRKDIR}/pkg-message

CRYPTKEY?=	11152, 368, 192, 1281, 62

USE_LIBTOOL=	yes

CONFIGURE_ARGS+=--enable-php_screw=shared \
		--with-php-config=${PREFIX}/bin/php-config

pre-everything:
	@${ECHO} ""
	@${ECHO} "To achieve real security, define your own encryption"
	@${ECHO} "seed key (CRYPTKEY); longer is better."
	@${ECHO} ""
	@${ECHO} "make CRYPTKEY=\"234, 84, 39664, 771, 9853\""
	@${ECHO} ""

post-extract:
	@${ECHO_MSG} "===>  PHPizing for ${PORTNAME}-${PORTVERSION}"
	@(cd ${WRKSRC}; ${LOCALBASE}/bin/phpize)

post-patch:
	@${ECHO} "short pm9screw_mycryptkey[] = { ${CRYPTKEY} };" > \
		${WRKSRC}/my_screw.h

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
	@(cd ${BUILD_WRKSRC}/tools; ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

post-build:
	@${SED} "s|%%LOCALBASE%%|${LOCALBASE}|g;s|%%PREFIX%%|${PREFIX}|g" \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}
do-install:
	@${MKDIR} ${PREFIX}/lib/php/extensions
	@${INSTALL_DATA} ${WRKSRC}/modules/php_screw.so \
		${PREFIX}/lib/php/extensions
	@${INSTALL_PROGRAM} ${WRKSRC}/tools/screw ${PREFIX}/bin

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
