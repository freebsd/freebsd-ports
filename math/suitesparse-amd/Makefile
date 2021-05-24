# Created by: Thierry Thomas (<thierry@pompo.net>)

PORTNAME=	AMD
PORTVERSION=	2.4.6
CATEGORIES=	math

COMMENT=	Symmetric approximate minimum degree

LICENSE=	BSD3CLAUSE

USES=		fortran localbase:ldflags
OMP_NEEDED=	yes

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
ALL_TARGET+=	fortran
USE_LDCONFIG=	yes

.include "${.CURDIR}/../../math/suitesparse/bsd.suitesparse.mk"

post-stage:
	${INSTALL_DATA} ${BUILD_WRKSRC}/Lib/libamdf77.a	\
		${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.post.mk>
