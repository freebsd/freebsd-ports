# Created by: Pawel Pekala <pawel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	coccigrep
PORTVERSION=	1.16
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Semantic grep for the C language

LICENSE=	GPLv3

RUN_DEPENDS=	spatch:devel/coccinelle

USE_GITHUB=	yes
GH_ACCOUNT=	regit

USES=		python
USE_PYTHON=	distutils autoplist concurrent optsuffix

PLIST_FILES=	man/man1/coccigrep.1.gz \
		${DATADIR_REL}/cocci-grep.el \
		${DATADIR_REL}/cocci-grep.vim
PORTDOCS=	ChangeLog README.rst

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/coccigrep.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/editors/cocci-grep.el ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/editors/cocci-grep.vim ${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
