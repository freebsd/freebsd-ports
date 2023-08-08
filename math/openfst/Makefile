PORTNAME=	openfst
PORTVERSION=	1.8.1
CATEGORIES=	math
MASTER_SITES=	http://www.openfst.org/twiki/pub/FST/FstDownload/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Library for working with weighted finite-state transducers
WWW=		https://www.openfst.org/

LICENSE=	APACHE20

USES=		compiler:c++17-lang libtool python
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--enable-bin \
		--enable-compact-fsts \
		--enable-compress \
		--enable-const-fsts \
		--enable-far \
		--enable-fsts \
		--enable-linear-fsts \
		--enable-lookahead-fsts \
		--enable-mpdt \
		--enable-ngram-fsts \
		--enable-pdt \
		--enable-python \
		--enable-special

CXXFLAGS_i386=	-msse -msse2 -mfpmath=sse

.include <bsd.port.mk>
