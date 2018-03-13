# $FreeBSD$

PORTNAME=	hfsfuse
DISTVERSION=	g20180118
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	FUSE driver for HFS+ filesystems

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/src/COPYING

LIB_DEPENDS=	libublio.so:devel/libublio \
		libutf8proc.so:textproc/utf8proc

USES=		fuse gmake
USE_GITHUB=	yes
GH_ACCOUNT=	0x09
GH_TAGNAME=	d021835629c3fb37bd5bf8d364d5196f1db53867

MAKE_ARGS=	WITH_UBLIO=system WITH_UTF8PROC=system

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
