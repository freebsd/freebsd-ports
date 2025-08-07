PORTNAME=	phpfpmtop
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2
PORTREVISION=	16
CATEGORIES=	www devel

MAINTAINER=	mops@punkt.de
COMMENT=	Top-inspired processviewer for PHP-FPM
WWW=		https://github.com/abrander/phpfpmtop

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	abrander
GH_TUPLE=	BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		golang:sys:5c8b2ff67527:golang_sys/vendor/golang.org/x/sys \
		pkg:term:aa71e9d9e942:pkg_term/vendor/github.com/pkg/term

PLIST_FILES=	bin/${PORTNAME} ${DOCSDIR}/README.md

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
