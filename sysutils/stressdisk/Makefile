PORTNAME=	stressdisk
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.12
PORTREVISION=	4
CATEGORIES=	sysutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Stress test your disks before trusting your valuable data to them

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go:modules

GO_MODULE=	github.com/ncw/stressdisk

PLIST_FILES=	bin/stressdisk

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
