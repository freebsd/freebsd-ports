# Created by: Dryice Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	muse
PORTVERSION=	3.20
PORTREVISION=	15
CATEGORIES=	textproc elisp
MASTER_SITES=	http://download.gna.org/muse-el/ \
		LOCAL/dryice \
		http://dryice.name/computer/FreeBSD/distfiles/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Authoring and publishing environment for Emacs

USES=		emacs gmake makeinfo

INFO=		muse

LISPDIR=	${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}

PORTDOCS=	AUTHORS ChangeLog ChangeLog.1 ChangeLog.2 ChangeLog.3 NEWS \
		README scripts COPYING

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${LISPDIR}/contrib
	(cd ${WRKSRC} && ${COPYTREE_SHARE} contrib  ${STAGEDIR}${LISPDIR})
	${INSTALL_DATA} ${WRKSRC}/experimental/* \
		${STAGEDIR}${LISPDIR}/experimental
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|scripts||:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} scripts ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
