# $FreeBSD$

PORTNAME=	tlsdate
PORTVERSION=	0.0.13
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	sysutils

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Secure parasitic rdate replacement

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libevent.so:devel/libevent2

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
TEST_TARGET=	test
USE_OPENSSL=	yes
USES=		autoreconf libtool pkgconfig

PLIST_SUB=	PKGNAME=${PKGNAME}
PORTDOCS=	*

USE_GITHUB=	yes
GH_ACCOUNT=	ioerror

.include <bsd.port.mk>
