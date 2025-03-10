PORTNAME=	openfst
DISTVERSION=	1.8.2-20221207
CATEGORIES=	math
#MASTER_SITES=	http://www.openfst.org/twiki/pub/FST/FstDownload/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for working with weighted finite-state transducers
WWW=		https://www.openfst.org/ \
		https://github.com/kkm000/openfst

LICENSE=	APACHE20

BROKEN_FreeBSD_15=	compilation fails with clang-19, see https://github.com/kkm000/openfst/issues/58

USES=		cmake compiler:c++17-lang
USE_LDCONFIG=	yes

CXXFLAGS_i386=	-msse -msse2 -mfpmath=sse

CMAKE_ON=	HAVE_COMPRESS

USE_GITHUB=	yes
GH_ACCOUNT=	kkm000
GH_TAGNAME=	8058417

.include <bsd.port.mk>
