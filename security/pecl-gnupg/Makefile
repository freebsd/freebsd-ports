# Created by: mnag@FreeBSD.org
# $FreeBSD$

PORTNAME=	gnupg
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PECL wrapper around the gpgme library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgpgme.so:${PORTSDIR}/security/gpgme

CONFIGURE_ARGS=	--with-gnupg=${LOCALBASE}/include/gpgme
USE_PHP=	yes
USE_PHPEXT=	yes
USES=		localbase tar:tgz

post-patch:
	@${REINPLACE_CMD} -e 's|$$GNUPG_DIR/lib|${LOCALBASE}/lib|; s| -ldl||g' ${WRKSRC}/config.m4

.include <bsd.port.mk>
