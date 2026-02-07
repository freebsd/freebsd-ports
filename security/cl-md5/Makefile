PORTNAME=	md5
DISTVERSIONPREFIX=	release-
DISTVERSION=	2.0.5
CATEGORIES=	security lisp
PKGNAMEPREFIX=	cl-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Native MD5 implementation in Common Lisp
WWW=		https://www.cliki.net/MD5

LICENSE=	PD

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/flexi-streams/flexi-streams.asd:devel/cl-flexi-streams
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/flexi-streams/flexi-streams.asd:devel/cl-flexi-streams



USES=		cl
USE_GITHUB=	yes
GH_ACCOUNT=	pmai

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME} ${STAGEDIR}${ASDF_REGISTRY}
	${INSTALL_DATA} ${WRKSRC}/*.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/*.asd ${STAGEDIR}${ASDF_PATHNAME}
	${RLN} ${STAGEDIR}${ASDF_PATHNAME}/md5.asd ${STAGEDIR}${ASDF_REGISTRY}

.include <bsd.port.mk>
