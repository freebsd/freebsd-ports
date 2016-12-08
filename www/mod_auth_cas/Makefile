# Created by: Kimo <kimor79@yahoo.com>
# $FreeBSD$

PORTNAME=	mod_auth_cas
PORTVERSION=	1.0.9.1
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache 2.x module that supports the CASv1 and CASv2 protocols

LICENSE=	APACHE20

LIB_DEPENDS=	libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	Jasig

WRKSRC_SUBDIR=	src

USE_APACHE=	22+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_LIB=		${LOCALBASE}/lib
AP_EXTRAS=	-l ssl -l curl

.include <bsd.port.mk>
