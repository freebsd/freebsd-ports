# $FreeBSD$

PORTNAME=	toybox
PORTVERSION=	0.8.2
CATEGORIES=	sysutils

MAINTAINER=	vidar@karlsen.tech
COMMENT=	All-in-one command line

LICENSE=	0BSD
LICENSE_NAME=	BSD Zero Clause License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	bash:shells/bash gsed:textproc/gsed
LIB_DEPENDS=	libinotify.so:devel/libinotify

USES=		gmake shebangfix

SHEBANG_FILES=	scripts/change.sh scripts/findglobals.sh \
		scripts/genconfig.sh scripts/install.sh \
		scripts/make.sh scripts/minicom.sh \
		scripts/portability.sh scripts/runtest.sh \
		scripts/single.sh scripts/test.sh configure

PLIST_FILES=	bin/toybox

USE_GITHUB=	yes
GH_ACCOUNT=	landley

post-patch:
	@${REINPLACE_CMD} -e 's|<sys/inotify.h>|"${LOCALBASE}/include/sys/inotify.h"|' \
		${WRKSRC}/lib/portability.c

do-configure:
	cd ${WRKSRC} && ${GMAKE} bsd_defconfig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/toybox ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
