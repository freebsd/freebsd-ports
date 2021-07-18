# Created by: MANTANI Nobutaka <nobutaka@nobutaka.com>

PORTNAME=	emacs-w3m
PORTVERSION=	1.4.632.b.${SNAPDATE}
CATEGORIES=	www elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Simple front-end to w3m for emacs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	w3m:www/w3m
RUN_DEPENDS=	w3m:www/w3m

USES=		autoreconf emacs tar:xz
USE_GITHUB=	yes
GH_TAGNAME=	8bab3dc

ALL_TARGET=	default
INSTALL_TARGET=	install install-icons

NO_ARCH=	yes
SNAPDATE=	20210409
MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/w3m \
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
SHIMBUN_BUILD_DEPENDS=	flim${EMACS_PKGNAMESUFFIX}>0:editors/flim@${EMACS_FLAVOR}
SHIMBUN_RUN_DEPENDS=	flim${EMACS_PKGNAMESUFFIX}>0:editors/flim@${EMACS_FLAVOR}

OCTET_VIEWER_RUN_DEPENDS=\
		semi${EMACS_PKGNAMESUFFIX}>0:editors/semi@${EMACS_FLAVOR} \
		wvHtml:textproc/wv \
		xlhtml:textproc/xlhtml

post-patch:
	@${MV} ${WRKSRC}/aclocal.m4 ${WRKSRC}/acinclude.m4

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
