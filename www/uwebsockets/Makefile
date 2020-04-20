# $FreeBSD$

PORTNAME=	uwebsockets
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.4
CATEGORIES=	www devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Web I/O library for the most demanding of applications

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	usockets>0:net/usockets

USE_GITHUB=	yes
GH_ACCOUNT=	uNetworking
GH_PROJECT=	uWebSockets

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${GH_PROJECT}
	${RM} ${STAGEDIR}${PREFIX}/include/uWebSockets/f2/LICENSE.txt

.include <bsd.port.mk>
