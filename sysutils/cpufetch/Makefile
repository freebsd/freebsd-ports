PORTNAME=	cpufetch
DISTVERSIONPREFIX=	v
DISTVERSION=	1.06
CATEGORIES=	sysutils

MAINTAINER=	jbo@FreeBSD.org
COMMENT=	Simple yet fancy CPU architecture fetching tool
WWW=		https://github.com/Dr-Noob/cpufetch

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	not yet ported to other architectures

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	Dr-Noob

PLIST_FILES=	bin/cpufetch \
		share/man/man1/cpufetch.1.gz

# Custom install as upstream uses invalid -Dm755 and -Dm644 instead of ${INSTALL_PROGRAM} and ${INSTALL_DATA} accordingly.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpufetch ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cpufetch.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
