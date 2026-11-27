PORTNAME=	toybox
PORTVERSION=	0.8.11
CATEGORIES=	sysutils
MASTER_SITES=	http://landley.net/toybox/downloads/

MAINTAINER=	vidar@karlsen.tech
COMMENT=	All-in-one command line
WWW=		https://landley.net/toybox/

LICENSE=	0BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash gsed:textproc/gsed

USES=		cpe gmake shebangfix

CPE_VENDOR=	toybox_project

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
