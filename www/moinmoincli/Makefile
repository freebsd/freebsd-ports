PORTNAME=	moinmoincli
DISTVERSION=	4.6.0
PORTREVISION=	1
CATEGORIES=	www docs

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Edit existing MoinMoin wiki pages from a command line
WWW=		https://github.com/0mp/moinmoincli

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	curl:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	0mp

MAKE_ARGS=	MANDIR=${STAGEDIR}${PREFIX}/share/man

SUB_FILES=	pkg-message

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=		GIT
OPTIONS_DEFAULT=	GIT
GIT_DESC=	Install git to use git-diff(1) instead of diff(1) for colored output
GIT_RUN_DEPENDS=	git:devel/git

.include <bsd.port.mk>
