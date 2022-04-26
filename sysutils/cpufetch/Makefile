PORTNAME=	cpufetch
DISTVERSIONPREFIX=	v
DISTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	sysutils

PATCH_SITES=	https://github.com/Dr-Noob/cpufetch/commit/
PATCHFILES=	0db9f1f5c26e57a6383f4609c5605ed5d3d41fd1.patch:-p1

MAINTAINER=	jbo@insane.engineer
COMMENT=	Simple yet fancy CPU architecture fetching tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	not yet ported to other architectures

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	Dr-Noob

PLIST_FILES=	bin/cpufetch \
		man/man1/cpufetch.1.gz

# Custom install as upstream uses invalid -Dm755 and -Dm644 instead of ${INSTALL_PROGRAM} and ${INSTALL_DATA} accordingly.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpufetch ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cpufetch.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
