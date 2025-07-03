PORTNAME=	rustscan
PORTVERSION=	2.4.1
PORTREVISION=	3
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Faster Nmap Scanning with Rust
WWW=		https://github.com/RustScan/RustScan

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	ring-0.17.8 crate fails to build

RUN_DEPENDS=	nmap>0:security/nmap

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	RustScan
GH_PROJECT=	RustScan

PLIST_FILES=	bin/rustscan

.include <bsd.port.mk>
