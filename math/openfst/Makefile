PORTNAME=	openfst
DISTVERSION=	1.8.2-20221207
PORTREVISION=	1
CATEGORIES=	math
#MASTER_SITES=	http://www.openfst.org/twiki/pub/FST/FstDownload/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for working with weighted finite-state transducers
WWW=		https://www.openfst.org/ \
		https://github.com/kkm000/openfst

LICENSE=	APACHE20

USES=		cmake compiler:c++17-lang
USE_LDCONFIG=	yes
USE_GCC=	yes # clang-19 fails to compile it since migration to 14.3

CXXFLAGS_i386=	-msse -msse2 -mfpmath=sse

CMAKE_ON=	HAVE_COMPRESS

USE_GITHUB=	yes
GH_ACCOUNT=	kkm000
GH_TAGNAME=	8058417

.include <bsd.port.mk>
