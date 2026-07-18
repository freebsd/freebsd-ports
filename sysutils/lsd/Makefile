PORTNAME=	lsd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
PORTREVISION=	6
CATEGORIES=	sysutils

MAINTAINER=	zihado@gmail.com
COMMENT=	Pretty ls alternative with support for icons
WWW=		https://github.com/lsd-rs/lsd/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	lsd-rs

PLIST_FILES=	bin/lsd

CARGO_TEST_AFTER_ARGS=	--skip git::tests::test_git_workflow \
			--skip meta::permissions::test::permission_octal_sticky \
			--skip meta::permissions::test::permission_rwx_sticky

.include <bsd.port.mk>
