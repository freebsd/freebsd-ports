PORTNAME=	tcpcrypt
PORTVERSION=	0.5
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	security net

PATCH_SITES=	https://github.com/glebius/${PORTNAME}/commit/
PATCHFILES=	8c7d4abf2ca1d795651cf8cc73994b18419487d7.patch:-p1

MAINTAINER=	jmg@FreeBSD.org
COMMENT=	TCPCrypt userland divert daemon
WWW=		http://www.tcpcrypt.org/

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	scslab

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_LDCONFIG=	yes
USES=		autoreconf libtool ssl
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

USERS=		tcpcryptd
GROUPS=		tcpcryptd

.include <bsd.port.mk>
