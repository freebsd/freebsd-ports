PORTNAME=	getdp
DISTVERSION=	4.0.0.rc1
CATEGORIES=	science

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Rather general finite element solver using mixed finite elements
WWW=		https://getdp.info/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libgsl.so:math/gsl	\
		liblapack.so:math/lapack

USE_GITLAB=	yes
GL_SITE=	https://gitlab.onelab.info
GL_ACCOUNT=	getdp
GL_PROJECT=	getdp
GL_COMMIT=	ff94cb9af929d523863deafcfa33342674a9c12a

USES=		fortran tar:tgz cmake

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for Rank mismatch in argument 'lines' at (1) (rank-1 and scalar)
FFLAGS+=	-fallow-argument-mismatch
.endif

do-test:
	cd ${WRKSRC}/demos && yes "" | ${STAGEDIR}${PREFIX}/bin/${PORTNAME} magnet.pro -solve MagSta_phi

.include <bsd.port.post.mk>
