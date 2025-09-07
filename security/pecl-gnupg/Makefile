PORTNAME=	gnupg
PORTVERSION=	1.5.4
CATEGORIES=	security

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PECL wrapper around the gpgme library
WWW=		https://pecl.php.net/package/gnupg \
		https://github.com/php-gnupg/php-gnupg

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgpgme.so:security/gpgme

USES=		localbase php:pecl

CONFIGURE_ARGS=	--with-gnupg=${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} -e '/GNUPG_DL/ s|-ldl||; s|$$GNUPG_DIR/lib|${LOCALBASE}/lib|' ${WRKSRC}/config.m4

.include <bsd.port.mk>
