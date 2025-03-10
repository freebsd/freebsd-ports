PORTNAME=	kvazaar
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.1
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	H.265/HEVC encoder implemented in C
WWW=		https://ultravideo.fi/#encoder_x

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf compiler:c11 libtool pathfix
USE_GITHUB=	yes
GH_ACCOUNT=	ultravideo
GH_TUPLE=	silentbicycle:greatest:v1.0.0:greatest/greatest
GNU_CONFIGURE=	yes
TEST_TARGET=	check
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	CRYPTOPP DOCS

CRYPTOPP_DESC=		Selective encryption via Crypto++ library
CRYPTOPP_LIB_DEPENDS=	libcryptopp.so:security/cryptopp
CRYPTOPP_USES=		pkgconfig
CRYPTOPP_CONFIGURE_WITH=cryptopp

post-patch:
	@${REINPLACE_CMD} -e 's/x86_64/&|amd64/' \
		-e '/AM_INIT_AUTOMAKE/s/])/ serial-tests&/' \
		${WRKSRC}/configure.ac

.include <bsd.port.mk>
