PORTNAME=	wanderlust
PORTVERSION=	2.15.9.b.${SNAPDATE}
PORTREVISION=	1
CATEGORIES=	mail elisp

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Mail and news system for Emacs
WWW=		https://github.com/wanderlust/wanderlust

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	emacs-w3m>0:www/emacs-w3m \
		semi>0:editors/semi \
		x-face-e21>0:mail/x-face-e21
RUN_DEPENDS=	emacs-w3m>0:www/emacs-w3m \
		semi>0:editors/semi

USES=		emacs:build
USE_GITHUB=	yes
GH_TAGNAME=	06ec9fa

CONFLICTS_INSTALL=	wanderlust-emacs_*

NO_ARCH=	yes
SNAPDATE=	20251029

MAKE_ARGS+=	EMACS=${EMACS_CMD} \
		FLAGS="-batch -q -no-site-file" \
		LISPDIR=${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR} \
		INFODIR=${STAGEDIR}${PREFIX}/${INFO_PATH} \
		PACKAGE_LISPDIR=NONE \
		PIXMAPDIR=${STAGEDIR}${PREFIX}/${EMACS_LIBDIR}/etc/wl/icons

INFO=		wl wl-ja
PORTDATA=	ja.Emacs
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract:
	@${CP} ${FILESDIR}/WL-CFG ${WRKSRC}

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/wl \
	-name "*.elc" -delete

	${INSTALL} -d ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/wl \
		${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/wanderlust-startup.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} \
		${WRKSRC}/elmo/elmo-shimbun.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/wl
	${INSTALL_DATA} ${WRKSRC}/etc/ja.Emacs ${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	${INSTALL} -d ${STAGEDIR}/${DOCSDIR}
.for f in README* NEWS* doc/wl*.texi
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-EXAMPLES-on:
	${INSTALL} -d ${STAGEDIR}/${EXAMPLESDIR}
	(cd ${WRKSRC}/samples && ${COPYTREE_SHARE} "en ja" \
		${STAGEDIR}${EXAMPLESDIR})
	${RM} ${STAGEDIR}${EXAMPLESDIR}/en/*.orig \
		${STAGEDIR}${EXAMPLESDIR}/ja/*.orig

.include <bsd.port.mk>
