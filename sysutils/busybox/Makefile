# Created by: luigi@FreeBSD.org
# $FreeBSD$

PORTNAME=	busybox
PORTVERSION=	1.24.2
CATEGORIES=	sysutils misc shells
MASTER_SITES=	https://busybox.net/downloads/

PATCH_SITES=	https://busybox.net/downloads/fixes-${PORTVERSION}/
PATCHFILES=	${PORTNAME}-${PORTVERSION}-CVE-2016-2147.patch \
		${PORTNAME}-${PORTVERSION}-CVE-2016-2148.patch \
		${PORTNAME}-${PORTVERSION}-ash-recursive-heredocs.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of common utilities built as single binary

LICENSE=	GPLv2

BUILD_DEPENDS=	gsed:textproc/gsed

CONFLICTS_INSTALL=	busybox-unstable-*

PORTSCOUT=	skipv:1.25.0

CFLAGS+=	-fno-builtin-mempcpy	# avoid -Wshadow warnings
MAKE_ARGS=	CC="${CC}" HOSTCC="${CC}" CXX="${CXX}" HOSTCXX="${CXX}" \
		SKIP_STRIP=y V=1
USES=		cpe gmake perl5 tar:bzip2
USE_PERL5=	build

PLIST_FILES=	bin/busybox man/man1/busybox.1.gz

OPTIONS_DEFINE=	DOCS STATIC

STATIC_LDFLAGS=	-static

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e \
		's|\([[:<:]]\)sed\([[:blank:]]-n\)|\1gsed\2|' \
		${WRKSRC}/scripts/gen_build_files.sh
	@${FIND} ${WRKSRC} -name "*.c" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		's|<alloca.h>|<stdlib.h>| ; \
		 s|<malloc.h>|<stdlib.h>|'

do-configure:
	@${CP} ${FILESDIR}/data-.config ${WRKSRC}/.config
	@(cd ${WRKSRC} && ${DO_MAKE_BUILD} oldconfig)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} busybox \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/docs && ${INSTALL_MAN} busybox.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)

post-install-DOCS-on:
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR} "! -name busybox.1")

.include <bsd.port.mk>
