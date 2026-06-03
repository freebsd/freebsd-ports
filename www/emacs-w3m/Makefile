PORTNAME=	emacs-w3m
PORTVERSION=	1.4.632.b.${SNAPDATE}
PORTREVISION=	1
CATEGORIES=	www elisp

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Simple front-end to w3m for emacs
WWW=		http://emacs-w3m.namazu.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	w3m:www/w3m
RUN_DEPENDS=	w3m:www/w3m

USES=		autoreconf emacs:build tar:xz
USE_GITHUB=	yes
GH_TAGNAME=	ec18c21

ALL_TARGET=	info
INSTALL_TARGET=	install install-icons

CONFLICTS_INSTALL=	emacs-w3m-emacs_*

NO_ARCH=	yes
SNAPDATE=	20251229
MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${PREFIX}/${EMACS_SITE_LISPDIR}/w3m \
		--with-icondir=${PREFIX}/${EMACS_LIBDIR}/etc/w3m/icons \
		--without-compress-install

INFO=		emacs-w3m-ja emacs-w3m
PORTDOCS=	README*

OPTIONS_DEFINE=		DOCS OCTET_VIEWER SHIMBUN
OPTIONS_DEFAULT=	OCTET_VIEWER SHIMBUN
OPTIONS_SUB=		yes

OCTET_VIEWER_DESC=	Octet stream viewer support
SHIMBUN_DESC=		Build and/or install Shimbun

SHIMBUN_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-Makefile.in
SHIMBUN_BUILD_DEPENDS=	flim>0:editors/flim
SHIMBUN_RUN_DEPENDS=	flim>0:editors/flim

OCTET_VIEWER_RUN_DEPENDS=\
		semi>0:editors/semi \
		wvHtml:textproc/wv \
		xlhtml:textproc/xlhtml

post-patch:
	@${MV} ${WRKSRC}/aclocal.m4 ${WRKSRC}/acinclude.m4

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/w3m/ \
	-name "*.elc" -delete

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
