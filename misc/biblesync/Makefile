PORTNAME=	biblesync
DISTVERSION=	2.1.0
PORTREVISION=	2
CATEGORIES=	misc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multicast shared co-navigation library for Bible programs
WWW=		https://github.com/karlkleinpaste/biblesync

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libuuid.so:misc/libuuid

USES=		cmake compiler:c++11-lang gettext-runtime

USE_GITHUB=	yes
GH_ACCOUNT=	karlkleinpaste

USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

post-patch:
	${REINPLACE_CMD} s,/bibleysnc,, ${WRKSRC}/biblesync.pc.in

.include <bsd.port.mk>
