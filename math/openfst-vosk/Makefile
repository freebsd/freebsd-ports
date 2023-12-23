PORTNAME=	openfst # openfst-vosk is for audio/vosk-api
DISTVERSION=	20210207
CATEGORIES=	math
PKGNAMESUFFIX=	-vosk

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for working with weighted finite-state transducers
WWW=		https://www.openfst.org/

LICENSE=	APACHE20

USES=		autoreconf compiler:c++17-lang gmake libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared \
		--enable-far \
		--enable-ngram-fsts \
		--enable-lookahead-fsts \
		--with-pic \
		--disable-bin

CXXFLAGS_i386=	-msse -msse2 -mfpmath=sse

USE_GITHUB=	yes
GH_ACCOUNT=	alphacep
GH_TAGNAME=	7dfd808

.include <bsd.port.mk>
