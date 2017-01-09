# Created by: Enrico M. Crisostomo <enrico.m.crisostomo@gmail.com>
# $FreeBSD$

PORTNAME=	fswatch
PORTVERSION=	1.9.3
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-mon

MAINTAINER=	enrico.m.crisostomo@gmail.com
COMMENT=	Cross-platform file change monitor

LICENSE=	GPLv3

USES=		autoreconf gettext libtool makeinfo
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

INFO=	fswatch

CONFLCICTS_INSTALL=	fswatch-[0-9]*

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	        gettext
NLS_CONFIGURE_ENABLE=	nls

USE_GITHUB=	yes
GH_ACCOUNT=	emcrisostomo

post-install:
	  ${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfswatch.so

.include <bsd.port.mk>
