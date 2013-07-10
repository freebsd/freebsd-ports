# Created by: Pawel Pekala <pawel@freebsd.org>
# $FreeBSD$

PORTNAME=	coccigrep
PORTVERSION=	1.12
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
USE_PYDISTUTILS=easy_install
MANCOMPRESSED=	no

MAN1=		coccigrep.1
PORTDOCS=	ChangeLog README.rst

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
	${INSTALL_MAN} ${WRKSRC}/coccigrep.1 ${MANPREFIX}/man/man1
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/editors/cocci-grep.el ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/editors/cocci-grep.vim ${DATADIR}

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${DOCSDIR}
.endif

.include <bsd.port.mk>
