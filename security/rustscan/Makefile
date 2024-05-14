PORTNAME=	rustscan
PORTVERSION=	2.2.3
CATEGORIES=	security

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Faster Nmap Scanning with Rust
WWW=		https://rustscan.github.io/RustScan/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	nmap>0:security/nmap

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	RustScan
GH_PROJECT=	RustScan

PLIST_FILES=	bin/rustscan

.include <bsd.port.mk>
