PORTNAME=	gitlogue
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0 # make patch cargo-crates
CATEGORIES=	misc

MAINTAINER=	nxjoseph@FreeBSD.org
COMMENT=	Watch your git commit history in a cinematic view
WWW=		https://github.com/unhappychoice/gitlogue

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2
RUN_DEPENDS=	noto-emoji>0:x11-fonts/noto-emoji

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	unhappychoice

TESTING_UNSAFE=	yes

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
