PORTNAME=	emacs-libvterm
DISTVERSION=	g20251119
PORTREVISION=	2
CATEGORIES=	misc elisp

MAINTAINER=	tslight@pm.me
COMMENT=	Emacs libvterm integration

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libvterm.so:devel/libvterm

USES=		cmake:noninja emacs

USE_GITHUB=	yes
GH_ACCOUNT=	akermu
GH_TAGNAME=	a01a2894a1c1e81a39527835a9169e35b7ec5dec

CONFLICTS_INSTALL=	emacs-libvterm-emacs_*

SUB_FILES=	pkg-message
SUB_LIST+=	EMACS_SITE_LISPDIR=${EMACS_SITE_LISPDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/vterm/etc
	${INSTALL_DATA} ${WRKSRC}/vterm.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/vterm
	${INSTALL_LIB} ${WRKSRC}/vterm-module.so \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/vterm
	${INSTALL_DATA} ${WRKSRC}/etc/* \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/vterm/etc/

.include <bsd.port.mk>
