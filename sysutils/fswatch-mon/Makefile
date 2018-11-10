# Created by: Enrico M. Crisostomo <enrico.m.crisostomo@gmail.com>
# $FreeBSD$

PORTNAME=	fswatch
PORTVERSION=	1.11.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${PORTVERSION}/
PKGNAMESUFFIX=	-mon

MAINTAINER=	enrico.m.crisostomo@gmail.com
COMMENT=	Cross-platform file change monitor

LICENSE=	GPLv3

USES=		compiler:c++11-lang libtool makeinfo
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

INFO=	fswatch

CONFLICTS_INSTALL=	fswatch-[0-9]*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

GH_ACCOUNT=	emcrisostomo
GH_PROJECT=	fswatch

post-install:
	  ${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfswatch.so

.include <bsd.port.mk>
