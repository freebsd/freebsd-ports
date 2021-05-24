# Created by: Thierry Thomas (<thierry@pompo.net>)

PORTNAME=	CAMD
PORTVERSION=	2.4.6
CATEGORIES=	math

COMMENT=	Symmetric approximate minimum degree

LICENSE=	BSD3CLAUSE

USES=		localbase:ldflags
OMP_NEEDED=	yes

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"
.include <bsd.port.post.mk>
