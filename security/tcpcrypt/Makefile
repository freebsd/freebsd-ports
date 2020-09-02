# Created by: John-Mark Gurney <jmg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tcpcrypt
PORTVERSION=	0.5
DISTVERSIONPREFIX=	v
CATEGORIES=	security net

MAINTAINER=	jmg@FreeBSD.org
COMMENT=	TCPCrypt userland divert daemon

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	scslab

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		autoreconf libtool ssl
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

USERS=		tcpcryptd
GROUPS=		tcpcryptd

.include <bsd.port.mk>
