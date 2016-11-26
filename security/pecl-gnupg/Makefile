# Created by: mnag@FreeBSD.org
# $FreeBSD$

PORTNAME=	gnupg
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PECL wrapper around the gpgme library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgpgme.so:security/gpgme

CONFIGURE_ARGS=	--with-gnupg=${LOCALBASE}/include
USES=		localbase php:ext tar:tgz

post-patch:
	@${REINPLACE_CMD} -e '/GNUPG_DL/ s|-ldl||; s|$$GNUPG_DIR/lib|${LOCALBASE}/lib|' ${WRKSRC}/config.m4

.include <bsd.port.mk>
