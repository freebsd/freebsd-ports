# $FreeBSD$

PORTNAME=	smbclient
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	net pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Smbclient wrapper extension

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:ext samba:lib tar:tgz

CONFIGURE_ARGS=	--with-libsmbclient=${LOCALBASE}
CPPFLAGS+=	-I${SAMBAINCLUDES}
LDFLAGS+=	-L${SAMBALIBS}

.include <bsd.port.mk>
