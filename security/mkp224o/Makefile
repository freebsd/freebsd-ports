PORTNAME=	mkp224o
DISTVERSION=	1.6.1
CATEGORIES=	security
MASTER_SITES=	https://github.com/cathugger/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Vanity address generator for tor onion v3 (ed25519) hidden services

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libsodium.so:security/libsodium

USES=		compiler:c11 gmake localbase:ldflags

GNU_CONFIGURE=	yes

MAKEFILE=	GNUmakefile

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
