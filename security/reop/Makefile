# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	reop
PORTVERSION=	2.1.0
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	https://humungus.tedunangst.com/r/reop/d/

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Reasonable Expectation Of Privacy

LICENSE=	ISCL

LIB_DEPENDS=	libsodium.so:security/libsodium

USES=		gmake tar:tgz

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
