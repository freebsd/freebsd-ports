# Created by: John-Mark Gurney <jmg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tcpcrypt
DISTVERSION=	0.3.rc1
CATEGORIES=	security net

MAINTAINER=	jmg@FreeBSD.org
COMMENT=	TCPCrypt userland divert daemon

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	scslab
GH_TAGNAME=	v0.3-rc1
GH_COMMIT=	b110e7e

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		autoreconf libtool
INSTALL_TARGET=	install-strip

USERS=		tcpcryptd
GROUPS=		tcpcryptd

.include <bsd.port.mk>
