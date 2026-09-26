PORTNAME=	libmbus
DISTVERSION=	0.10.4
CATEGORIES=	sysutils

MAINTAINER=	admin@lissyara.su
COMMENT=	Meter-bus library and utility programs
WWW=		https://github.com/rscada/libmbus/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf libtool
USE_GITHUB=	yes
GH_ACCOUNT=	rscada
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

pre-configure:
	${MKDIR} ${WRKSRC}/m4

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmbus.so.0.0.10

post-install-DOCS-off:
	${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
