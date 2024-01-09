PORTNAME=	pdumpfs
PORTVERSION=	1.3
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	http://0xcc.net/pdumpfs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Daily backup system similar to Plan9's dumpfs
WWW=		http://0xcc.net/pdumpfs/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ruby shebangfix
NO_ARCH=	yes

SHEBANG_FILES=	${WRKSRC}/pdumpfs.in
ALL_TARGET=	pdumpfs

PLIST_FILES=	share/man/ja/man8/pdumpfs.8.gz \
		share/man/man8/pdumpfs.8.gz \
		sbin/pdumpfs
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pdumpfs ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/man8/pdumpfs.8 ${STAGEDIR}${PREFIX}/share/man/man8
	${RUBY} -ni -r nkf -e 'puts NKF.nkf("-e",$$_)' ${WRKSRC}/man/ja/man8/pdumpfs.8
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/ja/man8
	${INSTALL_MAN} ${WRKSRC}/man/ja/man8/pdumpfs.8 ${STAGEDIR}${PREFIX}/share/man/ja/man8

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
