# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kr
PORTVERSION=	2.3.1
PORTREVISION=	4
CATEGORIES=	security

MAINTAINER=	feld@FreeBSD.org
COMMENT=	SSH and Git commit/tag signing using a key stored in Krypton

BROKEN=		fails to build
NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	Uses 64bit types

BUILD_DEPENDS=	${RUST_DEFAULT}>=1.19.0_2:lang/${RUST_DEFAULT} \
		bash>0:shells/bash

USES=		gmake go shebangfix
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
SHEBANG_FILES=	install/os.sh

USE_GITHUB=	yes
GH_ACCOUNT=	kryptco

GH_TUPLE+=	atotto:clipboard:bb272b8:clipboard/../src/github.com/atotto/clipboard
GH_TUPLE+=	kryptco:qr:eb334d7:qr/../src/github.com/kryptco/qr
GH_TUPLE+=	kryptco:gf256:bbd714a:gf256/../src/github.com/kryptco/gf256
GH_TUPLE+=	urfave:cli:b438abf:cli/../src/github.com/urfave/cli

PLIST_FILES=	bin/kr \
		bin/krd \
		bin/krgpg \
		bin/krssh \
		lib/kr-pkcs11.so

post-patch:
	${CP} -r ${WRKSRC}/vendor/ ${WRKDIR}/src/
	# Duplicate copy found in vendor dir breaks the build
	${RM} -r ${WRKSRC}/vendor/github.com/op
	# Hack because the build process is losing PREFIX somewhere
	${REINPLACE_CMD} 's|const DEFAULT_PREFIX = "/usr"|const DEFAULT_PREFIX = "${PREFIX}"|' ${WRKSRC}/kr/kr_unix.go

do-build:
	(cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${GO_ENV} ${GMAKE})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/kr ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/krd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/krssh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/krgpg ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/lib/kr-pkcs11.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
