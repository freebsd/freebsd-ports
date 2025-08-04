PORTNAME=	krb5
PORTVERSION=	1.2.4
CATEGORIES=	security pear

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	PECL classes for PAM integration
WWW=		https://pecl.php.net/package/krb5

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libkrb5support.so:security/krb5

USES=		php:pecl

CONFIGURE_ARGS=	--with-krb5config=${LOCALBASE}/bin/krb5-config

.include <bsd.port.mk>
