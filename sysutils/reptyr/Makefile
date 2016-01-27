# Created by: Andrey Cherkashin <andoriyu@gmail.com>
# $FreeBSD$

PORTNAME=	reptyr
PORTVERSION=	0.6.3a
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	andoriyu@gmail.com
COMMENT=	Reparent a running program to a new terminal

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	nelhage
GH_TAGNAME=	6fb15adb4552e170bcd5e648803da83dba57283b

MAKE_ARGS=	BASHCOMPDIR=${PREFIX}/share/bash-completion/completions \
		MANDIR=${MANPREFIX}/man
USES=		gmake

ONLY_FOR_ARCHS=	i386 amd64

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/reptyr

.include <bsd.port.mk>
