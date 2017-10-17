# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	titus
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	feld@FreeBSD.org
COMMENT=	TLS/SSL proxy server

LICENSE=	MIT

BROKEN_powerpc64=	fails to compile: child.cpp: undefined reference to std::__cxx11::basic_string

USES=		compiler:c++11-lang ssl
USE_RC_SUBR=	titus

USE_GITHUB=	yes
GH_ACCOUNT=	AGWA

USERS=		titus titus-keys
GROUPS=		nogroup

MAKE_ENV+=	MANDIR=${MANPREFIX}/man
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

post-patch:
	${REINPLACE_CMD} 's|/var/lib/titus/empty|/var/empty|' ${WRKSRC}/titus.conf.example

post-install:
	${INSTALL_DATA} ${WRKSRC}/titus.conf.example ${STAGEDIR}${PREFIX}/etc/titus.conf.sample

.include <bsd.port.mk>
