PORTNAME=	rdrview
DISTVERSIONPREFIX=v
DISTVERSION=	0.1.4
CATEGORIES=	www

MAINTAINER=	ps.ports@smyrak.com
COMMENT=	CLI tool to extract the main content from a webpage

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libiconv.so:converters/libiconv \
		libxml2.so:textproc/libxml2

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	eafer

MAKE_ARGS=	CC=${CC} \
		GIT_COMMIT=${DISTVERSIONFULL}
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/rdrview \
		share/man/man1/rdrview.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rdrview ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rdrview.1 ${STAGEDIR}${PREFIX}/share/man/man1/

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
