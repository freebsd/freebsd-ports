# Created by: Xiaoding Liu <xiaoding+freebsd@xiaoding.org>
# $FreeBSD$

PORTNAME=	shadowsocks-libev
PORTVERSION=	1.4.0
CATEGORIES=	net
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/archive/${GH_TAGNAME}.tar.gz?dummy=/

MAINTAINER=	xiaoding+freebsd@xiaoding.org
COMMENT=	Lightweight tunnel proxy which can help you get through firewalls

LICENSE=	GPLv3

# fetch from github repo
USE_GITHUB=	yes
GH_ACCOUNT=	madeye
GH_TAGNAME=	v1.4.0
WRKSRC=		${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes
USES=		gmake

USE_RC_SUBR=	shadowsocks_libev

.include <bsd.port.mk>
