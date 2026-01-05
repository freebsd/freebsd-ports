PORTNAME=	lsd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	sysutils

MAINTAINER=	ports@freebsd.org
COMMENT=	Pretty ls alternative with support for icons
WWW=		https://github.com/lsd-rs/lsd/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	libgit2.so:devel/libgit2
USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	lsd-rs

PLIST_FILES=	bin/lsd

.include <bsd.port.mk>
