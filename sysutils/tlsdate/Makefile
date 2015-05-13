# $FreeBSD$

PORTNAME=	tlsdate
PORTVERSION=	0.0.12
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	sysutils

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Secure parasitic rdate replacement

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USES=		autoreconf libtool pkgconfig

PLIST_SUB=	PKGNAME=${PKGNAME}
PORTDOCS=	*

USE_GITHUB=	yes
GH_ACCOUNT=	ioerror

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} test

.include <bsd.port.mk>
