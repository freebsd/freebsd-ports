# Created by: johans@stack.nl
# $FreeBSD$

PORTNAME=	nfsshell
PORTVERSION=	20130510
CATEGORIES=	net
#MASTER_SITES=	http://www.cs.vu.nl/pub/leendert/
DISTNAME=	${PORTNAME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Userland NFS command tool

USE_GITHUB=	yes
GH_ACCOUNT=	NetDirect
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	09cdd52

ALL_TARGET=	nfsshell
MAKE_ARGS=	CC="${CC}" LIBS="-lreadline"

PLIST_FILES=	bin/nfsshell

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nfsshell ${STAGEDIR}${PREFIX}/bin/nfsshell

.include <bsd.port.mk>
