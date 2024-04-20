PORTNAME=	toybox
PORTVERSION=	0.8.11
CATEGORIES=	sysutils
MASTER_SITES=	http://landley.net/toybox/downloads/

MAINTAINER=	vidar@karlsen.tech
COMMENT=	All-in-one command line
WWW=		https://landley.net/toybox/

LICENSE=	0BSD
LICENSE_NAME=	BSD Zero Clause License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	bash:shells/bash gsed:textproc/gsed

USES=		gmake shebangfix

SHEBANG_FILES=	mkroot/record-commands scripts/probes/bloatcheck \
		scripts/mcm-buildall.sh scripts/change.sh \
		scripts/probes/findglobals scripts/genconfig.sh \
		scripts/install.sh scripts/make.sh scripts/mkroot.sh \
		scripts/portability.sh scripts/runtest.sh \
		scripts/single.sh scripts/test.sh configure \
		tests/*

do-configure:
	cd ${WRKSRC} && HOSTCC=${CC} ${GMAKE} bsd_defconfig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/toybox ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/sbin
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/usr/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/usr/sbin
	(cd ${WRKSRC} && PREFIX=${STAGEDIR}${PREFIX}/${PORTNAME} scripts/install.sh --symlink --long)

.include <bsd.port.mk>
