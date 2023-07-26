PORTNAME=	datovka
DISTVERSION=	4.22.1
CATEGORIES=	mail
MASTER_SITES=	https://secure.nic.cz/files/datove_schranky/${DISTVERSION}/

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Qt re-implementation of Datovka
WWW=		https://gitlab.nic.cz/datovka/datovka

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libglvnd>0:graphics/libglvnd \
		pkgconf:devel/pkgconf
LIB_DEPENDS=	libdatovka.so:devel/libdatovka

USES=		desktop-file-utils gl pkgconfig qmake qt:5 ssl tar:xz
USE_GL=		gl
USE_QT=		buildtools core gui network printsupport sql svg websockets \
		widgets

.include <bsd.port.pre.mk>

.if ( ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400092 && ${SSL_DEFAULT} == base ) || ${SSL_DEFAULT:Mopenssl3*}
CXXFLAGS+=	-DOPENSSL_API_COMPAT=0x30000000L"
.endif

.include <bsd.port.post.mk>
