# Created by: Dmitri Goutnik <dg@syrec.org>
# $FreeBSD$

PORTNAME=	gdrive
DISTVERSION=	2.1.0-23
DISTVERSIONSUFFIX=	-gc3cbcce
CATEGORIES=	net

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
# https://github.com/prasmussen/gdrive/pull/428
PATCHFILES=	3c060f4d33530866496515b45fcfaa3fd2da5f32.patch:-p1 \
		4916e16a91b84702ebe67ca7be4295b26d4cb0b5.patch:-p1 \
		0197c982f6c961e8a44ec9895fcc33c1fe4c3ac2.patch:-p1 \
		f397bb25e339dc4cf1e9bf2467336ba6fd48fd9f.patch:-p1

MAINTAINER=	dg@syrec.org
COMMENT=	Google Drive CLI Client

LICENSE=	MIT

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	prasmussen

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/gdrive
PORTDOCS=	README.md

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
