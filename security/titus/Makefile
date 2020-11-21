# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	titus
PORTVERSION=	0.4
PORTREVISION=	0
CATEGORIES=	security

MAINTAINER=	feld@FreeBSD.org
COMMENT=	TLS/SSL proxy server

LICENSE=	MIT

DEPRECATED=	Development has officially ceased
EXPIRATION_DATE=	2021-02-01

USES=		compiler:c++11-lang ssl
USE_RC_SUBR=	titus

USE_GITHUB=	yes
GH_ACCOUNT=	AGWA

USERS=		titus titus-keys
GROUPS=		nogroup

MAKE_ENV+=	MANDIR=${MANPREFIX}/man

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_11=	Requires OpenSSL 1.1.0+
.endif

.if ${SSL_DEFAULT} != base
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
.endif

post-patch:
	${REINPLACE_CMD} 's|/var/lib/titus/empty|/var/empty|' ${WRKSRC}/titus.conf.example

post-install:
	${INSTALL_DATA} ${WRKSRC}/titus.conf.example ${STAGEDIR}${PREFIX}/etc/titus.conf.sample

.include <bsd.port.post.mk>
