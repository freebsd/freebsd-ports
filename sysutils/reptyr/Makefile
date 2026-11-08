PORTNAME=	reptyr
PORTVERSION=	0.10.0
DISTVERSIONPREFIX=	reptyr-
CATEGORIES=	sysutils

PATCH_SITES=	https://github.com/nelhage/reptyr/commit/
PATCHFILES=	59aa0dcb991177ccdc0d7887d7af0779fde4ebf3.patch:-p1

MAINTAINER=	andoriyu@gmail.com
COMMENT=	Reparent a running program to a new terminal
WWW=		https://github.com/nelhage/reptyr

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	nelhage

MAKE_ARGS=	BASHCOMPDIR=${PREFIX}/share/bash-completion/completions \
		MANDIR=${PREFIX}/share/man
USES=		gmake

ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc64 powerpc64le

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/reptyr

.include <bsd.port.mk>
