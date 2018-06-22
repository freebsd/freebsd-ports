# Created by: luigi@FreeBSD.org
# $FreeBSD$

PORTNAME=	busybox
PORTVERSION=	1.26.2
CATEGORIES=	sysutils misc shells
MASTER_SITES=	https://busybox.net/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of common utilities built as single binary

LICENSE=	GPLv2

BUILD_DEPENDS=	gsed:textproc/gsed

USES=		cpe gmake perl5 tar:bzip2
USE_PERL5=	build

CFLAGS+=	-fno-builtin-mempcpy	# avoid -Wshadow warnings
CONFLICTS_INSTALL=	busybox-unstable-*
MAKE_ARGS=	CC="${CC}" HOSTCC="${CC}" CXX="${CXX}" HOSTCXX="${CXX}" \
		SKIP_STRIP=y V=1
PLIST_FILES=	bin/busybox man/man1/busybox.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS STATIC

STATIC_LDFLAGS=	-static

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
