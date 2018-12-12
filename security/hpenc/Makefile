# $FreeBSD$

PORTNAME=	hpenc
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Fast authenticated encryption CLI tool

LICENSE=	BSD2CLAUSE

USES=		cmake compiler:c++11-lib ssl
LIB_DEPENDS=	libsodium.so:security/libsodium

USE_GITHUB=	yes
GH_ACCOUNT=	vstakhov

PLIST_FILES=	bin/hpenc bin/hpenc-${PORTVERSION} man/man1/hpenc.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/hpenc.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/hpenc

.include <bsd.port.mk>
