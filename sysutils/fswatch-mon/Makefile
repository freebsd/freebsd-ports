# Created by: Enrico M. Crisostomo <enrico.m.crisostomo@gmail.com>
# $FreeBSD$

PORTNAME=	fswatch
DISTVERSION=	1.13.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/emcrisostomo/${PORTNAME}/releases/download/${DISTVERSION}/
PKGNAMESUFFIX=	-mon

MAINTAINER=	enrico.m.crisostomo@gmail.com
COMMENT=	Cross-platform file change monitor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang libtool makeinfo
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	fswatch-[0-9]*
GNU_CONFIGURE=	yes
INFO=	fswatch
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
