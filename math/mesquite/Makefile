PORTNAME=	mesquite
DISTVERSION=	2.3.0
CATEGORIES=	math
MASTER_SITES=	https://github.com/sandialabs/mesquite/raw/main/mesquite/
PKGNAMESUFFIX=	-mesh-toolkit

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Mesh Quality Improvement Toolkit is a suite of mesh algorithms
WWW=		https://software.sandia.gov/mesquite

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/lgpl.txt

USES=		gmake libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --disable-static

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${MV} ${STAGEDIR}${DOCSDIR}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	@${RM} -r ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-off:
	@${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
