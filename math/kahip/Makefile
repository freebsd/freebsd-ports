PORTNAME=	kahip
DISTVERSIONPREFIX=	v
DISTVERSION=	3.22
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Karlsruhe high quality graph partitioning
WWW=		https://kahip.github.io/ \
		https://github.com/KaHIP/KaHIP

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmetis.so:math/metis \
		libmpi.so:net/mpich

USES=		cmake localbase
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	KaHIP
GH_PROJECT=	KaHIP

.include <bsd.port.mk>
