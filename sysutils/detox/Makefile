PORTNAME=	detox
PORTVERSION=	1.4.5
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Removes non-standard characters from filenames
WWW=		https://github.com/dharple/detox

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf gmake tar:bzip2
USE_GITHUB=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
GH_ACCOUNT=	dharple

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/detox
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/inline-detox

.include <bsd.port.mk>
