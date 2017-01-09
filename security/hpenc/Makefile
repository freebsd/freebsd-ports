# $FreeBSD$

PORTNAME=	hpenc
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://highsecure.ru/distfiles/

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Fast authenticated encryption CLI tool

LICENSE=	BSD2CLAUSE

BROKEN_powerpc64=	Does not build

NOT_FOR_ARCHS=		aarch64 sparc64
NOT_FOR_ARCHS_REASON=	not yet ported to this architecture

USES=		tar:xz compiler:c++11-lib gmake
USE_OPENSSL=	yes
PLIST_FILES=	bin/hpenc man/man1/hpenc.1.gz

MAKE_ARGS+=	"ARCH=${ARCH:S/amd64/x86/:S/i386/x86/}"
CXXFLAGS+=	-std=c++11 \
		-I${WRKSRC}/chacha-opt/app/include \
		-I${WRKSRC}/poly1305-opt/app/include \
		-I${OPENSSLINC}
LDFLAGS+=	-pthread -lcrypto -L${OPENSSLLIB}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/hpenc.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/hpenc

.include <bsd.port.mk>
