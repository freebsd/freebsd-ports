# Created by: Andrey Cherkashin <andoriyu@gmail.com>
# $FreeBSD$

PORTNAME=	reptyr
PORTVERSION=	0.6.3a
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	andoriyu@gmail.com
COMMENT=	Reparent a running program to a new terminal

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	nelhage
GH_TAGNAME=	6fb15adb4552e170bcd5e648803da83dba57283b

USES=		gmake

OPTIONS_DEFINE=	BASH
OPTIONS_SUB=	yes

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>
.if ${PORT_OPTIONS:MBASH}
BUILD_DEPENDS=	${LOCALBASE}/share/bash-completion/bash_completion:${PORTSDIR}/shells/bash-completion
.endif

BROKEN_FreeBSD_9=	Not supported on FreeBSD older than 10.0

post-install:
.if ${PORT_OPTIONS:MBASH}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_SCRIPT} ${WRKSRC}/reptyr.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/reptyr
.endif
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/reptyr

.include <bsd.port.post.mk>
