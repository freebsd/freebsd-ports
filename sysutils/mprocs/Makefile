PORTNAME=	mprocs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.3
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Run multiple commands in parallel
WWW=		https://github.com/pvolok/mprocs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo gmake
USE_GITHUB=	yes
GH_ACCOUNT=	pvolok

CARGO_INSTALL_PATH=	src

PLIST_FILES=	bin/mprocs

.include <bsd.port.mk>
