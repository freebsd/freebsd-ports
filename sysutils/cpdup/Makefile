PORTNAME=	cpdup
PORTVERSION=	1.22
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	gmarco@giovannelli.it
COMMENT=	Comprehensive filesystem mirroring and backup program
WWW=		https://github.com/DragonFlyBSD/cpdup

LICENSE=	BSD2CLAUSE # clarified by Matthew Dillon himself

USES=		gmake ssl tar:xz
USE_GITHUB=	yes
GH_TUPLE=	DragonFlyBSD:${PORTNAME}:v${PORTVERSION}
MAKEFILE=	GNUmakefile
MAKE_ARGS+=	LIBS="-L${OPENSSLLIB} -lcrypto"

CONFLICTS_INSTALL=	cpdup-FreeBSD

PLIST_FILES=	bin/cpdup share/man/man1/cpdup.1.gz

post-patch:
	${REINPLACE_CMD} \
		-e 's}^CFLAGS=\(.*\)}& ${CFLAGS}}' \
		-e '/^CFLAGS+=.*pkg-config.*openssl/s}^CFLAGS.*}CFLAGS+=-I${OPENSSLINC}}' \
		-e '/^LIBS+=.*pkg-config.*openssl/s}^LIBS.*}LIBS+=-L${OPENSSLLIB} -Wl,--as-needed -lssl -lcrypto}' \
		${WRKSRC}/GNUmakefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpdup ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cpdup.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
