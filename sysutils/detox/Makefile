PORTNAME=	detox
PORTVERSION=	2.0.0
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Removes non-standard characters from filenames
WWW=		https://github.com/dharple/detox

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf gmake pkgconfig tar:bzip2
USE_GITHUB=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
GH_ACCOUNT=	dharple

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/detox
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/inline-detox

.include <bsd.port.mk>
