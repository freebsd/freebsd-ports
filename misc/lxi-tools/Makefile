# $FreeBSD$

PORTNAME=	lxi-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	1.16
CATEGORIES=	misc

MAINTAINER=	dg@syrec.org
COMMENT=	Collection of tools that enables control of LXI compatible instruments

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblxi.so:misc/liblxi

USES=		autoreconf localbase readline
USE_GITHUB=	yes
GH_ACCOUNT=	lxi-tools

GNU_CONFIGURE=	yes
CFLAGS+=	-D_WITH_GETLINE # enable getline(3) prototype

PORTDOCS=	README

PLIST_FILES=	bin/lxi \
		man/man1/lxi.1.gz

OPTIONS_DEFINE=	BASH DOCS

BASH_CONFIGURE_WITH=	bash-completion-dir=${PREFIX}/etc/bash_completion.d
BASH_PLIST_FILES=	${PREFIX}/etc/bash_completion.d/lxi

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
