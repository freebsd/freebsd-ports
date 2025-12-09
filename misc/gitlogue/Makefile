PORTNAME=	gitlogue
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0 # make patch cargo-crates
CATEGORIES=	misc

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Watch your git commit history in a cinematic view
WWW=		https://github.com/unhappychoice/gitlogue

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo localbase ssl
USE_GITHUB=	yes
GH_ACCOUNT=	unhappychoice

CARGO_ENV=	OPENSSL_NO_VENDOR=1

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
