PORTNAME=	harper
DISTVERSIONPREFIX=	v
DISTVERSION=	0.53.0
CATEGORIES=	textproc

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Grammar checker for developers
WWW=		https://writewithharper.com/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	Automattic
CARGO_INSTALL_PATH=	harper-cli harper-ls
PLIST_FILES=	${CARGO_INSTALL_PATH:S,^,bin/,}

.include <bsd.port.mk>
