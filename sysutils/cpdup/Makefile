# Created by: Matthew Dillon <dillon@backplane.com>
# $FreeBSD$

PORTNAME=	cpdup
PORTVERSION=	1.22
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Comprehensive filesystem mirroring and backup program

LICENSE=	BSD2CLAUSE # clarified by Matthew Dillon himself

USES=		gmake ssl tar:xz
USE_GITHUB=	yes
GH_TUPLE=	DragonFlyBSD:${PORTNAME}:v${PORTVERSION}
MAKEFILE=	GNUmakefile
MAKE_ARGS+=	LIBS="-L${OPENSSLLIB} -lcrypto"

PLIST_FILES=	bin/cpdup man/man1/cpdup.1.gz

post-patch:
	${REINPLACE_CMD} \
		-e 's}^CFLAGS=\(.*\)}& ${CFLAGS}}' \
		-e '/^CFLAGS+=.*pkg-config.*openssl/s}^CFLAGS.*}CFLAGS+=-I${OPENSSLINC}}' \
		-e '/^LIBS+=.*pkg-config.*openssl/s}^LIBS.*}LIBS+=-L${OPENSSLLIB} -Wl,--as-needed -lssl -lcrypto}' \
		${WRKSRC}/GNUmakefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpdup ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cpdup.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
