PORTNAME=	hfsfuse
DISTVERSION=	0.126
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/0x09/hfsfuse/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	me@cameronkatri.com
COMMENT=	FUSE driver for HFS+ filesystems

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/src/COPYING

LIB_DEPENDS=	libublio.so:devel/libublio \
		libutf8proc.so:textproc/utf8proc

USES=		fuse gmake
USE_CSTD=	c99
USE_GITHUB=	yes
GH_ACCOUNT=	0x09

ALL_TARGET=	config all
MAKE_ARGS=	CONFIG_CFLAGS="${CFLAGS}" WITH_UBLIO=system WITH_UTF8PROC=system

PLIST_FILES=	bin/hfsdump bin/hfsfuse
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} hfsdump hfsfuse \
		${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
