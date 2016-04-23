# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	pdumpfs
PORTVERSION=	1.3
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://0xcc.net/pdumpfs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Daily backup system similar to Plan9's dumpfs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_RUBY=	yes
USES=		shebangfix
NO_ARCH=	yes

SHEBANG_FILES=	${WRKSRC}/pdumpfs.in
ALL_TARGET=	pdumpfs

PLIST_FILES=	man/ja/man8/pdumpfs.8.gz \
		man/man8/pdumpfs.8.gz \
		sbin/pdumpfs
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pdumpfs ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/man8/pdumpfs.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${RUBY} -ni -r nkf -e 'puts NKF.nkf("-e",$$_)' ${WRKSRC}/man/ja/man8/pdumpfs.8
	${INSTALL_MAN} ${WRKSRC}/man/ja/man8/pdumpfs.8 ${STAGEDIR}${MANPREFIX}/man/ja/man8

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
