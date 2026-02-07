PORTNAME=	librsync
PORTVERSION=	2.3.4
CATEGORIES=	net devel
MASTER_SITES=	https://github.com/librsync/librsync/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for delta compression of streams
WWW=		https://github.com/librsync/librsync

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpopt.so:devel/popt

USES=		cmake compiler:c11 cpe perl5
USE_PERL5=	test

CMAKE_OFF=	ENABLE_TRACE
CMAKE_ON=	BUILD_RDIFF BUILD_SHARED_LIBS ENABLE_COMPRESSION USE_LIBB2
TEST_TARGET=	check
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

CPE_VENDOR=	librsync_project

.include <bsd.port.mk>
