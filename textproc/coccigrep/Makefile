# Created by: Pawel Pekala <pawel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	coccigrep
PORTVERSION=	1.12
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Semantic grep for the C language

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/bin/spatch:${PORTSDIR}/devel/coccinelle

USE_GITHUB=	yes
GH_ACCOUNT=	regit
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	5ca9276

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

PLIST_FILES=	man/man1/coccigrep.1.gz \
		${DATADIR_REL}/cocci-grep.el \
		${DATADIR_REL}/cocci-grep.vim
PLIST_DIRS=	${DATADIR_REL}
PORTDOCS=	ChangeLog README.rst

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/coccigrep.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/editors/cocci-grep.el ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/editors/cocci-grep.vim ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
