PORTNAME=	libdaq
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.21
CATEGORIES=	net

PATCH_SITES=	https://github.com/glebius/${PORTNAME}/commit/
PATCHFILES=	c0f3283ad42a1d8e70ee699271b91168b14ec357.patch:-p1

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Data Acquisition abstraction library for snort 3.0+
WWW=		https://www.snort.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcap.so:net/libpcap	# avoid base libpcap

USES=		autoreconf compiler:c++11-lang libtool localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	snort3
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

CONFLICTS=	daq-2*

.include <bsd.port.mk>
