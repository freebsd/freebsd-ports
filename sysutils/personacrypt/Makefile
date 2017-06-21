# Created by: Joe Maloney <jmaloney@ixsystems.com>
# $FreeBSD$

PORTNAME=	personacrypt
PORTVERSION=	201706210947
CATEGORIES=	sysutils

MAINTAINER=	jmaloney@ixsystems.com
COMMENT=	Home directory encryption on external devices

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	pefs-kmod>=0:sysutils/pefs-kmod

WRKSRC_SUBDIR=  src-sh
USES=		pkgconfig tar:xz
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	personacrypt
GH_TAGNAME=	5062d8dd46217201986d31048eeec4dbcfbec6a5

.include <bsd.port.mk>
