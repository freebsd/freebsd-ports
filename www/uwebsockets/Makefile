# $FreeBSD$

PORTNAME=	uwebsockets
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.6
CATEGORIES=	www devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	159430943c3c1118a56a22ff9f7cc845661804f9.patch:-p1 # https://github.com/uNetworking/uWebSockets/pull/1042

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Web I/O library for the most demanding of applications

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	usockets>0:net/usockets

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	uNetworking
GH_PROJECT=	uWebSockets

NO_BUILD=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
