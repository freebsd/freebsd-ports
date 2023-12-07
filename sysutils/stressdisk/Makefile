PORTNAME=	stressdisk
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.13
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Stress test your disks before trusting your valuable data to them
WWW=		https://github.com/ncw/stressdisk

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go:modules
GO_MODULE=	github.com/ncw/stressdisk
GO_BUILDFLAGS=	-ldflags=" \
		-X main.version=${DISTVERSION}"

PLIST_FILES=	bin/stressdisk

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
