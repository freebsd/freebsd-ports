# Ports collection makefile for:  pear-gnupg
# Date created:			  16 March 2006
# Whom:				  mnag@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnupg
PORTVERSION=	1.3.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	A pecl wrapper around the gpgme library

LIB_DEPENDS=	gpgme.18:${PORTSDIR}/security/gpgme

USE_PHP=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	gnupg

CONFIGURE_ARGS=	--with-gnupg=${LOCALBASE}/include/gpgme
CFLAGS+=		-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e "s|\$$GNUPG_DIR/lib|${LOCALBASE}/lib|" -e "s|-ldl||g" \
		${WRKSRC}/config.m4

.include <bsd.port.mk>
