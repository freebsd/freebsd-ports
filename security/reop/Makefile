# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	reop
PORTVERSION=	2.1.0
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Reasonable Expectation Of Privacy

LIB_DEPENDS=	libsodium.so:security/libsodium

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	tedu

MAKEFILE=	GNUmakefile
MAKE_ARGS+=	CPPFLAGS="-D_NSIG=NSIG" \
		CFLAGS+="-I${LOCALBASE}/include -Iother -Wno-pointer-sign" \
		PREFIX="${STAGEDIR}${PREFIX}"

PLIST_FILES=	bin/reop \
		man/man1/reop.1.gz

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
