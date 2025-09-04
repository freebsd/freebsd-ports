PORTNAME=	stegify
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2-2
DISTVERSIONSUFFIX=	-g62518ca
PORTREVISION=	29
CATEGORIES=	security graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Steganography software
WWW=		https://github.com/DimitarPetrov/stegify

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	DimitarPetrov

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
