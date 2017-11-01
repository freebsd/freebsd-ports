# Created by: Enrico M. Crisostomo <enrico.m.crisostomo@gmail.com>
# $FreeBSD$

PORTNAME=	fswatch
PORTVERSION=	1.11.2
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${PORTVERSION}/
PKGNAMESUFFIX=	-mon

MAINTAINER=	enrico.m.crisostomo@gmail.com
COMMENT=	Cross-platform file change monitor

LICENSE=	GPLv3

BROKEN_powerpc64=	fails to configure: A compiler with support for C++11 language features is required

USES=	libtool makeinfo
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

INFO=	fswatch

CONFLICTS_INSTALL=	fswatch-[0-9]*

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

GH_ACCOUNT=	emcrisostomo
GH_PROJECT=	fswatch

post-install:
	  ${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfswatch.so

.include <bsd.port.mk>
