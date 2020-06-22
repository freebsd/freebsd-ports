# Created by: johans@stack.nl
# $FreeBSD$

PORTNAME=	nfsshell
PORTVERSION=	20130510
PORTREVISION=	4
CATEGORIES=	net
#MASTER_SITES=	http://www.cs.vu.nl/pub/leendert/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Userland NFS command tool

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		localbase readline
USE_GITHUB=	yes
GH_ACCOUNT=	NetDirect
GH_TAGNAME=	09cdd52
ALL_TARGET=	nfsshell
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DREADLINE" \
		LIBS="-lreadline ${LDFLAGS}"
PLIST_FILES=	bin/nfsshell

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nfsshell ${STAGEDIR}${PREFIX}/bin/nfsshell

.include <bsd.port.mk>
