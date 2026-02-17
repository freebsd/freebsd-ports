PORTNAME=	deark
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.2
CATEGORIES=	misc

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Utility for data extraction, decompression, and image format decoding
WWW=		https://entropymine.com/deark/ \
		https://github.com/jsummers/deark/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	help2man:misc/help2man

USES=		cpe gmake

CPE_VENDOR=	entropymine

USE_GITHUB=	yes
GH_ACCOUNT=	jsummers

PLIST_FILES=	bin/deark \
		share/man/man1/deark.1.gz

post-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/deark ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/deark.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
