# Created by: girgen@FreeBSD.org
# $FreeBSD$

PORTNAME=	krb5
PORTVERSION=	1.1.1
CATEGORIES=	security pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	PECL classes for PAM integration

LICENSE= 	BSD3CLAUSE

LIB_DEPENDS=	libkrb5support.so:security/krb5

USES=		php:ext tar:tgz

CONFIGURE_ARGS=	--with-krb5config=${LOCALBASE}/bin/krb5-config

.include <bsd.port.mk>
