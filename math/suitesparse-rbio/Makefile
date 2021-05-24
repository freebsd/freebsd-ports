# Created by: Thierry Thomas (<thierry@pompo.net>)

PORTNAME=	RBio
PORTVERSION=	2.2.6
CATEGORIES=	math

COMMENT=	Read/write sparse matrices

LICENSE=	GPLv2+

USES=		localbase:ldflags

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"
.include <bsd.port.post.mk>
