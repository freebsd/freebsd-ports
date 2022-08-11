PORTNAME=	cddlib
PORTVERSION=	0.94m
CATEGORIES=	math
MASTER_SITES=	https://github.com/cddlib/cddlib/releases/download/${DISTVERSION}/

MAINTAINER=	moritz@schmi.tt
COMMENT=	C-library implementation of the Double Description Method

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		autoreconf gmake libtool:build localbase:ldflags
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes
DOCS_DESC=	Install cddlib user manual
EXAMPLES_DESC=	Install cddlib examples

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so
	${RLN} ${STAGEDIR}${PREFIX}/include/cddlib ${STAGEDIR}${PREFIX}/include/cdd
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MV} ${STAGEDIR}${DOCSDIR}/example* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
