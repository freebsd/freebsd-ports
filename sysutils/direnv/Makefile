PORTNAME=	direnv
DISTVERSIONPREFIX=	v
DISTVERSION=	2.35.0
PORTREVISION=	9
CATEGORIES=	sysutils

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Environment variable manager for your shell
WWW=		https://direnv.net/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USES=		go:modules
GO_MODULE=	github.com/direnv/direnv/v2

MAN1PAGES=	direnv direnv-fetchurl direnv-stdlib direnv.toml
PLIST_FILES=	bin/direnv \
		${MAN1PAGES:C,^,share/man/man1/,:C,$,.1.gz,}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/direnv \
		${STAGEDIR}${PREFIX}/bin/
.for man in ${MAN1PAGES}
	${INSTALL_MAN} ${WRKSRC}/man/${man}.1 ${STAGEDIR}${PREFIX}/share/man/man1
.endfor

.include <bsd.port.mk>
