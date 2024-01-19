PORTNAME=	reptyr
PORTVERSION=	0.8.0
PORTREVISION=	1
DISTVERSIONPREFIX=	reptyr-
CATEGORIES=	sysutils

MAINTAINER=	andoriyu@gmail.com
COMMENT=	Reparent a running program to a new terminal
WWW=		https://github.com/nelhage/reptyr

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	nelhage

MAKE_ARGS=	BASHCOMPDIR=${PREFIX}/share/bash-completion/completions \
		MANDIR=${PREFIX}/share/man
USES=		gmake

ONLY_FOR_ARCHS=	i386 amd64

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/reptyr

.include <bsd.port.mk>
