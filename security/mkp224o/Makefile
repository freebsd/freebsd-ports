# $FreeBSD$

PORTNAME=	mkp224o
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Vanity address generator for tor onion v3 (ed25519) hidden services

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libsodium.so:security/libsodium

USES=		autoreconf compiler:c11 gmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	cathugger
GNU_CONFIGURE=	yes

MAKEFILE=	GNUmakefile

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
