PORTNAME=	stu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.6
CATEGORIES=	net

MAINTAINER=	longros@FreeBSD.org
COMMENT=	TUI explorer for Amazon S3 and compatible object storage
WWW=		https://lusingander.github.io/stu/ \
		https://github.com/lusingander/stu

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo cmake:indirect llvm:build
USE_GITHUB=	yes
GH_ACCOUNT=	lusingander

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
