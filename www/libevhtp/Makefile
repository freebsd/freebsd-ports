# $FreeBSD$

PORTNAME=	libevhtp
PORTVERSION=	1.2.9
CATEGORIES=	www

MAINTAINER=	yan_jingfeng@yahoo.com
COMMENT=	Flexible replacement for libevent httpd API

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2

USE_GITHUB=	yes
GH_ACCOUNT=	ellzey
GH_PROJECT=	libevhtp
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	3886506

USES=		cmake:outsource

CMAKE_ARGS=	-DCMAKE_INCLUDE_PATH:PATH=include/event2 \
		-DCMAKE_LIBRARY_PATH:PATH=lib/event2
CMAKE_BUILD_TYPE=	Release

PLIST_FILES=	include/evhtp.h\
		include/evhtp-config.h \
		include/evthr.h \
		include/htparse.h \
		include/onigposix.h \
		lib/libevhtp.a

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 900000
BROKEN=		Does not build on FreeBSD 8.x
.endif

.include <bsd.port.post.mk>
