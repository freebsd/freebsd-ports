PORTNAME=	muse
PORTVERSION=	3.20
PORTREVISION=	31
CATEGORIES=	textproc elisp
MASTER_SITES=	LOCAL/dryice
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Authoring and publishing environment for Emacs
WWW=		https://www.emacswiki.org/cgi-bin/wiki/MuseMode

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		emacs gmake

NO_ARCH=	yes

PORTDOCS=	AUTHORS ChangeLog ChangeLog.1 ChangeLog.2 ChangeLog.3 NEWS \
		README scripts COPYING

OPTIONS_DEFINE=	DOCS INFO
OPTIONS_DEFAULT=	INFO

INFO_USES=		makeinfo
INFO_INFO=		muse

LISPDIR=	${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}

.if ${FLAVOR:Ufull:Mfull}
PKGNAMESUFFIX=	-emacs
.endif

post-patch-INFO-off:
	${REINPLACE_CMD} -e '/^SUBDIRS/s|texi||g; \
		/^install:/s|install-info||g; /^all:/s|info-only||g' \
		${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${LISPDIR}/contrib
	(cd ${WRKSRC} && ${COPYTREE_SHARE} contrib  ${STAGEDIR}${LISPDIR})
	${INSTALL_DATA} ${WRKSRC}/experimental/* \
		${STAGEDIR}${LISPDIR}/experimental
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|scripts||:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} scripts ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
